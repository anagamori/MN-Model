close all
clear all
clc

%%
code_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

cd(data_folder)
load('mnParameter')
cd(code_folder)
n_MU = 120;
for j = 1:n_MU
    j
    %% Geometric parameters
    param.C_m = 3; %[microF/cm^2]
    % param.R_i = 70e-1; %[kohm*cm] cytoplasm resistivity
    
    param.q = 12.9; % the ratio of dendritic surface area to somatic surface area (Barrett and Crill 1974)
    %total_area = 179000e-8;
    param.area_s = mnParameter.area_s(i); %77.5e-4 - alpha*(82.5e-4-77.5e-4); %parameter(87.5e-4,113e-4,n_MU,i); %[cm^2]
    param.R_m_s = mnParameter.R_m_s(i); %2.2; %1.15 + alpha*(1.15-1.05); %parameter(0.95,0.65,n_MU,i); %[kohm*cm^2] somatic membrane specfic resistance
    
    param.R_m_d = mnParameter.R_m_d(i); %2.2; %14.4 + alpha*(14.4-10.7); %parameter(6.95,6.05,n_MU,i); %[kohm*cm^2] dendritic membrane specfic resistance
    
    param.I_r = mnParameter.I_r(i); %parameter(17.5e-9,25.1e-9,n_MU,i); %3.5e-9; %[A] rheobase current
    
    %%
    param.V_Na = 120; %(mV)
    param.V_K = -10; %(mV)
    param.V_l = 0; %(mV)
    
    %%
    param.g_Na = 30; %*param_s.area_s ; %(mS/cm^2)
    param.g_Kf = mnParameter.g_Kf(i); %*param_s.area_s ; %(mS/cm^2)
    param.g_Ks = mnParameter.g_Ks(i); %*param_s.area_s ; %(mS/cm^2)
    param.g_c = 0.1;
    %%
    param.alpha_m = 22*1000;
    param.beta_m = 13*1000;
    param.alpha_h = 0.5*1000;
    param.beta_h = 4*1000;
    param.alpha_n = 1.5*1000;
    param.beta_n = 0.1*1000;
    param.alpha_q = 1.5*1000;
    param.beta_q = mnParameter.beta_q(i);
    
    %%
    amp_vec = 0:1:100;
    mean_FR = zeros(1,length(amp_vec));
    CoV_FR = zeros(1,length(amp_vec));
    for i = 1:length(amp_vec)
        Fs = 10000;
        time = 0:1/Fs:5;
        noise_amp = 0;
        
        amp = amp_vec(i);
        input  = zeros(1,length(time));
        input(1*Fs+1:end) = amp;
        
        inputOpt = 2;
        pltOpt = 0;
        %%
        [binary,V_s,V_d] = Cisi2008_function_v2(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
        
        spike_time = find(binary(end-2*Fs+1:end));
        ISI = diff(spike_time)/(Fs/1000);
        mean_FR(i) = mean(1./ISI*1000);
        CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;
    end
    %%
    index_t = find(~isnan(mean_FR));
    
    current_th(j) = amp_vec(index_t(1));
    min_DR(j) = mean_FR(index_t(1));
    
    
    p_fit = polyfit(amp_vec(index_t),mean_FR(index_t),1);
    y1 = polyval(p_fit,amp_vec(index_t));
    
    figure(1)
    plot(amp_vec,mean_FR,'LineWidth',2)
    hold on
    plot(amp_vec(index_t),y1,'--k','LineWidth',1)
    xlabel('Injected Current (nA)','FontSize',14)
    ylabel('Dischage Rate (Hz)','FontSize',14)
    set(gca,'TickDir','out');
    set(gca,'box','off')
    
end

