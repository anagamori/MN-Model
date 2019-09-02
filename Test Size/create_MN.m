close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Test Size';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/MN Parameter';

type = 'F';
nMN = '1';
%% Geometric parameters
param.C_m = 1; %[microF/cm^2]
param.R_i = 70e-1; %[kohm*cm] cytoplasm resistivity

param.l_s = 87.5e-4; %[cm] soma length
param.r_s = 87.5e-4; %[cm] soma radius
param.R_m_s = 0.95; %[kohm*cm^2] somatic membrane specfic resistance

param.l_d = 83.5e-4; %[cm] dendrite length
param.r_d = 8.1e-1; %[cm] dendrite radius
param.R_m_d = 6.95; %[kohm*cm^2] dendritic membrane specfic resistance

param.I_r = 17.5e-9; %[A] rheobase current

%%
param.V_Na = 120; %(mV)
param.V_K = -10; %(mV)
param.V_l = 0; %(mV)

%%
param.g_Na = 30; %*param_s.area_s ; %(mS/cm^2)
param.g_Kf = 0.5; %*param_s.area_s ; %(mS/cm^2)
param.g_Ks = 4; %*param_s.area_s ; %(mS/cm^2)
param.g_c = 0.05;
%%
param.alpha_m = 22*1000;
param.beta_m = 13*1000;
param.alpha_h = 0.5*1000;
param.beta_h = 4*1000;
param.alpha_n = 1.5*1000;
param.beta_n = 0.1*1000;
param.alpha_q = 1.5*1000;
param.beta_q = 0.05*1000;

cd(data_folder)
save([type '_' nMN],'param')
cd(code_folder)