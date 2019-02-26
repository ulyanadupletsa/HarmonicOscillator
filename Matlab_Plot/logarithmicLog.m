function logarithmicLog

corrValue1 = dlmread('dataCorrMeanN4.txt','', [0 0 63 0]);
corrValue2 = dlmread('dataCorrMeanN5.txt','', [0 0 63 0]);
corrValue3 = dlmread('dataCorrMeanN6.txt','', [0 0 63 0]);
corrValue4 = dlmread('dataCorrMeanN7.txt','', [0 0 63 0]);

t = 1:64;

semilogy(t, abs(corrValue1), 'b', 'linewidth', 2, 'Marker', '*');
set(gca, 'fontsize', 18);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.8, 0.6, 0.68]);
xlabel('t');
ylabel('Correlator');
title('\fontsize{19} Logarithmic Correlation Function');

hold on 
semilogy(t, abs(corrValue2), 'color', [0 0.5 0], 'linewidth', 2,'Marker', '*');
semilogy(t, abs(corrValue3), 'color', [0.5 0 0],'linewidth', 2,'Marker', '*');
semilogy(t, abs(corrValue4), 'color', [0.8 0.1 0], 'linewidth', 2,'Marker', '*');


legend('Nconf=10^4', 'Nconf=10^5', 'Nconf=10^6', 'Nconf=10^7');
print('correlatorLog', '-dpng');

end
