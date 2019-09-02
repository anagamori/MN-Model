close all
clear all
clc

%%
Fs = 100000;
time = 0:1/Fs:3;

m = 0;
h = 1;
n = 0;
q = 0;

V_s = 70;

m_vec = zeros(1,length(time));
h_vec = zeros(1,length(time));
n_vec = zeros(1,length(time));
q_vec = zeros(1,length(time));

for t = 1:length(time)
    m = m_function(m,V_s,Fs);
    h = h_function(h,V_s,Fs);
    n = n_function(n,V_s,Fs);
    q = q_function(q,V_s,Fs);
    
    m_vec(t) = m;
    h_vec(t) = h;
    n_vec(t) = n;
    q_vec(t) = q;
    
end

figure(1)
plot(time,m_vec)
hold on
plot(time,h_vec)
hold on
plot(time,n_vec)
plot(time,q_vec)
xlabel('Time (s)')
legend('m','h','n','q')
title('Soma state variables')

function m = m_function(m,V,Fs)
alpha = 0.32*(13.1 - V)/(exp((13.1-V)/4)-1);
beta = 0.28*(V - 40.1)/(exp((V - 40.1)/5)-1);
dm = alpha*1000*(1-m) - beta*1000*m;
m = dm/Fs + m;
end

function h = h_function(h,V,Fs)
alpha = 0.128*exp((17-V)/18);
beta = 4/(1+exp((40-V)/5));
dh = alpha*1000*(1-h) - beta*1000*h;
h = dh/Fs + h;
end

function n = n_function(n,V,Fs)
alpha = 0.016*(35.1 - V)/(exp((35.1-V)/5)-1);
beta = 0.25*exp((20-V)/40);
dn = alpha*1000*(1-n) - beta*1000*n;
n = dn/Fs + n;
end

function q = q_function(q,V,Fs)
alpha = 0.32*(13.1 - V)/(exp((13.1-V)/4)-1);
beta = 0.28*(V - 40.1)/(exp((V - 40.1)/5)-1);
dq = alpha*1000*(1-q) - beta*1000*q;
q = dq/Fs + q;
end
