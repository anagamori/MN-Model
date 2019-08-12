%==========================================================================
% MN_Model_Destexhe2001.m
% Author: Akira Nagamori
% Last update: 8/5/19
% Descriptions:
%==========================================================================

close all
clear all
clc



V_m = 0; %-56;

Fs = 10000;
step = 1/Fs;
time = 0:1/Fs:1;
I_app = zeros(1,length(time)); % applied current (microA/cm^2)
I_app(0.5*Fs:end) = 10;

m = 0.053;
h = 0.5961;
n = 0.3177;

%V_m = 100*ones(1,length(time));

for t = 1:length(time)
        
    alpha_m = 0.1*(25-V_m)/(exp((25-V_m)/10)-1)*1000;
    beta_m = 4.0*(exp(-V_m/18))*1000;
    
    alpha_h = 0.07*exp(-V_m/20)*1000;
    beta_h = 1/(exp((30-V_m)/10)+1)*1000;
    
    alpha_n = 0.01*(10-V_m)/(exp((10-V_m)/10)-1)*1000;
    beta_n = 0.125*(exp(-V_m/80))*1000;
    
    dm = alpha_m*(1-m) - beta_m*m;
    dh = alpha_h*(1-h) - beta_h*h;
    dn = alpha_n*(1-n) - beta_n*n;
    
%     dV_m = f_dV(V_m,m,h,n,I_app(t));
%     V_m = dV_m/Fs+V_m;

    k_1 = f_dV(V_m,m,h,n,I_app(t));
    y_1 = V_m + k_1*step/2;
    k_2 = f_dV(y_1,m,h,n,I_app(t));
    y_2 = V_m + k_2*step/2;
    k_3 = f_dV(y_2,m,h,n,I_app(t));
    y_3 = V_m + k_3*step/2;
    k_4 =  f_dV(y_3,m,h,n,I_app(t));
    V_m = V_m + step/6*(k_1+2*k_2+2*k_3+k_4);
    
    m = dm/Fs+ m;
    h = dh/Fs+ h;
    n = dn/Fs+ n;
   
    V_m_vec(t) = V_m;
    m_vec(t) = m;
    h_vec(t) = h;
    n_vec(t) = n;
end

figure(1)
subplot(2,1,1)
plot(time,I_app)
subplot(2,1,2)
plot(time,V_m_vec)

figure(2)
plot(time,m_vec)
hold on 
plot(time,h_vec)
hold on
plot(time,n_vec)
legend('m','h','n')

%%
g_K_max = 36;
g_Na_max = 120;
figure(3)
plot(time,g_Na_max.*m_vec.^3.*h_vec)
hold on
plot(time,g_K_max*n_vec.^4)
legend('g_{Na}','g_{K}')

function dx = f_dV(x,m,h,n,I_app)
E_Na = 115;
E_K = -12;
E_L = 10.6;
g_K_max = 36;
g_Na_max = 120;
g_L_max = 0.3;
C_m = 1;

I_Na = g_Na_max*m^3*h*(x-E_Na);
I_K = g_K_max*n^4*(x-E_K);
I_L = g_L_max*(x-E_L);

dx = 1/C_m*(-I_Na-I_K-I_L+I_app)*1000;

end
