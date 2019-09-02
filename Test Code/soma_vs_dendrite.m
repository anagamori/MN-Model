close all
clear all
clc

%%
Fs = 30000;
time = 0:1/Fs:10;
noise_amp = 50000;


%% Somatic input
amp_vec = 10;
I_input = [zeros(1,1*Fs) amp_vec*[0:1/Fs:1] amp_vec*ones(1,length(time)-1*Fs-length(amp_vec*[0:1/Fs:1]))];

[binary,~,~] = Booth1997_function(time,I_input,Fs,noise_amp,1,0);
 
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
%% Dendritic input
clear binary

amp_vec = 3;
I_input = [zeros(1,1*Fs) amp_vec*[0:1/Fs:1] amp_vec*ones(1,length(time)-1*Fs-length(amp_vec*[0:1/Fs:1]))];


[binary,V_s,V_d] = Booth1997_function(time,I_input,Fs,noise_amp,2,0);
 
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