function sigma

error1 = dlmread('energyData3.txt','', [0 1 2 1]);
error2 = dlmread('energyData3.txt','', [0 1 5 1]);
error3 = dlmread('energyData3.txt','', [0 1 8 1]);

t1 = 1:3;
t2 = 1:6;
t3 = 1:9;

plot(t1, error1, 'linewidth', 2);
hold on 
plot(t2, error2, 'linewidth', 2);
plot(t3, error3, 'linewidth', 2);

set(gca, 'fontsize', 18);
xlabel('Time t');
ylabel('error');
title('Error bars');

legend('Nconf=10ˆ4', 'Nconf=10ˆ6', 'Nconf=10ˆ8');
