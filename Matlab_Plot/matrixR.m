function matrixR

mat2 = dlmread('dataMatrixR_a2.txt','', [2 0 2 0]);
err2 = dlmread('dataMatrixR_a2.txt','', [2 1 2 1]);

mat1 = dlmread('dataMatrixR_a1.txt','', [2 0 2 0]);
err1 = dlmread('dataMatrixR_a1.txt','', [2 1 2 1]);

mat05 = dlmread('dataMatrixR_a05.txt','', [2 0 2 0]);
err05 = dlmread('dataMatrixR_a05.txt','', [2 1 2 1]);

mat025 = dlmread('dataMatrixR_a025.txt','', [2 0 2 0]);
err025 = dlmread('dataMatrixR_a025.txt','', [2 1 2 1]);

mat0125 = dlmread('dataMatrixR_a0125.txt','', [2 0 2 0]);
err0125 = dlmread('dataMatrixR_a0125.txt','', [2 1 2 1]);



a = [2.0; 1.0; 0.5; 0.25; 0.125]; 
a = a.^2;
matrix = [mat2; mat1; mat05; mat025; mat0125];
err = [err2; err1; err05; err025; err0125];

errorbar(a, matrix, err, 'linewidth', 2, 'Marker', '*', 'Linestyle', 'none');
hold on
Ofitline = polyfit(a, matrix, 1);
p = plot(a, polyval(Ofitline,a),'--b', 'Linewidth', 2);

set(gca, 'fontsize', 18);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.8, 0.6, 0.68]);
xlabel('a^2');
ylabel('Matrix element');
legend(p,'y = (-0.0415 \pm 0.0001)x+(0.7073 \pm 0.0002)');
title('\fontsize{19} Matrix element in the continuum limit with Nconf=10^6');
print('matrixR', '-dpng');

