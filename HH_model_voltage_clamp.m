%==========================================================================
% MN_Model_Destexhe2001.m
% Author: Akira Nagamori
% Last update: 8/5/19
% Descriptions:
%==========================================================================

close all
clear all
clc

E_Na = 115;
E_K = -12;
E_L = 10.6;
g_K_max = 36;
g_Na_max = 120;
g_L_max = 0.3;
C_m = 1;

V_m = -56;

Fs = 10000;
time = 0:1/Fs:1;
I_app = zeros(1,length(time)); % applied current (microA/cm^2)
I_app(0.5*Fs:end) = 0;

m = 0;
h = 1;
n = 0;

V_m = 100*ones(1,length(time));

for t = 1:length(time)
    
    m_vec(t) = m;
    h_vec(t) = h;
    n_vec(t) = n;
    
    alpha_m = 0.1*(25-V_m(t))/(exp((25-V_m(t))/10)-1)*1000;
    beta_m = 4.0*(exp(-V_m(t)/18))*1000;
    
    alpha_h = 0.07*exp(-V_m(t)/20)*1000;
    beta_h = 1/(exp((30-V_m(t))/10)+1)*1000;
    
    alpha_n = 0.01*(10-V_m(t))/(exp((10-V_m(t))/10)-1)*1000;
    beta_n = 0.125*(exp(-V_m(t)/80))*1000;
    
    dm = alpha_m*(1-m) - beta_m*m;
    dh = alpha_h*(1-h) - beta_h*h;
    dn = alpha_n*(1-n) - beta_n*n;
    
    
    m = dm/Fs+ m;
    h = dh/Fs+ h;
    n = dn/Fs+ n;
  
    
end

figure(2)
plot(time,m_vec)
hold on 
plot(time,h_vec)
hold on
plot(time,n_vec)

figure(3)
plot(time,g_Na_max.*m_vec.^3.*h_vec)
hold on
plot(time,g_K_max*n_vec.^4)
legend('g_{Na}','g_{K}')
