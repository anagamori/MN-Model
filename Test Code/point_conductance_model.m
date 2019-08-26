%==========================================================================
% point_conductance_model.m
% Author: Akira Nagamori
% Last update: 8/14/19
% Descriptions:
%   Equations obtained from Destexhe et al. (2001)
%==========================================================================

close all
clear all
clc

%%
Fs = 10000;
time = 0:1/Fs:0.5;
noise_amp = 1;

E_e = 0;
E_i = -75;
g_e0 = 0.012;
g_e = 0;
g_i0 = 0.057;
g_i = 0;
tau_e = 0.0027;
tau_i = 0.0105;

V = -65;

I_syn_vec = zeros(1,length(time));
x_e = normrnd(0,1,[1,length(time)]);
x_i = normrnd(0,1,[1,length(time)]);

for t = 1:length(time)
    I_syn = g_e*(V-E_e) + g_i*(V-E_i);
    
    dg_e = -1/tau_e*(g_e-g_e0) + sqrt(noise_amp)*x_e(t);
    g_e = dg_e/Fs + g_e;
    
    dg_i = -1/tau_i*(g_i-g_e0) + sqrt(noise_amp)*x_i(t);
    g_i = dg_i/Fs + g_i;
    
    I_syn_vec(t) = I_syn;
end

plot(time,I_syn_vec)