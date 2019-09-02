close all
clear all
clc

%%
Fs = 30000;
time = 0:1/Fs:10;
noise_amp = 50000;

%% Test Izhikevich
amp_vec = 5;
I_input = [zeros(1,1*Fs) amp_vec*[0:1/Fs:1] amp_vec*ones(1,length(time)-1*Fs-length(amp_vec*[0:1/Fs:1]))];
   
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
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR*100

temp = ISI(1:end-1);
temp2 = ISI(2:end);
[R,P] = corrcoef(temp,temp2)

figure(1)
for i = 1:length(ISI)-1
    scatter(ISI(i),ISI(i+1),'b')
    hold on
end
%% Test Booth_1997
clear binary

[binary,V_s,V_d] = Booth1997_function(time,I_input,Fs,noise_amp,0);
 
spike_time = find(binary(end-2*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR*100

temp = ISI(1:end-1);
temp2 = ISI(2:end);
[R,P] = corrcoef(temp,temp2)

figure(1)
for i = 1:length(ISI)-1
    scatter(ISI(i),ISI(i+1),'r+')
    hold on
end