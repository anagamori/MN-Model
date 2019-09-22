%==========================================================================
% final_test_Cisi_v2.m
% Author: Akira Nagamori
% Last update: 9/21/19
% Descriptions:
%   - Test the MN parameter of individual MNs
%   - Record the minimal discharge rate, recruitment threshold, and current
%   required for the maximal discharge rate
%==========================================================================

close all
clear all
clc

%%
code_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

cd(data_folder)
load('mnParameter')
load('MDR')
load('modelParameter')
load('current_th')
load('min_DR')
cd(code_folder)

for n_MU = 1:120
    n_MU
    
    current_th_d = current_th(n_MU)
    min_DR_d = min_DR(n_MU)
    
    cd(data_folder)
    load(['MN_' num2str(n_MU)])
    cd(code_folder)
    
    %%
    threshold = current_th(n_MU);
    amp_vec = -1e-3+threshold:0.01e-3:threshold+20e-3;
    
    %%
    tic
    
    mean_FR = zeros(1,length(amp_vec));
    CoV_FR = zeros(1,length(amp_vec));
    binary_cell = cell(1,length(amp_vec));
    Fs = 10000;
    time = 0:1/Fs:5;
    noise_amp = 0;
    parfor i = 1:length(amp_vec)
        
        amp = amp_vec(i);
        input  = zeros(1,length(time));
        input(1*Fs+1:end) = amp;
        
        inputOpt = 2;
        pltOpt = 0;
        %%
        [binary_temp,V_s,V_d] = Cisi2008_function_v2(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
        binary_cell{i} = binary_temp;
    end
    for n = 1:length(amp_vec)
        binary = binary_cell{n};
        spike_time = find(binary(end-2*Fs+1:end));
        ISI = diff(spike_time)/(Fs/1000);
        mean_FR(n) = mean(1./ISI*1000);
        CoV_FR(n) = std(1./ISI*1000)/mean_FR(n)*100;
    end
    %%
    index_t = find(~isnan(mean_FR));
    area_s = param.area_s;
    
    current_th_new = amp_vec(index_t(1))
    min_DR_new = mean_FR(index_t(1))
    p_fit = polyfit(amp_vec(index_t),mean_FR(index_t),1);    
    f_I_slope(n_MU = p_fit(1)*10^-3;
    y1 = polyval(p_fit,amp_vec(index_t));
    
    peak_DR = min_DR_new*4;
    [~,loc] = min(abs(mean_FR-peak_DR));
    current_peak_new = amp_vec(loc)
    current_peak(n_MU) = amp_vec(loc);
    
    figure(1)
    plot(amp_vec,mean_FR,'LineWidth',2)
    hold on
    plot(amp_vec(index_t),y1)
    plot([0 amp_vec(end)],[min_DR_new min_DR_new],'--k','LineWidth',1)
    plot([0 amp_vec(end)],[peak_DR peak_DR],'--k','LineWidth',1)
    xlabel('Injected Current (nA)','FontSize',14)
    ylabel('Dischage Rate (Hz)','FontSize',14)
    set(gca,'TickDir','out');
    set(gca,'box','off')
    
    toc

end

cd(data_folder)
save('current_peak','current_peak')
save('f_I_slope','f_I_slope')
cd(code_folder)