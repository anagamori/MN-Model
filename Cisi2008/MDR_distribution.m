%==========================================================================
% MDR_distribution.m
% Author: Akira Nagamori
% Last update: 9/16/19
% Descriptions:
%   - Create a distribution of contraction times with a prespecified range
%   - Calculate f_half based on the relationship between contraction time and
%   f_half
%   - Calculate minimal discharge rate from f_half
%==========================================================================

close all
clear all
clc

code_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008';
data_folder = '/Users/akira/Documents/GitHub/MN-Model/Cisi2008/MN Parameter';

rng(1)
CT = round(raylrnd(25,1,120)+20);

figure(1)
histogram(CT)
xlabel('Contraction time (ms)')

ISI_half = CT*1.3/1000; % cat peroneus longus from Kernell et al. (1983)
% Also refer to Botterman et al. (1983)
f_half = 1./ISI_half;

figure(2)
histogram(f_half)
xlabel('f_{0.5} (Hz)')

MDR = f_half/2;
MDR = sort(MDR);

figure(3)
histogram(MDR)
xlabel('Minimum discharge rate (Hz)')

cd(data_folder)
save('MDR','MDR')
cd(code_folder)


