%==========================================================================
% pool_parameter.m
% Author: Akira Nagamori
% Last update: 9/16/19
% Descriptions:
%   - Find an index that divides a pool into slow and fast motor units (index_slow)
%   - Find recruitment thresholds of individual motor units
%==========================================================================

close all
clear all
clc

code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

N_MU = 120;
i_MU = 1:N_MU;
%% Soma diameter
min_d = 70;
max_d = 350; 
rng(1)
d_vec = round(normrnd((max_d+min_d)/2,67,[1,N_MU]));
max(d_vec)
min(d_vec)
d_vec = d_vec*10^-6;
figure(1)
histogram(d_vec)
title('Soma surface area')
mnParameter.d = d_vec;
%%
min_R_m = 0.3;
max_R_m = 1.8;
f_R_m = fit([1 N_MU]',[max_R_m min_R_m]','exp1');
coeffs_f_R_m = coeffvalues(f_R_m);
R_m_vec = coeffs_f_R_m(1)*exp(coeffs_f_R_m(2)*i_MU); % the resulting recruitment threshold for individual units

mnParameter.R_m = R_m_vec;
%%
min_I_r = 1e-9;
max_I_r = 32e-9;
rng(1)
I_r_vec = raylrnd(10,1,120);
I_r_vec = I_r_vec*10^-9;

mnParameter.I_r = I_r_vec;

figure(3)
histogram(I_r_vec)
title('Rhoebase current')
%% Save model parameters
cd(data_folder)
save('mnParameter','mnParameter')
cd(code_folder)
