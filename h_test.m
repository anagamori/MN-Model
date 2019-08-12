%==========================================================================
% MN_Model_Destexhe2001.m
% Author: Akira Nagamori
% Last update: 8/5/19
% Descriptions:
%==========================================================================

close all
clear all
clc

%%
g_c = 0.1; %coupling conductance (mS/cm^2)
p = 0.1; %the ratio of somatic surface area to toal cell surface area

K_d = 0.2; %(microM)

%%
g_Na = 120; %(mS/cm^2)
g_K_dr = 100; %(mS/cm^2)
g_Ca_N_s = 14; %(mS/cm^2)
g_Ca_N_d = 0.3; %(mS/cm^2)
g_K_Ca_s = 5; %(mS/cm^2)
g_K_Ca_d = 1.1; %(mS/cm^2)
g_Ca_L = 0.33; %(mS/cm^2)
g_L = 0.51; %(mS/cm^2)
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
V_Na = 55; %(mV)
V_K = -80; %(mV)
V_Ca = 80; %(mV)
V_L = -60; %(mV)

%%
C_m = 1; %(microF/cm^2)

%%

V_s = -57;
V_d = -57;
m_inf = 1/(1+exp((V_s-theta_m)/k_m));

h = 0.6017;
n = 0.12;
m_N_s = 0.004;
h_N_s = 0.9294;
m_N_d = 0.0046;
h_N_d = 0.9146;
m_L = 0.083;
Ca_s = 0.001;
Ca_d = 0.17;

%%
Fs = 10000;
time = 0:1/Fs:5;
I_app = zeros(1,length(time)); % applied current (microA/cm^2)

I_app(0.5*Fs:end) = 10;

V_s = -65*ones(1,length(time));
V_s(0.5*Fs:end) = 10;
%% 
V_s_vec =  zeros(1,length(time));
V_d_vec =  zeros(1,length(time));
m_inf_vec =  zeros(1,length(time));
h_vec =  zeros(1,length(time));
n_vec =  zeros(1,length(time));
m_N_s_vec =  zeros(1,length(time));
Ca_s_vec =  zeros(1,length(time));
Ca_d_vec =  zeros(1,length(time));

I_Na_vec = zeros(1,length(time));
I_K_dr_vec = zeros(1,length(time));

%%
for t = 1:length(time)   

    
    %% State variables for ionic conductances
    I_Na = g_Na*m_inf^3*h*(V_s(t)-V_Na);
    m_inf = 1/(1+exp((V_s(t)-theta_m)/k_m));
    tau_h = time_constant_h(V_s(t));
    h = conductance_kinetics(h,V_s(t),tau_h,theta_h,k_h,Fs);
    tau_n = time_constant_n(V_s(t));
    n = conductance_kinetics(n,V_s(t),tau_n,theta_n,k_n,Fs);
    m_N_s = conductance_kinetics(m_N_s,V_s(t),tau_m_N,theta_m_N,k_m_N,Fs);
    
    I_Na_vec(t) =  I_Na;
   
end

%%
figure(1)
plot(time,I_Na_vec)
xlabel('Time (s)')
ylabel('Soma potential (mV)')

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
 alpha = 0.009; %(mol/C/microm)
 k_Ca = 2; %(s)
 
dCa = f*(-alpha*I_Ca - k_Ca*Ca);
Ca = dCa*1/Fs + Ca;

end