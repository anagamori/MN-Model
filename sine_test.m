close all
clear all
clc

%%
Fs = 30000;
time = 0:1/Fs:5;
noise_amp = 0; %100000;

%% Test Izhikevich
amp_vec = 10;
I_input = [zeros(1,1*Fs) amp_vec*[0:1/Fs:1] amp_vec*ones(1,length(time)-1*Fs-length(amp_vec*[0:1/Fs:1]))];
sine_wave = 1*sin(2*pi*5*[0:1/Fs:3]);  
I_input(end-length(sine_wave)+1:end) = I_input(end-length(sine_wave)+1:end) + sine_wave;
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

figure(11)
plot(time,v_vec,'LineWidth',1,'Color','k')
hold on 
plot(time,binary*50,'LineWidth',1,'Color','b')
xlabel('Time (s)')
ylabel({'Membrane potential';'(mV)'})
set(gca,'TickDir','out');
set(gca,'box','off')
ax = gca;

spike_time = find(binary(1*Fs+3:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR*100

%% Test Booth_1997
clear binary

[binary,V_s,V_d] = Booth1997_function(time,I_input,Fs,noise_amp,1);
 
spike_time = find(binary(1*Fs+3:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR*100
