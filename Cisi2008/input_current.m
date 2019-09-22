%==========================================================================
% input_current.m
% Author: Akira Nagamori
% Last update: 9/21/19
% Descriptions:
%   -  Compute the slope and intercept of linear function that converts
%   synaptic input (0-1) into effective current (nA)
%==========================================================================

close all
clear all
clc

%%
code_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akiranagamori/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

cd(data_folder)
load('modelParameter')
load('current_th')
load('current_peak')
cd(code_folder)

N_MU = modelParameter.N_MU;
[U_th_sort,idx] = sort(modelParameter.U_th);

U_vec = 0:0.01:1;

for n = 1 %:N_MU
    U_th =  U_th_sort(n);
    I_min = current_th(n);
    I_max = current_peak(n);
    I_eff = (I_max-I_min)./(1-U_th).*(U_vec-U_th) + I_min;
    
    figure(1)
    plot(U_vec,I_eff,'LineWidth',2)
    hold on
    plot([0 U_vec(end)],[I_min I_min],'--k','LineWidth',1)
    plot([0 U_vec(end)],[I_max I_max],'--k','LineWidth',1)
    xlabel('Synaptic Input','FontSize',14)
    ylabel('Effective Current (nA)','FontSize',14)
    set(gca,'TickDir','out');
    set(gca,'box','off')
end