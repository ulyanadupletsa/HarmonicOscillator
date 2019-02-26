function corrSigma

sigmaValue1 = dlmread('dataCorrSigmaN4.txt','', [0 0 63 0]);
sigmaValue2 = dlmread('dataCorrSigmaN5.txt','', [0 0 63 0]);
sigmaValue3 = dlmread('dataCorrSigmaN6.txt','', [0 0 63 0]);
sigmaValue4 = dlmread('dataCorrSigmaN7.txt','', [0 0 63 0]);

t = 1:64;
plot(t, sigmaValue1,'linewidth', 2);
hold on
plot(t, sigmaValue2,'linewidth', 2);
plot(t, sigmaValue3,'linewidth', 2);
plot(t, sigmaValue4,'linewidth', 2);

n4 = sum(sigmaValue1)/64
n5 = sum(sigmaValue2)/64
n6 = sum(sigmaValue3)/64
n7 = sum(sigmaValue4)/64
 v2 = n4/8
 v3 = n5/8
 v4 = n6/8

set(gca, 'fontsize', 19);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.9, 0.7, 0.68]);
xlabel('N');
ylabel('Correlator Sigma');
title('Correlator Sigma');

legend('Nconf=10^4', 'Nconf=10^5', 'Nconf=10^6', 'Nconf=10^7');

end