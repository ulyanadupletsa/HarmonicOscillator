function correlatorN6

corrValue1 = dlmread('dataCorrMeanN6.txt','', [0 0 63 0]);
errValue1 = dlmread('dataCorrSigmaN6.txt','', [0 0 63 0]);

sigmaValue1 = dlmread('dataCorrSigmaN6.txt','', [0 0 63 0]);

t = 1:64;
errorbar(t, corrValue1,errValue1, 'Linewidth', 2, 'color', [0.3 0.6 0]);
hold on
plot(t, sigmaValue1,'linewidth', 3);
set(gca, 'fontsize', 18);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.8, 0.6, 0.68]);
xlabel('k');
xlabel('Time t');
ylabel('Correlator');
title('\fontsize{19} Correlation function, with Nconf=10^6');
legend('corrData', '\sigma_{corr}');

print('correlatorN6', '-dpng');
end

        
   
        
        