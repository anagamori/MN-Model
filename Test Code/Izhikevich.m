%==========================================================================
% Izhikevich_2003.m
% Author: Akira Nagamori
% Last update: 6/18/19
% Reference:
%   Izhikevich 2003
%==========================================================================


function [v_vec,binary] = Izhikevich(time,input,parameter,Fs,noise_amp)

%%
I = input;
%% Model parameters
a = parameter.a; %0.005; %[0.02*ones(Ne,1); 0.02+0.08*ri];
b = parameter.b; %0.2; %[0.2*ones(Ne,1); 0.25-0.05*ri];
c = parameter.c; %-65; %[-65+15*re.^2; -65*ones(Ni,1)];
d = parameter.d; %8; %[8-6*re.^2; 2*ones(Ni,1)];

alpha = parameter.alpha; % 0.04
beta = parameter.beta; % 5
gamma = parameter.gamma; % 140

%% Initial Conditions
v = parameter.v; %-65; %*ones(Ne+Ni,1); % Initial values of v
u = b.*v; % Initial values of u

%%
chi = normrnd(0,1,[1,length(time)]);
%%
x_noise = 0;
binary = zeros(1,length(time));
v_vec = zeros(1,length(time));
for t = 1:length(time)
    [x_noise] = noise(x_noise,noise_amp,chi(t),Fs);
    I_app = I(t) + I(t)*x_noise; 
    if v >= 30
        binary(t) = 1;
        v = c;
        u = u +d;
    end
    
    v_dot = (alpha*v.^2+beta*v+gamma-u+I_app);
    v = v_dot*1000/Fs + v;
    
    u_dot = a.*(b.*v-u);
    u = u_dot*1000/Fs + u;
    
    v_vec(t) = v;
end

    function [x] = noise(x,D,chi,Fs)
        tau = 0.005;
        x_dot = -x/tau + sqrt(D)*chi;
        x = x_dot*1/Fs + x;
    end
end
