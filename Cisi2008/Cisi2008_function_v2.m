%==========================================================================
% Cisi2008_function.m
% Author: Akira Nagamori
% Last update: 8/31/19
% Descriptions:
%==========================================================================

function [binary,V_s_vec,V_d_vec] = Cisi2008_function_v2(param,time,input,Fs,noise_amp,inputOpt,pltOpt)

step = 1/Fs;

%% Geometric parameters
param_s.area_s = param.area_s; % the surface area of soma
param_d.area_d = param_s.area_s*param.q; % the surface area of dendrite

p = 1/(1+param.q); % the ratio of somatic surface area to total cell surface area
%% Dendtritic parameters
param_d.V_l = param.V_l; %(mV)

param_d.g_c = param.g_c*param_d.area_d; %2/((param.R_i*param.l_d/(pi*param.r_d^2))+(param.R_i*param.l_s/(pi*param.r_s^2)));
param_d.g_l = param_d.area_d/param.R_m_d;
param_d.C_m = param.C_m*param_d.area_d;
param_d.p = p; % the ratio of somatic surface area to total cell surface area
%% Somatic parameters
param_s.V_Na = param.V_Na; %(mV)
param_s.V_K = param.V_K; %(mV)
param_s.V_l = param.V_l; %(mV)

param_s.g_Na = param.g_Na*param_s.area_s ; %(mS)
param_s.g_Kf = param.g_Kf*param_s.area_s ; %(mS)
param_s.g_Ks = param.g_Ks*param_s.area_s ; %(mS)
param_s.g_c = param.g_c*param_s.area_s;
param_s.g_l = param_s.area_s/param.R_m_s;
param_s.p = p;
param_s.C_m = param.C_m*param_s.area_s;

param_s.V_th = (param.R_m_s*10^3)/param_s.area_s*param.I_r;
param_s.V_th = param_s.V_th*10^3;

%%
V_s = 0;
V_d = 0;

m = 0;
h = 1;
n = 0;
q = 0;

m_0 = 0;
h_0 = 1;
n_0 = 0;
q_0 = 0;
%%
chi = normrnd(0,1,[1,length(time)]);
%%
V_s_vec =  zeros(1,length(time));
V_d_vec =  zeros(1,length(time));
m_vec =  zeros(1,length(time));
h_vec =  zeros(1,length(time));
n_vec =  zeros(1,length(time));
q_vec =  zeros(1,length(time));

binary = zeros(1,length(time));

x_noise = 0;
x_noise_vec = zeros(1,length(time));

I_app_vec = zeros(1,length(time));

index_s = zeros(1,length(time));
t_0_end = 0;
%%
for t = 1:length(time)
    [x_noise] = noise(x_noise,noise_amp,chi(t),Fs);
    I_app = input(t) + input(t)*x_noise; % + input(t)*sum(x_noise);
    V_s_m1 = V_s;
    %%
    k_1_s = f_dV_s(V_s,V_d,m,h,n,q,param_s,I_app,inputOpt);
    y_1_s = V_s + k_1_s*step/2;
    k_2_s = f_dV_s(y_1_s,V_d,m,h,n,q,param_s,I_app,inputOpt);
    y_2_s = V_s + k_2_s*step/2;
    k_3_s = f_dV_s(y_2_s,V_d,m,h,n,q,param_s,I_app,inputOpt);
    y_3_s = V_s + k_3_s*step/2;
    k_4_s = f_dV_s(y_3_s,V_d,m,h,n,q,param_s,I_app,inputOpt);
    V_s = V_s + step/6*(k_1_s+2*k_2_s+2*k_3_s+k_4_s);
    
    %%
    k_1_d = f_dV_d(V_d,V_s,param_d,I_app,inputOpt);
    y_1_d = V_d + k_1_d*step/2;
    k_2_d = f_dV_d(y_1_d,V_s,param_d,I_app,inputOpt);
    y_2_d = V_d + k_2_d*step/2;
    k_3_d = f_dV_d(y_2_d,V_s,param_d,I_app,inputOpt);
    y_3_d = V_d + k_3_d*step/2;
    k_4_d = f_dV_d(y_3_d,V_s,param_d,I_app,inputOpt);
    V_d = V_d + step/6*(k_1_d+2*k_2_d+2*k_3_d+k_4_d);
    
    %% Spike detection
    if V_s_m1 < param_s.V_th  && V_s >= param_s.V_th
        binary(t) = 1;
        index_s(t:t+round(0.0006*Fs)) = 1; %pulse duration of 6
    end
    %% State variables for ionic conductances
    if t > 1
        if index_s(t) == 1 && index_s(t-1) == 0
            t_0_start = t/Fs;
            t_0_end = (t+round(0.0006*Fs))/Fs;
            m_0 = m;
            h_0 = h;
            n_0 = n;
            q_0 = q;
        elseif index_s(t) == 0 && index_s(t-1) == 1
            m_0 = m;
            h_0 = h;
            n_0 = n;
            q_0 = q;
        end
        if index_s(t) == 1        
            T = t/Fs;
            m = 1 + (m_0-1)*exp(-param.alpha_m*(T-t_0_start));
            h = h_0*exp(-param.beta_h*(T-t_0_start));
            n = 1 + (n_0-1)*exp(-param.alpha_n*(T-t_0_start));
            q = 1 + (q_0-1)*exp(-param.alpha_q*(T-t_0_start));
        else
            T = t/Fs;
            m = m_0*exp(-param.beta_m*(T-t_0_end));
            h = 1 + (h_0-1)*exp(-param.alpha_h*(T-t_0_end));
            n = n_0*exp(-param.beta_n*(T-t_0_end));
            q = q_0*exp(-param.beta_q*(T-t_0_end));
        end
    end
    V_s_vec(t) = V_s;
    V_d_vec(t) = V_d;
    m_vec(t) =  m;
    h_vec(t) =  h;
    n_vec(t) =  n;
    q_vec(t) =  q;
    
    x_noise_vec(t) = x_noise;
    
    I_app_vec(t) = I_app;
    
end

%%
if pltOpt == 1
    figure(1)
    ax1 = subplot(3,1,1);
    plot(time,I_app_vec,'LineWidth',1,'Color','k')
    xlabel('Time (s)')
    ylabel({'Applied current';'(\muA/cm^2)'})
    set(gca,'TickDir','out');
    set(gca,'box','off')
    ax = gca;
    ax2 = subplot(3,1,2);
    plot(time,V_s_vec,'LineWidth',1,'Color','k')
    hold on
    plot(time,binary*50,'LineWidth',1,'Color','b')
    xlabel('Time (s)')
    ylabel({'Soma potential';'(mV)'})
    set(gca,'TickDir','out');
    set(gca,'box','off')
    ax = gca;
    ax3 = subplot(3,1,3);
    plot(time,V_d_vec,'LineWidth',1,'Color','k')
    xlabel('Time (s)')
    ylabel({'Dendritic potential';'(mV)'})
    set(gca,'TickDir','out');
    set(gca,'box','off')
    ax = gca; 
    
%     figure(2)
%     ax1 = subplot(4,1,1);
%     plot(time,m_vec)
%     legend('m')
%     set(gca,'TickDir','out');
%     set(gca,'box','off')
%     ax2 = subplot(4,1,2);
%     plot(time,h_vec)
%     legend('h')
%     set(gca,'TickDir','out');
%     set(gca,'box','off')
%     ax3 = subplot(4,1,3);
%     plot(time,n_vec)
%     legend('n')
%     set(gca,'TickDir','out');
%     set(gca,'box','off')
%     ax4 = subplot(4,1,4);
%     plot(time,q_vec)
%     legend('q')
%     xlabel('Time (s)')
%     set(gca,'TickDir','out');
%     set(gca,'box','off')
%     ax = gca;
%     linkaxes([ax1,ax2,ax3,ax4],'x')
end

    function dx = f_dV_s(V_s,V_d,m,h,n,q,param_s,I_app,inputOpt)
        %%
        I_Na = param_s.g_Na*m^3*h*(V_s-param_s.V_Na); % sodium conductance
        I_Kf = param_s.g_Kf*n^4*(V_s-param_s.V_K); %  potassium delayed rectifier
        I_Ks = param_s.g_Ks*q^2*(V_s-param_s.V_K); %  potassium delayed rectifier
        
        I_l = param_s. g_l*(V_s-param_s.V_l); % leak conductance
        I_c = param_s.g_c/param_s.p*(V_s-V_d);
        %%
        if inputOpt == 1
            dx = 1/param_s.C_m*(-I_Na - I_Kf - I_Ks ...
                - I_l - I_c + param_s.area_s*I_app)*1000; %- I_c
        else
            dx = 1/param_s.C_m*(-I_Na - I_Kf - I_Ks...
                - I_l - I_c)*1000; %
        end
    end

    function dx = f_dV_d(V_d,V_s,param_d,I_app,inputOpt)
        
        %%
        I_l = param_d.g_l*(V_d-param_d.V_l);
        I_c = param_d.g_c/(1-param_d.p)*(V_d-V_s);
        
        %%
        if inputOpt == 1
            dx = 1/param_d.C_m*(- I_l - I_c)*1000; % - I_c
        else
            dx = 1/param_d.C_m*(- I_l - I_c + param_d.area_d*I_app)*1000; %- I_c
        end
        
    end

    function [x] = noise(x,D,chi,Fs)
        tau = 0.005;
        x_dot = -x/tau + sqrt(D)*chi;
        x = x_dot*1/Fs + x;
    end
end