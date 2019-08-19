%==========================================================================
% comparison_MNs.m
% Author: Akira Nagamori
% Last update: 8/19/19
% Descriptions:
%   Compare the temporal discharge patterns of different MN models
%==========================================================================

close all
clear all
clc

%%
Fs = 30000;
time = 0:1/Fs:5;
noise_amp = 50000;

amp_vec = 10;
I_input = zeros(1,length(time)); % applied current (microA/cm^2)
I_input(0.5*Fs:end) = amp_vec;

%% Test Izhikevich
parameter.a = 0.02; %; %0.02 %the time scale of the recovery variable. Smaller values result in slower recovery. %0.005 for 2.4573 Hz
parameter.b = 0.2; %0.2 %the sensitivity of the recovery variableu to the subthreshold fluctuations of the membrane potential v.
%Greater values couple v and u more strongly resulting in possible subthreshold oscillations and low-threshold spiking dynamics
parameter.c = -65; % -65 %the after-spike reset value of the membrane potential v caused by the fast high-threshold K+ conductances
parameter.d = 6; %8 %after-spike reset of the recovery variable u caused by slowhigh-threshold Na+ andK+ conductances
parameter.v = -65; %-65

parameter.alpha = 0.04;
parameter.beta = 5;
parameter.gamma = 140;

[v_vec,binary_I] = Izhikevich(time,I_input,parameter,Fs,noise_amp);

figure(11)
plot(time,v_vec,'LineWidth',1,'Color','k')
hold on
plot(time,binary_I*50,'LineWidth',1,'Color','b')
xlabel('Time (s)')
ylabel({'Membrane potential';'(mV)'})
set(gca,'TickDir','out');
set(gca,'box','off')
ax = gca;

spike_time_I = find(binary_I(1*Fs+1:end));
ISI_I = diff(spike_time_I)/(Fs/1000);
mean_FR_I = mean(1./ISI_I*1000)
CoV_FR_I = std(1./ISI_I*1000)/mean_FR_I*100

%% Test Booth_1997
[binary_B,V_s,V_d] = Booth1997_function(time,I_input,Fs,noise_amp,0);

spike_time_B = find(binary_B(1*Fs+3:end));
ISI_B = diff(spike_time_B)/(Fs/1000);
mean_FR_B = mean(1./ISI_B*1000)
CoV_FR_B = std(1./ISI_B*1000)/mean_FR_B*100

%% Test Fuglevand
[binary_F] = Fuglevand(time,mean_FR,CoV_FR,Fs);

spike_time_F = find(binary_F(1*Fs+1:end));
ISI_F = diff(spike_time_F)/(Fs/1000);
mean_FR_F = mean(1./ISI_F*1000)
CoV_FR_F = std(1./ISI_F*1000)/mean_FR_F*100

%%
figure(1)
histogram(ISI_I-mean(ISI_I))
hold on 
histogram(ISI_B-mean(ISI_B))
histogram(ISI_F-mean(ISI_F))
legend('Izhikevich','Booth','Fuglevnad')

%%
[r_I,lags] = xcorr(binary_I(1*Fs+1:end)-mean(binary_I(1*Fs+1:end)),Fs,'coeff');
[r_B,~] = xcorr(binary_B(1*Fs+1:end)-mean(binary_B(1*Fs+1:end)),Fs,'coeff');
[r_F,~] = xcorr(binary_F(1*Fs+1:end)-mean(binary_F(1*Fs+1:end)),Fs,'coeff');
figure(2)
plot(lags(Fs+1:end)*1000/Fs,r_I(Fs+1:end))
hold on 
plot(lags(Fs+1:end)*1000/Fs,r_B(Fs+1:end))
plot(lags(Fs+1:end)*1000/Fs,r_F(Fs+1:end))
legend('Izhikevich','Booth','Fuglevnad')