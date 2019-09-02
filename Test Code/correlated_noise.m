%==========================================================================
% correlated_noise.m
% Author: Akira Nagamori
% Last update: 8/27/19
% Descriptions:
%   Equations obtained from Destexhe et al. (2001)
%==========================================================================

close all
clear all
clc

%%
Fs = 10000;
time = 0:1/Fs:3;
noise_amp = 4000;
n_elem = 2000;
I_e = zeros(n_elem,1);
I_i = zeros(n_elem,1);
tau_e = 0.0027;
tau_i = 0.0105;

V = -65;

I_syn_vec = zeros(1,length(time));

sine = 0.003*sin(2*pi*1*time);

x_e = normrnd(0,1,[n_elem,length(time)]);
x_i = normrnd(0,1,[n_elem,length(time)]);

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
    I_syn = sum(I_e); % + sum(I_i); %*(V-E_e) + g_i*(V-E_i);
    
    if v >= 30
        binary(t) = 1;
        v = c;
        u = u +d;
    end
    
    v_dot = (alpha*v.^2+beta*v+gamma-u+I_syn);
    v = v_dot*1000/Fs + v;
    
    u_dot = a.*(b.*v-u);
    u = u_dot*1000/Fs + u;
    
    v_vec(t) = v;
    
    dI_e = -1/tau_e*I_e + sqrt(noise_amp)*x_e(:,t);
    I_e = dI_e/Fs + I_e;
    
    dI_i = -1/tau_i*I_i + sqrt(noise_amp)*x_i(:,t);
    I_i = dI_i/Fs + I_i;
        
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
