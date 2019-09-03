close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Test Size';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/MN Parameter';

%%
model_folder = '/Users/akiranagamori/Documents/GitHub/Twitch-Based-Muscle-Model/Model Parameters/Model_8';
cd(model_folder)
load('modelParameter')
cd(code_folder)

[val,loc] = min(modelParameter.U_th);
testMN = loc;

MDR = modelParameter.MDR(testMN);
PDR = modelParameter.PDR(testMN);
%%
type = 'S';
nMN = '1';

cd(data_folder)
load([type '_' nMN])
cd(code_folder)

%%
amp_vec = 15:70;
for i = 1:length(amp_vec)
    i
    Fs = 10000;
    time = 0:1/Fs:5;
    noise_amp = 0;
    
    amp = amp_vec(i);
    input  = zeros(1,length(time));
    input(1*Fs+1:end) = amp;
    
    inputOpt = 1;
    pltOpt = 0;
    %%
    [binary,V_s,V_d] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
    
    spike_time = find(binary(end-2*Fs+1:end));
    ISI = diff(spike_time)/(Fs/1000);
    mean_FR(i) = mean(1./ISI*1000);
    CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;
end
%%
index_t = find(~isnan(mean_FR));
area_s = 2*pi*param.l_s*param.r_s;
current = amp_vec*area_s*10^3;

current_th = current(index_t(1))
min_DR = mean_FR(index_t(1))

figure(1)
plot(current,mean_FR,'LineWidth',2)
hold on
plot([min(current) max(current)],[MDR MDR],'--k','LineWidth',1)
plot([min(current) max(current)],[PDR PDR],'--k','LineWidth',1)
xlabel('Injected Current (nA)','FontSize',14)
ylabel('Dischage Rate (Hz)','FontSize',14)
set(gca,'TickDir','out');
set(gca,'box','off')
