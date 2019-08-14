close all
clear all
clc

%%
Fs = 50000;
step = 1/Fs;
time = 0:1/Fs:2;
I_input = zeros(1,length(time)); % applied current (microA/cm^2)

I_input(0.5*Fs:end) = 6;

 [binary,V_s,V_d] = Booth1997_function(time,I_input,Fs,0);
 
spike_time = find(binary(1*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR