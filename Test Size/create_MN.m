close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Test Size';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/MN Parameter';

n_MU = 10;
for i = 1:n_MU
type = 'F';
index_MN = num2str(i);

%% Geometric parameters
param.C_m = 1; %[microF/cm^2]
param.R_i = 70e-1; %[kohm*cm] cytoplasm resistivity

param.l_s = parameter(87.5e-4,113e-4,n_MU,i); %[cm] soma length
param.r_s = parameter(87.5e-4,113e-4,n_MU,i); %[cm] soma radius
param.R_m_s = parameter(0.95,0.65,n_MU,i); %[kohm*cm^2] somatic membrane specfic resistance

param.l_d = parameter(83.5e-4,92.5e-4,n_MU,i); %[cm] dendrite length
param.r_d = parameter(8.1e-1,10.6e-1,n_MU,i); %[cm] dendrite radius
param.R_m_d = parameter(6.95,6.05,n_MU,i); %[kohm*cm^2] dendritic membrane specfic resistance

param.I_r = parameter(17.5e-9,25.1e-9,n_MU,i); %3.5e-9; %[A] rheobase current

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
save([type '_' index_MN],'param')
cd(code_folder)

end

function x = parameter(min_val,max_val,range,index)
    x_temp =linspace(min_val,max_val,range);
    x = x_temp(index);
end