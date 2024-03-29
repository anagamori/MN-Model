%close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Test Size';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/MN Parameter';

n_MU = 11;

type = 'S';
index_MN = num2str(n_MU);

alpha = 1;
%% Geometric parameters
param.C_m = 1; %[microF/cm^2]
param.R_i = 70e-1; %[kohm*cm] cytoplasm resistivity

param.l_s = 60e-4; %77.5e-4 - alpha*(82.5e-4-77.5e-4); %parameter(87.5e-4,113e-4,n_MU,i); %[cm] soma length
param.r_s = 60e-4; %77.5e-4 - alpha*(82.5e-4-77.5e-4); %parameter(87.5e-4,113e-4,n_MU,i); %[cm] soma radius
param.R_m_s = 1.15 + alpha*(1.15-1.05); %parameter(0.95,0.65,n_MU,i); %[kohm*cm^2] somatic membrane specfic resistance

param.l_d = 41.5e-4 - alpha*(62.5e-4-41.5e-4); %parameter(83.5e-4,92.5e-4,n_MU,i); %[cm] dendrite length
param.r_d = 5.5e-1 -  alpha*(6.8e-1-5.5e-1); %parameter(8.1e-1,10.6e-1,n_MU,i); %[cm] dendrite radius
param.R_m_d = 14.4 + alpha*(14.4-10.7); %parameter(6.95,6.05,n_MU,i); %[kohm*cm^2] dendritic membrane specfic resistance

param.I_r = 2.0e-9; %parameter(17.5e-9,25.1e-9,n_MU,i); %3.5e-9; %[A] rheobase current

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

cd(data_folder)
save([type '_' index_MN],'param')
cd(code_folder)

%%
Fs = 10000;
time = 0:1/Fs:5;
noise_amp = 0;

%% Test input resistance 
% Methods (Zengel et al. 1985)
amp_vec = 0.001/(2*pi*param.l_s*param.r_s);
input  = zeros(1,length(time));
input(1*Fs+1:1.2*Fs) = amp_vec;

inputOpt = 1;
pltOpt = 1;

[binary,V_s,~] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);

V_s_ss = mean(V_s(round(1.14*Fs):round(1.2*Fs)));
R_input_s = V_s_ss/0.001

