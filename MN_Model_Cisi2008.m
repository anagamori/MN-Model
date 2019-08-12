%==========================================================================
% MN_Model_Cisi2008.m
% Author: Akira Nagamori
% Last update: 8/4/19
% Descriptions:
%==========================================================================

%%
close all
clear all
clc

%%
Fs = 10000;
time = 0:1/Fs:5;

%% modle parameter
R_i = 70*10^-3; %sytoplasm resistivity (ohm*cm)
r_s = 77.5*10^-4; % soma diameter (micrometer)
l_s = 77.5*10^-4; %soma length (micometer)
R_m_s = 1.15; % soma specific resistance (kohm*cm^2)
r_d = 41.5*10^-4; % soma diameter (micrometer)
l_d = 5519*10^-4; %soma length (micometer)
R_m_d = 14.4; % dendrite specific resistance (kohm*cm^2)

C_m  = 1; % specific membrain capacitance (microF/cm^2)
E_Na = 120;
E_K = -10;
E_l = 0;

g_Na_max = 30; %*2*pi*r_s*l_s; %(mS/cm^2)
g_Kf_max = 4;% *2*pi*r_s*l_s; %(mS/cm^2)
g_Ks_max = 16; %*2*pi*r_s*l_s; %(mS/cm^2)

g_c = 2/(R_i*l_d/(pi*r_d^2)+R_i*l_s/(pi*r_s^2)); % coupling conductance
g_ld = 2*pi*r_d*l_d/(R_m_d); % leak conductance for dendrite
g_ls = 2*pi*r_s*l_s/(R_m_s); % leak conductance for soma
C_d = 2*pi*r_d*l_d*C_m*10^3; % dendritic membrane capacitance
C_s = 2*pi*r_s*l_s*C_m*10^3; % somatic membrane capacitance

%% initilization
V_d = 0;
V_s = 0;

m = 0;
h = 1;
n = 0;
q = 0;

%% vactors to save
V_d_vec = zeros(1,length(time));
V_s_vec = zeros(1,length(time));

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
I_inj_s(2*Fs:3*Fs) = 10;
%% simulation
for t = 1:length(time)
    
    alpha_m = 0.32*(13.1-V_s)/(exp((13.1-V_s)/4)-1);
    beta_m = 0.28*(V_s-40.1)/(exp((V_s-40.1)/5)-1);
    alpha_h = 0.128*exp((17-V_s)/18)*1000;
    beta_h = 4/(1+exp((40-V_s)/5))*1000;
    alpha_n = 0.016*(35.1-V_s)/(exp((35.1-V_s)/5)-1);
    beta_n = 0.25*exp((20-V_s)/40);
    alpha_q = min([0.2*10e-4*n,0.01]);
    beta_q = 0.001;
    
    m = state_var(m,alpha_m,beta_m,Fs);
    h = state_var(h,alpha_h,beta_h,Fs);
    n = state_var(n,alpha_n,beta_n,Fs);
    q = state_var(q,alpha_q,beta_q,Fs);
    
    I_ion = g_Na_max*m^3*h*(V_s - E_Na) + g_Kf_max*n^4*(V_s-E_K) ...
        + g_Ks_max*q^2*(V_s-E_K); % membrane current due to the voltage-dependent ionic conductances 
    
    dV_d = 1/C_d*(-I_syn_d(t) - g_ld*(V_d-E_l)-g_c*(V_d-V_s)+I_inj_d(t)); % membrane potential of the dendritic compartment
    dV_s = 1/C_s*(-I_syn_s(t) - g_ls*(V_s-E_l)-g_c*(V_s-V_d)-I_ion+I_inj_s(t)); % membrane potential of the soma compartment 
    
    V_d = 1/Fs*dV_d + V_d;
    V_s = 1/Fs*dV_s + V_s;
    
    V_d_vec(t) = V_d;
    V_s_vec(t) = V_s;
    m_vec(t) = m;
    h_vec(t) = h;
    n_vec(t) = n;
    q_vec(t) = q;
end

figure(1)
subplot(3,1,1)
plot(time,I_inj_s)
subplot(3,1,2)
plot(time,V_d_vec)
subplot(3,1,3)
plot(time,V_s_vec)


function x = state_var(x,alpha,beta,Fs)
    dx = alpha*(1-x) - beta*x;
    x = 1/Fs*dx + x;
end