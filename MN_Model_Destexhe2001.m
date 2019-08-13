%==========================================================================
% MN_Model_Destexhe2001.m
% Author: Akira Nagamori
% Last update: 8/5/19
% Descriptions:
%==========================================================================

%%
close all
clear all
clc

%%
Fs = 50000;
time = 0:1/Fs:2;


%% initilization
V = -65;

m = 0;
h = 1;
n = 0;
q = 0;

%% vactors to save
V_vec = zeros(1,length(time));

m_vec = zeros(1,length(time));
h_vec = zeros(1,length(time));
n_vec = zeros(1,length(time));
q_vec = zeros(1,length(time));

%% input 
I_inj_s = zeros(1,length(time)); %(mincroA)
I_inj_d = zeros(1,length(time));
I_syn_s = zeros(1,length(time));
I_syn_d = zeros(1,length(time));

%% 
I_inj_s(0.5*Fs:end) = 0;
%% simulation
for t = 1:length(time)   
%     if t >= 0.5*Fs
%         V = 100;
%     else
%         V = 0;
%     end
    V = f_V(V,m,h,n,q,I_inj_s(t),Fs);
        
    m = f_m(m,V,Fs);
    h = f_h(h,V,Fs);
    n = f_n(n,V,Fs);
    q = f_q(q,V,Fs);
    
    V_vec(t) = V;
 
    m_vec(t) = m;
    h_vec(t) = h;
    n_vec(t) = n;
    q_vec(t) = q;
end

figure(1)
subplot(2,1,1)
plot(time,I_inj_s)
subplot(2,1,2)
plot(time,V_vec)

figure(2)
plot(time,m_vec)
hold on 
plot(time,h_vec)
plot(time,n_vec)
plot(time,q_vec)
legend('m','h','n','q')


function x = f_m(x,V,Fs)
    step = 1/Fs;
    V_T = -58;
    alpha = -0.32*(V-V_T-13)/(exp(-(V-V_T-13)/4)-1)*1000;
    beta = 0.28*(V-V_T-40)/(exp((V-V_T-40)/5)-1)*1000;
    
    k_1 = f_dx(x,alpha,beta);
    y_1 = x + k_1*step/2;
    k_2 = f_dx(y_1,alpha,beta);
    y_2 = x + k_2*step/2;
    k_3 = f_dx(y_2,alpha,beta);
    y_3 = x + k_3*step/2;
    k_4 = f_dx(y_3,alpha,beta);
    x = x + step/6*(k_1+2*k_2+2*k_3+k_4);
    
    function dx = f_dx(x,alpha,beta)
        dx = alpha*(1-x) - beta*x;
    end
end

function x = f_h(x,V,Fs)
    step = 1/Fs;
    V_T = -58;
    V_S = -10;
    alpha = 0.128*exp(-(V-V_T-V_S-17)/18)*1000;
    beta = 4/(1+exp(-(V-V_T-V_S-40)/5))*1000;
    
    k_1 = f_dx(x,alpha,beta);
    y_1 = x + k_1*step/2;
    k_2 = f_dx(y_1,alpha,beta);
    y_2 = x + k_2*step/2;
    k_3 = f_dx(y_2,alpha,beta);
    y_3 = x + k_3*step/2;
    k_4 = f_dx(y_3,alpha,beta);
    x = x + step/6*(k_1+2*k_2+2*k_3+k_4);
    
    function dx = f_dx(x,alpha,beta)
        dx = alpha*(1-x) - beta*x;
    end
end

function x = f_n(x,V,Fs)
    step = 1/Fs;
    V_T = -58;
    alpha = -0.032*(V-V_T-15)/(exp(-(V-V_T-15)/5)-1)*1000;
    beta = 0.5*exp(-(V-V_T-10)/40)*1000;
    
    k_1 = f_dx(x,alpha,beta);
    y_1 = x + k_1*step/2;
    k_2 = f_dx(y_1,alpha,beta);
    y_2 = x + k_2*step/2;
    k_3 = f_dx(y_2,alpha,beta);
    y_3 = x + k_3*step/2;
    k_4 = f_dx(y_3,alpha,beta);
    x = x + step/6*(k_1+2*k_2+2*k_3+k_4);
    
    function dx = f_dx(x,alpha,beta)
        dx = alpha*(1-x) - beta*x;
    end
end

function x = f_q(x,V,Fs)
    step = 1/Fs;
    
    alpha = 0.0001*(V+30)/(1-exp(-(V+30)/9))*1000;
    beta = -0.0001*(V+30)/(1-exp((V+30)/9))*1000;
    
    k_1 = f_dx(x,alpha,beta);
    y_1 = x + k_1*step/2;
    k_2 = f_dx(y_1,alpha,beta);
    y_2 = x + k_2*step/2;
    k_3 = f_dx(y_2,alpha,beta);
    y_3 = x + k_3*step/2;
    k_4 = f_dx(y_3,alpha,beta);
    x = x + step/6*(k_1+2*k_2+2*k_3+k_4);
    
    function dx = f_dx(x,alpha,beta)
        dx = alpha*(1-x) - beta*x;
    end
end

function x = f_V(x,m,h,n,q,I_input,Fs)
    step = 1/Fs;
    k_1 = f_dV(x,m,h,n,q,I_input);
    y_1 = x + k_1*step/2;
    k_2 = f_dV(y_1,m,h,n,q,I_input);
    y_2 = x + k_2*step/2;
    k_3 = f_dV(y_2,m,h,n,q,I_input);
    y_3 = x + k_3*step/2;
    k_4 = f_dV(y_3,m,h,n,q,I_input);
    x = x + step/6*(k_1+2*k_2+2*k_3+k_4);
    
    function dx = f_dV(x,m,h,n,q,I_input)
        a = 34636*10^-4;

        C_m  = 1; % specific membrain capacitance (microF/cm^2)
        E_Na = 115;
        E_K = -15;
        E_l = -80;
        
        g_l = 0.045; %(mS/cm^2)
        g_Na_max = 30; %*2*pi*r_s*l_s; %(mS/cm^2)
        g_Kf_max = 4;% *2*pi*r_s*l_s; %(mS/cm^2)
        g_Ks_max = 16; %*2*pi*r_s*l_s; %(mS/cm^2)

        I_Na = g_Na_max*m^3*h*(x-E_Na);
        I_Kf = g_Kf_max*n^4*(x-E_K);
        I_Ks = g_Ks_max*q*(x-E_K);
    
        dx = (-g_l*(x-E_l) - I_Na - I_Kf - I_Ks + I_input)/C_m*1000;   
    end
end