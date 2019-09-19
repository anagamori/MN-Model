%==========================================================================
% electrical_parameter.m
% Author: Akira Nagamori
% Last update: 9/18/19
% Descriptions:
%==========================================================================

close all
clear all
clc

code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

N_MU = 120;
i_MU = 1:N_MU;
%% Soma diameter
min_d = 65;
max_d = 350; 
rng(1)
area_s = round(normrnd((max_d+min_d)/2,69,[1,N_MU]));
max(area_s)
min(area_s)
area_s = area_s*10^-6;
figure(1)
histogram(area_s)
title('Soma surface area')
mnParameter.area_s = area_s';
%%
min_R_m_s = 0.5;
max_R_m_s = 1;
f_R_m_s = fit([1 N_MU]',[max_R_m_s min_R_m_s]','exp1');
coeffs_f_R_m_s = coeffvalues(f_R_m_s);
R_m_s_vec = coeffs_f_R_m_s(1)*exp(coeffs_f_R_m_s(2)*i_MU); % the resulting recruitment threshold for individual units

mnParameter.R_m_s = R_m_s_vec';

%%
min_R_m_d = 5.3;
max_R_m_d = 5.8;
f_R_m_d = fit([1 N_MU]',[max_R_m_d min_R_m_d]','exp1');
coeffs_f_R_m_d = coeffvalues(f_R_m_d);
R_m_d_vec = coeffs_f_R_m_d(1)*exp(coeffs_f_R_m_d(2)*i_MU); % the resulting recruitment threshold for individual units

mnParameter.R_m_d = R_m_d_vec';
%%
min_I_r = 1e-9;
max_I_r = 32e-9;
rng(1)
I_r_vec = raylrnd(10,1,120);
I_r_vec = I_r_vec*10^-9;

mnParameter.I_r = I_r_vec';

figure(3)
histogram(I_r_vec)
title('Rhoebase current')
%% Save model parameters
cd(data_folder)
save('mnParameter','mnParameter')
cd(code_folder)
