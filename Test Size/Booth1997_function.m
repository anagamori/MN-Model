%==========================================================================
% Booth1997_function.m
% Author: Akira Nagamori
% Last update: 8/14/19
% Descriptions:
%==========================================================================

function [binary,V_s,V_d] = Booth1997_function(param_s,param_d,time,input,Fs,noise_amp,inputOpt,pltOpt)

step = 1/Fs;

%%
theta_m = -35; %(mV)
theta_h = -55; %(mV)
theta_n = -28; %(mV)
theta_m_N = -30; %(mV)
theta_h_N = -45; %(mV)
theta_m_L = -40; %(mV)

k_m = -7.8; %(mV)
k_h = 7; %(mV)
k_n = -15; %(mV)
k_m_N = -5; %(mV)
k_h_N = 5; %(mV)
k_m_L = -7; %(mV)

tau_m_N = 0.004; %(s)
tau_h_N = 0.04; %(s)
tau_m_L = 0.04; %(s)

%%
V_Ca = 80; %(mV)

g_Ca_N_s = 14; %(mS/cm^2)
g_Ca_N_d = 0.3; %(mS/cm^2)
g_Ca_L = 0.33; %(mS/cm^2)


%%

V_s = -66;
V_d = -66;
m_inf = 1/(1+exp((V_s-theta_m)/k_m));

h = 0.8067;
n = 0.0782;
m_N_s = 0; %0.004;
h_N_s = 0.9294;
m_N_d = 0.0046;
h_N_d = 0.9146;
m_L = 0.083;
Ca_s = 0.001;
Ca_d = 0.17;


%%
V_s_vec =  zeros(1,length(time));
V_d_vec =  zeros(1,length(time));
m_inf_vec =  zeros(1,length(time));
h_vec =  zeros(1,length(time));
n_vec =  zeros(1,length(time));
m_N_s_vec =  zeros(1,length(time));
h_N_s_vec =  zeros(1,length(time));
m_N_d_vec =  zeros(1,length(time));
h_N_d_vec =  zeros(1,length(time));
m_L_vec = zeros(1,length(time));

Ca_s_vec =  zeros(1,length(time));
Ca_d_vec =  zeros(1,length(time));

binary = zeros(1,length(time));

x_noise = 0;
chi = normrnd(0,1,[1,length(time)]);
x_noise_vec = zeros(1,length(time));

I_app_vec = zeros(1,length(time));

%%
for t = 1:length(time)
    [x_noise] = noise(x_noise,noise_amp,chi(t),Fs);
    I_app = input(t) + input(t)*x_noise; % + input(t)*sum(x_noise);
    V_s_1 = V_s;
    m_inf = 1/(1+exp((V_s-theta_m)/k_m));
    %%
    k_1_s = f_dV_s(param_s,V_s,V_d,h,n,m_N_s,h_N_s,Ca_s,I_app,inputOpt);
    y_1_s = V_s + k_1_s*step/2;
    k_2_s = f_dV_s(param_s,y_1_s,V_d,h,n,m_N_s,h_N_s,Ca_s,I_app,inputOpt);
    y_2_s = V_s + k_2_s*step/2;
    k_3_s = f_dV_s(param_s,y_2_s,V_d,h,n,m_N_s,h_N_s,Ca_s,I_app,inputOpt);
    y_3_s = V_s + k_3_s*step/2;
    k_4_s = f_dV_s(param_s,y_3_s,V_d,h,n,m_N_s,h_N_s,Ca_s,I_app,inputOpt);
    V_s = V_s + step/6*(k_1_s+2*k_2_s+2*k_3_s+k_4_s);
    
    %%
    k_1_d = f_dV_d(param_d,V_d,V_s,m_N_d,h_N_d,m_L,Ca_d,I_app,inputOpt);
    y_1_d = V_d + k_1_d*step/2;
    k_2_d = f_dV_d(param_d,y_1_d,V_s,m_N_d,h_N_d,m_L,Ca_d,I_app,inputOpt);
    y_2_d = V_d + k_2_d*step/2;
    k_3_d = f_dV_d(param_d,y_2_d,V_s,m_N_d,h_N_d,m_L,Ca_d,I_app,inputOpt);
    y_3_d = V_d + k_3_d*step/2;
    k_4_d = f_dV_d(param_d,y_3_d,V_s,m_N_d,h_N_d,m_L,Ca_d,I_app,inputOpt);
    V_d = V_d + step/6*(k_1_d+2*k_2_d+2*k_3_d+k_4_d);
    %% State variables for ionic conductances
    
    tau_h = time_constant_h(V_s);
    h = conductance_kinetics(h,V_s,tau_h,theta_h,k_h,Fs);
    tau_n = time_constant_n(V_s);
    n = conductance_kinetics(n,V_s,tau_n,theta_n,k_n,Fs);
    m_N_s = conductance_kinetics(m_N_s,V_s,tau_m_N,theta_m_N,k_m_N,Fs);
    h_N_s = conductance_kinetics(h_N_s,V_s,tau_h_N,theta_h_N,k_h_N,Fs);
    
    I_Ca_s = g_Ca_N_s*m_N_s^2*h_N_s*(V_s-V_Ca);
    Ca_s = calcium_concentration(Ca_s,I_Ca_s,Fs);
    
    
    %%
    m_N_d = conductance_kinetics(m_N_d,V_d,tau_m_N,theta_m_N,k_m_N,Fs);
    h_N_d = conductance_kinetics(h_N_d,V_d,tau_h_N,theta_h_N,k_h_N,Fs);
    m_L = conductance_kinetics(m_L,V_d,tau_m_L,theta_m_L,k_m_L,Fs);
    
    I_Ca_d = g_Ca_N_d*m_N_d^2*h_N_d*(V_d-V_Ca) + g_Ca_L*m_L*(V_d-V_Ca);
    Ca_d = calcium_concentration(Ca_d,I_Ca_d,Fs);
    
    V_s_vec(t) = V_s;
    V_d_vec(t) = V_d;
    
    m_inf_vec(t) =  m_inf;
    h_vec(t) =  h;
    n_vec(t) =  n;
    m_N_s_vec(t) =  m_N_s;
    h_N_s_vec(t) =  h_N_s;
    m_N_d_vec(t) =  m_N_d;
    h_N_d_vec(t) =  h_N_d;
    m_L_vec(t) = m_L;
    Ca_s_vec(t) = Ca_s;
    Ca_d_vec(t) = Ca_d;
    
    x_noise_vec(t) = x_noise;
    
    I_app_vec(t) = I_app;
    if V_s > 0 && V_s_1 < 0
        binary(t) = 1;
    end
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
    linkaxes([ax1,ax2,ax3],'x')
    
    figure(2)
    plot(time,m_inf_vec)
    hold on
    plot(time,h_vec)
    plot(time,n_vec)
    legend('m','h','n')
end
%%
    function tau_h = time_constant_h(V)
        tau_h = 30/(exp((V+50)/15) + exp(-(V+50)/16));
        tau_h = tau_h/1000;
    end

    function tau_n = time_constant_n(V)
        tau_n = 7/(exp((V+40)/40) + exp(-(V+40)/50));
        tau_n = tau_n/1000;
    end

    function w = conductance_kinetics(w,V,tau_w,theta_w,k_w,Fs)        
        w_inf = 1/(1+exp((V-theta_w)/k_w));
        dw = (w_inf - w)/tau_w;
        w = dw*1/Fs + w;
        
    end

    function Ca = calcium_concentration(Ca,I_Ca,Fs)
        f = 0.01; % percent of free to bound Ca2+
        alpha = 0.009*1000; %(mol/C/microm)
        k_Ca = 2*1000; %(s)
        
        dCa = f*(-alpha*I_Ca - k_Ca*Ca);
        Ca = dCa*1/Fs + Ca;
        
    end

    function dx = f_dV_s(param_s,V_s,V_d,h,n,m_N,h_N,Ca,I_app,inputOpt)        
        %%
        m_inf_f = 1/(1+exp((V_s-param_s.theta_m_f)/param_s.k_m_f));
        
        %%
        I_Na = param_s.g_Na_f*m_inf_f^3*h*(V_s-param_s.V_Na_f); % sodium conductance
        I_K_dr = param_s.g_K_dr_f*n^4*(V_s-param_s.V_K_f); %  potassium delayed rectifier
        
        I_Ca_N = param_s.g_Ca_N_f*m_N^2*h_N*(V_s-param_s.V_Ca_f); % inactivating, high-threshold, N-like calcium conductance
        I_K_Ca = param_s.g_K_Ca_f*(Ca/(Ca+param_s.K_d_f))*(V_s-param_s.V_K_f); % calcium-dependent potassium conductance
        I_L = param_s.g_L_f*(V_s-param_s.V_L_f); % leak conductance
        I_c = param_s.g_c_f/param_s.p_f*(V_d-V_s);
        %%
        if inputOpt == 1
            dx = 1/param_s.C_m_f*(-I_Na - I_K_dr - I_Ca_N ...
                - I_L - I_K_Ca + I_c + I_app)*1000; %
        else
            dx = 1/param_s.C_m_f*(-I_Na - I_K_dr - I_Ca_N ...
                - I_L - I_K_Ca + I_c)*1000; %
        end
        
    end

    function dx = f_dV_d(param_d,V_d,V_s,m_N,h_N,m_L,Ca,I_app,inputOpt)
        %%
        I_Ca_N = param_d.g_Ca_N_f*m_N^2*h_N*(V_d-param_d.V_Ca_f); % inactivating, high-threshold, N-like calcium conductance
        I_K_Ca = param_d.g_K_Ca_f*(Ca/(Ca+param_d.K_d_f))*(V_d-param_d.V_K_f); % calcium-dependent potassium conductance
        I_Ca_L = param_d.g_Ca_L_f*m_L*(V_d-param_d.V_Ca_f); % persistent, low-threshold, L-like calicum conductance
        I_L = param_d.g_L_f*(V_d-param_d.V_L_f);
        I_c = param_d.g_c_f/(1-param_d.p_f)*(V_s-V_d);
        
        %%
        if inputOpt == 1
            dx = 1/param_d.C_m_f*(-I_Ca_N - I_Ca_L - I_K_Ca...
                - I_L + I_c)*1000;
        else
            dx = 1/param_d.C_m_f*(-I_Ca_N - I_Ca_L - I_K_Ca...
                - I_L + I_c + I_app)*1000;
        end
        
    end
    function [x] = noise(x,D,chi,Fs)
        tau = 0.005; 
        x_dot = -x/tau + sqrt(D)*chi;
        x = x_dot*1/Fs + x;
    end
end