%==========================================================================
% F_I_relationship.m
% Author: Akira Nagamori
% Last update: 6/26/19
% Descriptions:
%   Test the frequency-current relationship of Izhikevich model
%==========================================================================

%close all
clear all
clc

code_folder = '/Users/akira/Documents/Github/MN-Model';
model_parameter_folder =  '/Users/akira/Documents/Github/Twitch-Based-Muscle-Model/Model Parameters/Model_6';

%%
cd(model_parameter_folder)
load('modelParameter')
cd(code_folder)
MDR = modelParameter.FR_half/2;
PDR = modelParameter.FR_half*2;
U_th = modelParameter.U_th_new;
[val,loc] = min(U_th);
testUnit = loc;
%%
Fs = 30000;
time = 0:1/Fs:5;
noise_amp = 0;
%% Izhikevich Model parameters
parameter.a = 0.02; %0.02 %the time scale of the recovery variable. Smaller values result in slower recovery. %0.005 for 2.4573 Hz 
parameter.b = 0.2; %0.2 %the sensitivity of the recovery variableu to the subthreshold fluctuations of the membrane potential v. 
%Greater values couple v and u more strongly resulting in possible subthreshold oscillations and low-threshold spiking dynamics
parameter.c = -65; % -65 %the after-spike reset value of the membrane potential v caused by the fast high-threshold K+ conductances
parameter.d = 6; %8 %after-spike reset of the recovery variable u caused by slowhigh-threshold Na+ andK+ conductances
parameter.v = -65; %-65

parameter.alpha = 0.04;
parameter.beta = 5;
parameter.gamma = 140;

input_vec = 1:1:30; %[0.1:0.1:0.9 1:100];
for i = 1:length(input_vec)
    i
%% Input 
amp = input_vec(i);
input = [zeros(1,2*Fs),amp*ones(1,length(time)-2*Fs)];
%input = [zeros(1,1*Fs) amp/2*[0:1/Fs:2] amp*ones(1,length(time)-1*Fs-length(amp*[0:1/Fs:2]))];

tic
%% Run Izhikevich model
[v_vec,binary] = Izhikevich(time,input,parameter,Fs,noise_amp);

spike_time = find(binary(3*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR_Iz(i) = mean(1./ISI*1000);

%% Run Booth model
[binary,V_s,V_d] = Booth1997_function(time,input,Fs,noise_amp,0);
 
spike_time = find(binary(1*Fs+3:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR_Bo(i) = mean(1./ISI*1000);
toc
end

%%
figure(1)
plot(input_vec,mean_FR_Iz)
hold on
plot(input_vec,mean_FR_Bo)
legend('Izhikevich','Booth')
plot([0 40],[MDR(testUnit) MDR(testUnit)],'k')
plot([0 40],[PDR(testUnit) PDR(testUnit)],'k')

%%
input_vec_int = 1:0.01:30;
FR_Iz_int = spline(input_vec,mean_FR_Iz,input_vec_int);
[~,loc] = min(abs(FR_Iz_int-MDR(testUnit)));
I_th_Iz = input_vec_int(loc);
[~,loc] = min(abs(FR_Iz_int-PDR(testUnit)));
I_max_Iz = input_vec_int(loc);

%%
FR_Bo_int = spline(input_vec,mean_FR_Bo,input_vec_int);
[~,loc] = min(abs(FR_Bo_int-MDR(testUnit)));
I_th_Bo = input_vec_int(loc);
[~,loc] = min(abs(FR_Bo_int-PDR(testUnit)));
I_max_Bo = input_vec_int(loc);

%%
noise_amp = 200000;
noise_vec = zeros(1,length(time));
x = 0;
tau = 0.005;
for i = 1:length(time)
chi = normrnd(0,1,[1,1]);
x_dot = -x/tau + sqrt(noise_amp)*chi;
x = x_dot*1/Fs + x;
noise_vec(i) = x;
end
%%
noise_amp = 0;
amp = 0.5;
input = [zeros(1,2*Fs),amp*ones(1,length(time)-2*Fs)];
input = input + input.*noise_vec;
I = (I_max_Iz-I_th_Iz)/(1-U_th(testUnit))*(input-U_th(testUnit)) + I_th_Iz;

[v_vec,binary] = Izhikevich(time,I,parameter,Fs,noise_amp);

spike_time = find(binary(3*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR_Iz_temp = mean(1./ISI*1000)
CoV_FR_Iz_temp = std(1./ISI*1000)/mean_FR_Iz_temp*100

%%
I = (I_max_Bo-I_th_Bo)/(1-U_th(testUnit))*(input-U_th(testUnit)) + I_th_Bo;

[binary,V_s,V_d] = Booth1997_function(time,I,Fs,noise_amp,0);

spike_time = find(binary(3*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR_Bo_temp = mean(1./ISI*1000)
CoV_FR_Bo_temp = std(1./ISI*1000)/mean_FR_Bo_temp*100
