close all
clear all
clc

code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

cd(data_folder)
load('mn_parameter')

cd(code_folder)

Fs = 10000;
time = 0:1/Fs:5;
noise_amp = 0;
amp = 0.1;
U_syn  = zeros(1,length(time));
U_syn(1*Fs+1:end) = amp;

inputOpt = 2;

[binary,V_s_mat,V_d_mat] = MN_model_population(mn_parameter,time,U_syn,Fs,noise_amp,inputOpt);

%%
test_unit = 1;
figure(1)
plot(time,V_s_mat(test_unit,:))

spike_time = find(binary(test_unit,end-2*Fs+1:end));
ISI = diff(spike_time)/(Fs/1000);
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR*100

%%
binary_log = logical(binary);
plotSpikeRaster(binary_log,'PlotType','vertline');