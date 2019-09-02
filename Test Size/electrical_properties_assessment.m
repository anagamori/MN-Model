close all
clear all
clc

%% Geometric parameters
param.C_m = 1; %[microF/cm^2]
param.R_i = 70e-1; %[kohm*cm] cytoplasm resistivity

param.l_s = 77.5e-4; %[cm] soma length
param.r_s = 77.5e-4; %[cm] soma radius
param.R_m_s = 1.15; %[kohm*cm^2] somatic membrane specfic resistance

param.l_d = 41.5e-4; %[cm] dendrite length
param.r_d = 5.5e-1; %[cm] dendrite radius
param.R_m_d = 14.4; %[kohm*cm^2] dendritic membrane specfic resistance

param.I_r = 3.5e-9; %[A] rheobase current

%%
param.V_Na = 120; %(mV)
param.V_K = -10; %(mV)
param.V_l = 0; %(mV)

%%
param.g_Na = 30; %*param_s.area_s ; %(mS/cm^2)
param.g_Kf = 4; %*param_s.area_s ; %(mS/cm^2)
param.g_Ks = 16; %*param_s.area_s ; %(mS/cm^2)
param.g_c = 0.05;
%%
param.alpha_m = 22*1000;
param.beta_m = 13*1000;
param.alpha_h = 0.5*1000;
param.beta_h = 4*1000;
param.alpha_n = 1.5*1000;
param.beta_n = 0.1*1000;
param.alpha_q = 1.5*1000;
param.beta_q = 0.025*1000;

%%
Fs = 100000;
time = 0:1/Fs:5;
noise_amp = 0;

amp_vec = 22;
input  = zeros(1,length(time));
input(1*Fs+1:1.2*Fs) = amp_vec;

inputOpt = 1;
pltOpt = 1;
%%
[binary,V_s,~] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);

spike_time = find(binary);
V_base = V_s(spike_time(1)-1);
[~,loc] = min(abs(V_s(spike_time(1):spike_time(2))-V_base));
V_return = V_s(spike_time(1)+loc);
AHP_duration = loc/(Fs/1000)
AHP_mag = min(V_s(spike_time(1):spike_time(2)))

%%
amp_vec = 10;
input  = zeros(1,length(time));
input(1*Fs+1:1.2*Fs) = amp_vec;
[binary,V_s,~] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
%%
V_temp = V_s(1.2*Fs+1:1.5*Fs);
V_temp = V_temp';
time_temp = 1/(Fs/1000):1/(Fs/1000):length(V_temp)/(Fs/1000);
time_temp = time_temp';

f = polyfit(time_temp,log(V_temp),1);
tau = 1/abs(f(1))
