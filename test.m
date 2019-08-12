v = 100; xo = 0; g_K = 35;
     [t,x] = ode23s(@dXdT_n,[0 12],xo,[],v);
     g = g_K*(x(:,1).^4);
     plot(t,g)
     xlabel('t (ms)');
     ylabel('g_{K}');
     set(gca,'fontsize',16)


function [f] = dXdT_n(~,n,v)
     % FUNCTION dXdT_N
     %  Inputs: t - time (milliseconds)
     %          x - vector of state variables {n}
     %          V - applied voltage (mV)
     %
     %  Outputs: f - vector of time derivatives
% {dn/dt}
% alphas and betas:
     a_n = 0.01*(10-v)./(exp((10-v)/10)-1);
     b_n = 0.125*exp(-v/80);
     % Computing derivative dn/dt:
     f(1,:) = a_n*(1-n) - b_n*n;
     
end