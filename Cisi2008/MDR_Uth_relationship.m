%==========================================================================
% MDR_Uth_relationship.m
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

cd(data_folder)
load('MDR')
load('modelParameter')
cd(code_folder)

[~,index] = min(modelParameter.U_th);
MDR(index)


