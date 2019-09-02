%==========================================================================
% CoV_vs_rate.m
% Author: Akira Nagamori
% Last update: 8/27/19
% Descriptions:
%   Equations obtained from Destexhe et al. (2001)
%==========================================================================

close all
clear all
clc

%%
Fs = 30000;
time = 0:1/Fs:10;
noise_amp = 50000;
amp_vec = [3.7:0.1:15];
for i = 1:length(amp_vec)
    amp = amp_vec(i);
    I_input = [zeros(1,1*Fs) amp*[0:1/Fs:1] amp*ones(1,length(time)-1*Fs-length(amp*[0:1/Fs:1]))];
    
    % I_input = zeros(1,length(time)); % applied current (microA/cm^2)
    % I_input(0.5*Fs:end) = amp_vec;
    
    parameter.a = 0.02; %; %0.02 %the time scale of the recovery variable. Smaller values result in slower recovery. %0.005 for 2.4573 Hz
    parameter.b = 0.2; %0.2 %the sensitivity of the recovery variableu to the subthreshold fluctuations of the membrane potential v.
    %Greater values couple v and u more strongly resulting in possible subthreshold oscillations and low-threshold spiking dynamics
    parameter.c = -65; % -65 %the after-spike reset value of the membrane potential v caused by the fast high-threshold K+ conductances
    parameter.d = 6; %8 %after-spike reset of the recovery variable u caused by slowhigh-threshold Na+ andK+ conductances
    parameter.v = -65; %-65
    
    parameter.alpha = 0.04;
    parameter.beta = 5;
    parameter.gamma = 140;
    
    [v_vec,binary] = Izhikevich(time,I_input,parameter,Fs,noise_amp);
    
    spike_time = find(binary(end-2*Fs+1:end));
    ISI = diff(spike_time)/(Fs/1000);
    
    mean_ISI(i) = mean(ISI);
    std_ISI(i) = std(ISI);
    
    mean_FR(i) = mean(1./ISI*1000);
    CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;
    
    temp = ISI(1:end-1);
    temp2 = ISI(2:end);
    [R,P] = corrcoef(temp,temp2);
    r_vec(i) = R(1,2);
    p_vec(i) = P(1,2);
end

%%
figure(1)
ax1 = subplot(2,1,1);
scatter(mean_ISI,std_ISI,'k')
xlabel('ISI (ms)','FontSize',14)
ylabel('CoV ISI','FontSize',14)
set(gca,'TickDir','out');
set(gca,'box','off')
ax = gca;
ax2 = subplot(2,1,2);
scatter(mean_ISI,r_vec,'k')
xlabel('ISI (ms)','FontSize',14)
ylabel('Correlation','FontSize',14)
set(gca,'TickDir','out');
set(gca,'box','off')
ax = gca;

%%
close all
Fs = 30000;
time = 0:1/Fs:50;
noise_amp = 50000;
amp_vec = [4.1 8];
for i = 1:length(amp_vec)
    amp = amp_vec(i);
    I_input = [zeros(1,1*Fs) amp*[0:1/Fs:1] amp*ones(1,length(time)-1*Fs-length(amp*[0:1/Fs:1]))];
    
    % I_input = zeros(1,length(time)); % applied current (microA/cm^2)
    % I_input(0.5*Fs:end) = amp_vec;
    
    parameter.a = 0.02; %; %0.02 %the time scale of the recovery variable. Smaller values result in slower recovery. %0.005 for 2.4573 Hz
    parameter.b = 0.2; %0.2 %the sensitivity of the recovery variableu to the subthreshold fluctuations of the membrane potential v.
    %Greater values couple v and u more strongly resulting in possible subthreshold oscillations and low-threshold spiking dynamics
    parameter.c = -65; % -65 %the after-spike reset value of the membrane potential v caused by the fast high-threshold K+ conductances
    parameter.d = 6; %8 %after-spike reset of the recovery variable u caused by slowhigh-threshold Na+ andK+ conductances
    parameter.v = -65; %-65
    
    parameter.alpha = 0.04;
    parameter.beta = 5;
    parameter.gamma = 140;
    
    [v_vec,binary] = Izhikevich(time,I_input,parameter,Fs,noise_amp);
    
    spike_time = find(binary(end-2*Fs+1:end));
    ISI = diff(spike_time)/(Fs/1000);
    
    figure(2)
    histogram(ISI,10,'Normalization','probability')
    hold on
end
