%==========================================================================
% mn_parameter_pool.m
% Author: Akira Nagamori
% Last update: 9/22/19
% Descriptions:
%   -  Generate a structure variable, mn_parameter, to run MN_model_population
%==========================================================================

close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

cd(data_folder)
load('modelParameter')
load('current_th')
load('current_peak')
cd(code_folder)

N_MU = modelParameter.N_MU;
[U_th_sort,idx] = sort(modelParameter.U_th);

for n = 1:N_MU
    cd(data_folder)
    load(['MN_' num2str(n)])
    cd(code_folder)
    
    mn_parameter.C_m = param.C_m;
    mn_parameter.q = param.q;
     
    mn_parameter.area_s(n) = param.area_s;
    mn_parameter.R_m_s(n) = param.R_m_s;
    mn_parameter.R_m_d(n) = param.R_m_d;
    mn_parameter.I_r(n) = param.I_r;
    
    mn_parameter.V_Na = param.V_Na;
    mn_parameter.V_K = param.V_K;
    mn_parameter.V_l = param.V_l;
    
    mn_parameter.g_Na = param.g_Na;
    mn_parameter.g_Kf(n) = param.g_Kf;
    mn_parameter.g_Ks(n) = param.g_Ks;
    mn_parameter.g_c = param.g_c;
    
    mn_parameter.alpha_m = param.alpha_m;
    mn_parameter.beta_m = param.beta_m;
    mn_parameter.alpha_h = param.alpha_h;
    mn_parameter.beta_h = param.beta_h;
    mn_parameter.alpha_n = param.alpha_n;
    mn_parameter.beta_n = param.beta_n;
    mn_parameter.alpha_q(n) = param.alpha_q;
    mn_parameter.beta_q(n) = param.beta_q;
    
    mn_parameter.I_min(n) = current_th(n);
    mn_parameter.I_max(n) = current_peak(n);
    mn_parameter.U_th(n) = U_th_sort(n);
end

mn_parameter.area_s = mn_parameter.area_s';
mn_parameter.R_m_s = mn_parameter.R_m_s';
mn_parameter.R_m_d = mn_parameter.R_m_d';
mn_parameter.I_r = mn_parameter.I_r';
   
mn_parameter.g_Kf = mn_parameter.g_Kf';
mn_parameter.g_Ks =  mn_parameter.g_Ks';

mn_parameter.alpha_q = mn_parameter.alpha_q';
mn_parameter.beta_q = mn_parameter.beta_q';

mn_parameter.I_min = mn_parameter.I_min';
mn_parameter.I_max = mn_parameter.I_max';
mn_parameter.U_th = mn_parameter.U_th';

cd(data_folder)
save('mn_parameter','mn_parameter')
cd(code_folder)