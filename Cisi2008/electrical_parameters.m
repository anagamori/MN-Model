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
min_d = 30e-4;
max_d = 90e-4; 
rng(1)
d_vec = normrnd((max_d+min_d)/2,12e-4,[1,N_MU]);
figure(1)
histogram(d_vec)

mnParameter.d = d_vec;
%%
min_R_m = 0.4;
max_R_m = 1.1;
f_R_m = fit([1 N_MU]',[max_R_m min_R_m]','exp1');
coeffs_f_R_m = coeffvalues(f_R_m);
R_m_vec = coeffs_f_R_m(1)*exp(coeffs_f_R_m(2)*i_MU); % the resulting recruitment threshold for individual units

mnParameter.R_m = R_m_vec;
%%
min_I_r = 1.0e-9;
max_I_r = 32e-9;

%% Save model parameters
cd(data_folder)
save('mnParameter','mnParameter')
cd(code_folder)
