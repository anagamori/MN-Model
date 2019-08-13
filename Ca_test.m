
I_Ca = -g_Ca_N*m_N_s_vec.^2.*h_N_s_vec.*(V_s-V_Ca);

f = 0.01;
alpha = 0.9*1000;
k_Ca = 2*1000;
Ca = 0;

K_d = 0.2; %(microM)
g_K_Ca = 5; %(mS/cm^2)

Ca_vec = zeros(1,length(time));
for t = 1:length(time)
    dCa = f*(-alpha*I_Ca(t)-k_Ca*Ca);
    Ca = Ca+dCa/Fs;
    Ca_vec(t) = Ca;
end

I_K_Ca = g_K_Ca*(Ca_vec./(Ca_vec+K_d)).*(V_s-V_K);

figure(1)
plot(time,Ca_vec)

figure(2)
plot(time,I_K_Ca)