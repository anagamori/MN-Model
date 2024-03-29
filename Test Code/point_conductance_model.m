%==========================================================================
% point_conductance_model.m
% Author: Akira Nagamori
% Last update: 8/14/19
% Descriptions:
%   Equations obtained from Destexhe et al. (2001)
%==========================================================================

close all
clear all
clc

%%
Fs = 10000;
time = 0:1/Fs:20;
noise_amp = 5000;

E_e = 0;
E_i = -75;
g_e0 = 0.012;
g_e = 0;
g_i0 = 0.057;
g_i = 0;
tau_e = 0.0027;
tau_i = 0.0105;

V = -65;

I_syn_vec = zeros(1,length(time));
x_e = normrnd(0,1,[1,length(time)]);
x_i = normrnd(0,1,[1,length(time)]);

%% Izhikevich model
amp_vec = 10;
I_input = [zeros(1,1*Fs) amp_vec*[0:1/Fs:1] amp_vec*ones(1,length(time)-1*Fs-length(amp_vec*[0:1/Fs:1]))];
   
% I_input = zeros(1,length(time)); % applied current (microA/cm^2)
% I_input(0.5*Fs:end) = amp_vec;

parameter.a = 0.02; %; %0.02 %the time scale of the recovery variable. Smaller values result in slower recovery. %0.005 for 2.4573 Hz 
parameter.b = 0.2; %0.2 %the sensitivity of the recovery variableu to the subthreshold fluctuations of the membrane potential v. 
%Greater values couple v and u more strongly resulting in possible subthreshold oscillations and low-threshold spiking dynamics
parameter.c = -65; % -65 %the after-spike reset value of the membrane potential v caused by the fast high-threshold K+ conductances
parameter.d = 6; %8 %after-spike reset of the recovery variable u caused by slowhigh-threshold Na+ andK+ conductances
parameter.v = -65; %-65

parameter.alpha = 0.04;
parameter.beta = 5;
parameter.gamma = 140;

a = 0.02;
b = 0.2; %[0.2*ones(Ne,1); 0.25-0.05*ri];
c = -65; %[-65+15*re.^2; -65*ones(Ni,1)];
d = 6; %8; %[8-6*re.^2; 2*ones(Ni,1)];

alpha = 0.04;
beta = 5;
gamma = 140;

v = -65; %*ones(Ne+Ni,1); % Initial values of v
u = b.*v; % Initial values of u

binary = zeros(1,length(time));
v_vec = zeros(1,length(time));

%%
for t = 1:length(time)
    I_syn = g_e*(V-E_e) + g_i*(V-E_i);
    
    if v >= 30
        binary(t) = 1;
        v = c;
        u = u +d;
    end
    
    v_dot = (alpha*v.^2+beta*v+gamma-u-(I_syn));
    v = v_dot*1000/Fs + v;
    
    u_dot = a.*(b.*v-u);
    u = u_dot*1000/Fs + u;
    
    v_vec(t) = v;
    
    dg_e = -1/tau_e*(g_e-g_e0) + sqrt(noise_amp)*x_e(t);
    g_e = dg_e/Fs + g_e;
    
    dg_i = -1/tau_i*(g_i-g_e0) + sqrt(noise_amp)*x_i(t);
    g_i = dg_i/Fs + g_i;
    
    I_syn_vec(t) = I_syn;
end

figure(1)
ax1 =  subplot(2,1,1);
plot(time,I_syn_vec)
ax2 = subplot(2,1,2);
plot(time,v_vec)
linkaxes([ax1,ax2],'x')
set(gca,'TickDir','out');
set(gca,'box','off')
ax = gca;


spike_time = find(binary);
ISI = diff(spike_time)/(Fs/1000);
mean_FR = mean(1./ISI*1000)
CoV_FR = std(1./ISI*1000)/mean_FR*100

temp = ISI(1:end-1);
temp2 = ISI(2:end);
R = corrcoef(temp,temp2)

figure(2)
for i = 1:length(ISI)-1
    scatter(ISI(i),ISI(i+1),'b')
    hold on
end