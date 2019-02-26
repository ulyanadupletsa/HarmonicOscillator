function continuumLimit

en2 = dlmread('dataEnergy_a2.txt','', [2 0 2 0]);
err2 = dlmread('dataEnergy_a2.txt','', [2 1 2 1]);

en1 = dlmread('dataEnergy_a1.txt','', [2 0 2 0]);
err1 = dlmread('dataEnergy_a1.txt','', [2 1 2 1]);

en05 = dlmread('dataEnergy_a05.txt','', [2 0 2 0]);
err05 = dlmread('dataEnergy_a05.txt','', [2 1 2 1]);

en025 = dlmread('dataEnergy_a025.txt','', [2 0 2 0]);
err025 = dlmread('dataEnergy_a025.txt','', [2 1 2 1]);

en0125 = dlmread('dataEnergy_a0125.txt','', [2 0 2 0]);
err0125 = dlmread('dataEnergy_a0125.txt','', [2 1 2 1]);



a = [2.0; 1.0; 0.5; 0.25; 0.125]; 
a = a.^2;
energy = [en2; en1; en05; en025; en0125];
err = [err2; err1; err05; err025; err0125];

errorbar(a, energy, err, 'linewidth', 2, 'Marker', '*', 'Linestyle', 'none');
hold on
Ofitline = polyfit(a, energy, 1);
p = plot(a, polyval(Ofitline,a),'--b', 'Linewidth', 2);

set(gca, 'fontsize', 18);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.8, 0.6, 0.68]);
xlabel('a^2');
ylabel('\Delta Energy');
legend(p, 'y = (-0.0427\pm 0.0007)x+(0.9999\pm 0.0013)');
title('\fontsize{19} \Delta Energy in the continuum limit with Nconf=10^6');
print('energy', '-dpng');
