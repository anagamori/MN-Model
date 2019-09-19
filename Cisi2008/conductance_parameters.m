%==========================================================================
% conductance_parameter.m
% Author: Akira Nagamori
% Last update: 9/18/19
% Descriptions:
%==========================================================================

close all
clear all
clc

code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

%%
cd(data_folder)
load('mnParameter')
load('modelParameter')
cd(code_folder)
%%
N_MU = 120;
i_MU = 1:N_MU;

index_slow = modelParameter.index_slow;

%%
mnParameter.V_Na = 120; %(mV)
mnParameter.V_K = -10; %(mV)
mnParameter.V_l = 0; %(mV)

%%
mnParameter.g_Na = 30; %*param_s.area_s ; %(mS/cm^2)
mnParameter.g_Kf = [4*ones(index_slow,1);0.5*ones(N_MU-index_slow,1)]; %*param_s.area_s ; %(mS/cm^2)
mnParameter.g_Ks = [16*ones(index_slow,1);4*ones(N_MU-index_slow,1)]; %*param_s.area_s ; %(mS/cm^2)
mnParameter.g_c = 0.1;
%%
mnParameter.alpha_m = 22*1000;
mnParameter.beta_m = 13*1000;
mnParameter.alpha_h = 0.5*1000;
mnParameter.beta_h = 4*1000;
mnParameter.alpha_n = 1.5*1000;
mnParameter.beta_n = 0.1*1000;
mnParameter.alpha_q = 1.5*1000;
mnParameter.beta_q = [0.025*1000*ones(index_slow,1);0.05*ones(N_MU-index_slow,1)];

%% Save model parameters
cd(data_folder)
save('mnParameter','mnParameter')
cd(code_folder)
