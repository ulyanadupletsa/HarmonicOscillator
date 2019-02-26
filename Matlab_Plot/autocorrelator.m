function autocorrelator 

gamma = dlmread('dataAutoCorr.txt','', [0 1 49 1]);



time = (1:50)';


g = fittype('a*exp(-b*x)');
f0 = fit(time,gamma,g,'StartPoint',[1, 0.26]);
xx = linspace(1,50,100);
plot(time,gamma,'*','Linewidth', 2);
hold on
p = plot(xx,f0(xx),'r-', 'Linewidth', 2);

set(gca, 'fontsize', 18);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.8, 0.6, 0.68]);
xlabel('k');
title('\fontsize{19} Autocorrelation Function');
xlabel('Markovian Time t');
ylabel('Autocorrelator');
legend('data','fit: y = (1.263 \pm 0.012)exp(-x/(3.800 \pm 0.043))');
print('autocorrelator', '-dpng');

end