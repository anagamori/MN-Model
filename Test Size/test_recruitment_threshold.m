close all
clear all
clc

%%
Fs = 30000;
time = 0:1/Fs:5;
noise_amp = 0;

for j = 1:3
    %%
    l_s = 77.5; %77.5;
    d_s = 77.5;
    area_s = 2*pi*l_s*d_s;
    
    l_d = 62.5; %41.5;
    d_d = 6798; %5519;
    area_d = 2*pi*l_d*d_d;
    %% Soma parameters
    param_s.V_Na_f = 55; %(mV)
    param_s.V_K_f = -80; %(mV)
    param_s.V_Ca_f = 80; %(mV)
    param_s.V_L_f = -60; %(mV)
    
    param_s.g_Na_f = 120; %(mS/cm^2)
    param_s.g_K_dr_f = 100; %(mS/cm^2)
    param_s.g_Ca_N_f = 14; %(mS/cm^2)
    param_s.g_K_Ca_f = 15; %3.136; %(mS/cm^2)
    
    if j == 3
        param_s.g_K_Ca_f = 20; 
    end

    
    param_s.g_L_f = 0.51; %0.51; %1/1.15; %0.51; %(mS/cm^2) 1150.0
    
    if j == 1
        param_s.g_c_f = 0.1; %coupling conductance (mS/cm^2)
    else
        param_s.g_c_f = 0.15; %coupling conductance (mS/cm^2)
    end
    param_s.p_f = 0.1; %area_s/(area_s+area_d); %the ratio of somatic surface area to toal cell surface area
    param_s.K_d_f = 0.2; %(microM)
    
    param_s.C_m_f = 1; %(microF/cm^2)
    
    param_s.theta_m_f = -35; %(mV)
    param_s.k_m_f = -7.8; %(mV)
    %% Dendrite parameters
    param_d.V_K_f = -80; %(mV)
    param_d.V_Ca_f = 80; %(mV)
    param_d.V_L_f = -60; %(mV)
    
    param_d.g_Ca_N_f = 0.3; %(mS/cm^2)
    param_d.g_K_Ca_f = 1.1; %(mS/cm^2)
    param_d.g_Ca_L_f = 0.33; %(mS/cm^2)
    param_d.g_L_f = 0.51; %1/14.35; %(mS/cm^2)
    param_d.g_c_f = param_s.g_c_f; %coupling conductance (mS/cm^2)
    param_d.p_f = param_s.p_f; %the ratio of somatic surface area to toal cell surface area
    param_d.K_d_f = param_s.K_d_f ; %(microM)
    
    param_d.C_m_f = 1; %(microF/cm^2)
    
    %% Somatic input
    amp_vec = [1:20];
    for i = 1:length(amp_vec)
        %I_input = [zeros(1,1*Fs) amp_vec*[0:1/Fs:1] amp_vec*ones(1,length(time)-1*Fs-length(amp_vec*[0:1/Fs:1]))];
        I_input  = zeros(1,length(time));
        I_input(1*Fs+1:end) = amp_vec(i);
        
        [binary,V_s,V_d] = Booth1997_function(param_s,param_d,time,I_input,Fs,noise_amp,1,0);
        
        spike_time = find(binary(end-2*Fs+1:end));
        ISI = diff(spike_time)/(Fs/1000);
        mean_FR(i) = mean(1./ISI*1000);
        CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;
        
        temp = ISI(1:end-1);
        temp2 = ISI(2:end);
        [R,P] = corrcoef(temp,temp2);
        
    end
    
    figure(1)
    plot(amp_vec,mean_FR,'LineWidth',1)
    xlabel('Injected Current (nA/cm^2)')
    ylabel('Dischage Rate (Hz)')
    hold on
    
end