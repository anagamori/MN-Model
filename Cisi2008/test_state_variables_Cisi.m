close all
clear all
clc

param.alpha_m = 22*1000;
param.beta_m = 13*1000;
param.alpha_h = 0.5*1000;
param.beta_h = 4*1000;
param.alpha_n = 1.5*1000;
param.beta_n = 0.1*1000;
param.alpha_q = 1.5*1000;
param.beta_q = 0.025*1000;

Fs = 50000;
time = 0:1/Fs:0.05;
index_s = zeros(1,length(time));
index_s(0.01*Fs:0.01*Fs+round(0.0006*Fs)) = 1;
index_s(0.02*Fs:0.02*Fs+round(0.0006*Fs)) = 1;

m = 0;
h = 1;
n = 0;
q = 0;

m_0 = 0;
h_0 = 1;
n_0 = 0;
q_0 = 0;

t_0_end = 0;
t_0_start = 0.01;
spike_index = 0;
for t = 1:length(time)
    if t > 1
        if index_s(t) == 1 && index_s(t-1) == 0
            t_0_start = t/Fs;
            t_0_end = (t+round(0.0006*Fs))/Fs;
            spike_index = spike_index + 1;
            m_0 = m;
            h_0 = h;
            n_0 = n;
            q_0 = q;
        elseif index_s(t) == 0 && index_s(t-1) == 1
            m_0 = m;
            h_0 = h;
            n_0 = n;
            q_0 = q;
        end
        if index_s(t) == 1
            T = t/Fs;
            m = 1 + (m_0-1)*exp(-param.alpha_m*(T-t_0_start));
            h = h_0*exp(-param.beta_h*(T-t_0_start));
            n = 1 + (n_0-1)*exp(-param.alpha_n*(T-t_0_start));
            q = 1 + (q_0-1)*exp(-param.alpha_q*(T-t_0_start));
        elseif index_s(t) == 0 
            T = t/Fs;
            m = m_0*exp(-param.beta_m*(T-t_0_end));
            h = 1 + (h_0-1)*exp(-param.alpha_h*(T-t_0_end));
            n = n_0*exp(-param.beta_n*(T-t_0_end));
            q = q_0*exp(-param.beta_q*(T-t_0_end));
        end
    end
    m_vec(t) = m;
    h_vec(t) = h;
    n_vec(t) = n;
    q_vec(t) = q;
end
figure(1)
ax1 = subplot(4,1,1);
plot(time,m_vec,'LineWidth',1)
hold on
plot(time,index_s,'--k')
ax2 = subplot(4,1,2);
plot(time,h_vec,'LineWidth',1)
hold on
plot(time,index_s,'--k')
ax3 = subplot(4,1,3);
plot(time,n_vec,'LineWidth',1)
hold on
plot(time,index_s,'--k')
ax4 = subplot(4,1,4);
plot(time,q_vec,'LineWidth',1)
hold on
plot(time,index_s,'--k')
linkaxes([ax1,ax2,ax3,ax4],'x')
