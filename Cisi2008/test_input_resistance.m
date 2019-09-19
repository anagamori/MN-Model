close all
clear all
clc

%%
code_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

cd(data_folder)
load('mnParameter')
cd(code_folder)

for i = 1:120
    i
    n_MU = i;
    
    type = 'S';
    index_MN = num2str(n_MU);
    
    alpha = 1;
    %% Geometric parameters
    param.C_m = 3; %[microF/cm^2]
    % param.R_i = 70e-1; %[kohm*cm] cytoplasm resistivity
    
    param.q = 12.9; % the ratio of dendritic surface area to somatic surface area (Barrett and Crill 1974)
    %total_area = 179000e-8;
    param.area_s = mnParameter.area_s(i); %77.5e-4 - alpha*(82.5e-4-77.5e-4); %parameter(87.5e-4,113e-4,n_MU,i); %[cm^2] 
    param.R_m_s = mnParameter.R_m_s(i); %2.2; %1.15 + alpha*(1.15-1.05); %parameter(0.95,0.65,n_MU,i); %[kohm*cm^2] somatic membrane specfic resistance
    
    param.R_m_d = mnParameter.R_m_d(i); %2.2; %14.4 + alpha*(14.4-10.7); %parameter(6.95,6.05,n_MU,i); %[kohm*cm^2] dendritic membrane specfic resistance
    
    param.I_r = 2.0e-9; %parameter(17.5e-9,25.1e-9,n_MU,i); %3.5e-9; %[A] rheobase current
    
    %%
    param.V_Na = 120; %(mV)
    param.V_K = -10; %(mV)
    param.V_l = 0; %(mV)
    
    %%
    param.g_Na = 30; %*param_s.area_s ; %(mS/cm^2)
    param.g_Kf = 4; %*param_s.area_s ; %(mS/cm^2)
    param.g_Ks = 16; %*param_s.area_s ; %(mS/cm^2)
    param.g_c = 0.1;
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
    Fs = 10000;
    time = 0:1/Fs:5;
    noise_amp = 0;
    
    %% Test input resistance
    % Methods (Zengel et al. 1985)
    amp_vec = 0.001/param.area_s;
    input  = zeros(1,length(time));
    input(1*Fs+1:1.2*Fs) = amp_vec;
    
    inputOpt = 1;
    pltOpt = 0;
    
    [binary,V_s,~] = Cisi2008_function_v2(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
    
    V_s_ss = mean(V_s(round(1.14*Fs):round(1.2*Fs)));
    R_input_s(i) = V_s_ss/0.001;
    
    V_s_ts = V_s(round(1.2*Fs):round(1.23*Fs));
    time_ts = 0:1/Fs:0.03;
    f = fit(time_ts',V_s_ts','exp1');
    coeffs_f = coeffvalues(f);
    tau_s(i) = abs(1/coeffs_f(2)*1000);
end

figure(1)
histogram(R_input_s)

figure(2)
histogram(tau_s)
