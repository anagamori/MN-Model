close all
clear all
clc

%%
Fs = 30000;
step = 1/Fs;
time = 0:1/Fs:5;

I_amp = 10; %3:0.1:30;

for i = 1:length(I_amp)
I_input = zeros(1,length(time)); % applied current (microA/cm^2)
I_input(1*Fs:3*Fs) = I_amp(i);

noise_amp = 0; %100000;

%%
[binary,V_s,V_d] = Booth1997_function(time,I_input,Fs,noise_amp,1);
 
spike_time = find(binary(1*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR(i) = mean(1./ISI*1000);
CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;

end

% figure(11)
% plot(I_amp,mean_FR)