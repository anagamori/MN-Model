close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Test Size';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/MN Parameter';

%%
type = 'S';
nMN = '11';

cd(data_folder)
load([type '_' nMN])
cd(code_folder)
%%
Fs = 10000;
time = 0:1/Fs:5;
noise_amp = 0;

%% Test input resistance 
% Methods (Zengel et al. 1985)
amp_vec = 0.001/(2*pi*param.l_s*param.r_s);
input  = zeros(1,length(time));
input(1*Fs+1:1.2*Fs) = amp_vec;

inputOpt = 1;
pltOpt = 1;

[binary,V_s,~] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);

V_s_ss = mean(V_s(round(1.14*Fs):round(1.2*Fs)));
R_input_s = V_s_ss/0.001

%% Test AHP duration and magnitude
amp_vec = 21.3;
input  = zeros(1,length(time));
input(1*Fs+1:1.2*Fs) = amp_vec;

[binary,V_s,~] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);

spike_time = find(binary);
V_base = V_s(spike_time(1)-1);
[~,loc] = min(abs(V_s(spike_time(1):spike_time(2))-V_base));
V_return = V_s(spike_time(1)+loc);
AHP_duration = loc/(Fs/1000)
AHP_mag = min(V_s(spike_time(1):spike_time(2)))-V_base

%%
amp_vec = 22;
input  = zeros(1,length(time));
input(1*Fs+1:1.2*Fs) = amp_vec;
[binary,V_s,~] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
%%
V_temp = V_s(1.2*Fs+1:1.5*Fs);
V_temp = V_temp';
time_temp = 1/(Fs/1000):1/(Fs/1000):length(V_temp)/(Fs/1000);
time_temp = time_temp';

f = polyfit(time_temp,log(V_temp),1);
tau = 1/abs(f(1))
