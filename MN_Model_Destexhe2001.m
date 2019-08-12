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

C_m  = 1*10^-3; % specific membrain capacitance (microF/cm^2)
E_Na = 115;
E_K = -15;
E_l = -80;

g_l = 0.045; %(mS/cm^2)
g_Na_max = 30; %*2*pi*r_s*l_s; %(mS/cm^2)
g_Kf_max = 4;% *2*pi*r_s*l_s; %(mS/cm^2)
g_Ks_max = 16; %*2*pi*r_s*l_s; %(mS/cm^2)

g_c = 2/(R_i*l_d/(pi*r_d^2)+R_i*l_s/(pi*r_s^2)); % coupling conductance
g_ld = 2*pi*r_d*l_d/(R_m_d); % leak conductance for dendrite
g_ls = 2*pi*r_s*l_s/(R_m_s); % leak conductance for soma
C_d = 2*pi*r_d*l_d*C_m*10^3; % dendritic membrane capacitance
C_s = 2*pi*r_s*l_s*C_m*10^3; % somatic membrane capacitance

a = 34636*10^-4;
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
I_inj_s(2*Fs:3*Fs) = 10;
%% simulation
for t = 1:length(time)
      
    I_Na = g_Na_max*m^3*h*(V-E_Na);
    I_Kf = g_Kf_max*n^4*(V-E_K);
    I_Ks = g_Ks_max*q*(V-E_K);
    
    dV = (-g_l*(V-E_l) - I_Na - I_Kf - I_Ks + I_inj_s(t)/a)/C_m;    
    V = 1/Fs*dV + V;
    
    alpha_m = 0.32*(13.1-V-58)/(exp((13.1-V-58)/4)-1);
    beta_m = 0.28*(V-40.1-58)/(exp((V-40.1-58)/5)-1);
    alpha_h = 0.128*exp((17-V-68)/18);
    beta_h = 4/(1+exp((40-V-68)/5));
    alpha_n = 0.016*(35.1-V-58)/(exp((35.1-V-58)/5)-1);
    beta_n = 0.25*exp((20-V-58)/40);
    alpha_q = min([0.2*10e-4*n,0.01]);
    beta_q = 0.001;
    
    m = state_var(m,alpha_m,beta_m,Fs);
    h = state_var(h,alpha_h,beta_h,Fs);
    n = state_var(n,alpha_n,beta_n,Fs);
    q = state_var(q,alpha_q,beta_q,Fs);
    
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



function x = state_var(x,alpha,beta,Fs)
    dx = alpha*(1-x) - beta*x;
    x = 1/Fs*dx + x;
end