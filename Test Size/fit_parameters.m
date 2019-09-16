close all
clear all
clc

%%
code_folder = '/Users/akira/Documents/GitHub/MN-Model/Test Size';
data_folder = '/Users/akira/Documents/GitHub/MN-Model/MN Parameter';

%%
type = 'S';
%%
model_folder = '/Users/akira/Documents/GitHub/Twitch-Based-Muscle-Model/Model Parameters/Model_8';
cd(model_folder)
load('modelParameter')
cd(code_folder)

[val,loc] = min(modelParameter.U_th);
testMN = loc;

MDR_d = modelParameter.MDR(testMN);
PDR_d = modelParameter.PDR(testMN);

I_max = 100;
I_th = 100*val;
slope_target = (PDR_d-MDR_d)/(I_max-I_th);

%%
% find a template MN whose minimal discharge rate is closest to the target
% minimal discharge rate
cd(data_folder)
load([type '_MDR'])
cd(code_folder)

[~,loc_min] = min(abs(MDR_d-MDR));
nMN = num2str(11);

cd(data_folder)
load([type '_' nMN])
cd(code_folder)

%%
count = 1;
perturbation_amp = 0.3;

%%
% Fit the sloe of the f-I relationship by adjusting parameter g_Ks
for j = 1:5
    
    j
    amp_vec = 0:1:100;
    mean_FR = zeros(1,length(amp_vec));
    CoV_FR = zeros(1,length(amp_vec));
    
    for i = 1:length(amp_vec)
        
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
    
    amp_th = amp_vec(index_t(1));
    min_DR = mean_FR(index_t(1));
    
    p_fit = polyfit(amp_vec(index_t),mean_FR(index_t),1);
    y1 = polyval(p_fit,amp_vec(index_t));
    
    error = slope_target - p_fit(1);
    
    if error > 0
        param.g_Ks = param.g_Ks - (param.g_Ks*perturbation_amp)./2.^(count-2);
    else
        param.g_Ks = param.g_Ks + (param.g_Ks*perturbation_amp)./2.^(count-2);
    end
    count = count + 1;
    
end

% %%
% % Fit the recruitment threshold by adjusting parameter I_r
% mean_FR = zeros(1,length(amp_vec));
% CoV_FR = zeros(1,length(amp_vec));
% perturbation_amp = 0.3;
% count = 1;
% for j = 1:5
%     
%     j
%     
%     amp_vec = 0:0.1:50;
%     mean_FR = zeros(1,length(amp_vec));
%     CoV_FR = zeros(1,length(amp_vec));
%     
%     error = I_th - amp_th;
%     
%     if error > 0
%         param.I_r = param.I_r + (param.I_r*perturbation_amp)./2.^(count-2);
%     else
%         param.I_r = param.I_r - (param.I_r*perturbation_amp)./2.^(count-2);
%     end
%     
%     for i = 1:length(amp_vec)
%         
%         Fs = 10000;
%         time = 0:1/Fs:5;
%         noise_amp = 0;
%         
%         amp = amp_vec(i);
%         input  = zeros(1,length(time));
%         input(1*Fs+1:end) = amp;
%         
%         inputOpt = 1;
%         pltOpt = 0;
%         
%         [binary,V_s,V_d] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
%         
%         spike_time = find(binary(end-2*Fs+1:end));
%         ISI = diff(spike_time)/(Fs/1000);
%         mean_FR(i) = mean(1./ISI*1000);
%         CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;
%     end
%     
%     
%     
%     index_t = find(~isnan(mean_FR));
%     
%     amp_th = amp_vec(index_t(1));
%     min_DR = mean_FR(index_t(1));
%     
%     p_fit = polyfit(amp_vec(index_t),mean_FR(index_t),1);
%     y1 = polyval(p_fit,amp_vec(index_t));
%     
%     count = count + 1;
%     
% end
% 

%% Plot the result
amp_vec = 0:0.1:100;
mean_FR = zeros(1,length(amp_vec));
CoV_FR = zeros(1,length(amp_vec));
for i = 1:length(amp_vec)
    
    Fs = 10000;
    time = 0:1/Fs:5;
    noise_amp = 0;
    
    amp = amp_vec(i);
    input  = zeros(1,length(time));
    input(1*Fs+1:end) = amp;
    
    inputOpt = 1;
    pltOpt = 0;
    
    [binary,V_s,V_d] = Cisi2008_function(param,time,input,Fs,noise_amp,inputOpt,pltOpt);
    
    spike_time = find(binary(end-2*Fs+1:end));
    ISI = diff(spike_time)/(Fs/1000);
    mean_FR(i) = mean(1./ISI*1000);
    CoV_FR(i) = std(1./ISI*1000)/mean_FR(i)*100;
end



index_t = find(~isnan(mean_FR));

amp_th = amp_vec(index_t(1));
min_DR = mean_FR(index_t(1));
p_fit = polyfit(amp_vec(index_t),mean_FR(index_t),1);
y1 = polyval(p_fit,amp_vec(index_t));
figure(1)
plot(amp_vec,mean_FR,'LineWidth',2)
hold on
plot(amp_vec(index_t),y1,'--k','LineWidth',1)
plot([min(amp_vec) max(amp_vec)],[MDR_d MDR_d],'--k','LineWidth',1)
plot([min(amp_vec) max(amp_vec)],[PDR_d PDR_d],'--k','LineWidth',1)
xlabel('Injected Current (nA)','FontSize',14)
ylabel('Dischage Rate (Hz)','FontSize',14)
set(gca,'TickDir','out');
set(gca,'box','off')
