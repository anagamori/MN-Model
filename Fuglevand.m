%%
function [binary] = Fuglevand(time,target_FR,target_CV,Fs)

Input = zeros(1,length(time)); 
Input(0.5*Fs:end) = target_FR;

MFR = 8;
PFR = 35;
binary = zeros(1,length(time));
FR_mat = zeros(1,length(time));
spike_time = 0;
cv = target_CV/100;

for t = 1:length(time)
    if t > 1
        FR = Input(t);
        FR_mat(t) = FR;
        FR(FR<MFR) = 0;
 
        index_1 = FR >= MFR & FR_mat(t-1) == 0;
        index_2 = FR >= MFR & spike_time == t;
        index = [index_1 index_2];
 
        for j = 1:length(index)          
            if FR >= PFR
                FR = PFR;              
            end
            if ~any(binary) % initial time
                binary(t) = 1;

                mu = 1/FR;
                Z = randn(1);
                Z(Z>3.9) = 3.9;
                Z(Z<-3.9) = -3.9;
                spike_time_temp = (mu + mu*cv*Z)*Fs;
                spike_time = round(spike_time_temp) + t; 
            else
                if spike_time == t
                    binary(t) = 1;

                    mu = 1/FR;
                    Z = randn(1);
                    Z(Z>3.9) = 3.9;
                    Z(Z<-3.9) = -3.9;
                    spike_time_temp = (mu + mu*cv*Z)*Fs;
                    spike_time = round(spike_time_temp) + t;
                    
   
                elseif FR_mat(t-1) == 0
                    binary(t) = 1;
                    mu = 1/FR;
                    Z = randn(1);
                    Z(Z>3.9) = 3.9;
                    Z(Z<-3.9) = -3.9;
                    spike_time_temp = (mu + mu*cv*Z)*Fs;
                    spike_time = round(spike_time_temp) + t;                   
                end
            end           
        end
    end    
end

end