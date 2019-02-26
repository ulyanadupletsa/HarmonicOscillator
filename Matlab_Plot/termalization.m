function termalization

lecture = fopen('dataAction.txt');
vector = textscan(lecture, '%f %f');
fclose(lecture);

t = vector{1};
S = vector{2};

plot(t,S, 'Marker', '.', 'Linestyle', '-', 'Linewidth', 2);
set(gca, 'fontsize', 18);
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.8, 0.6, 0.68]);
xlabel('k');
xlabel('Markovian time t');
ylabel('Action S');
title('\fontsize{19} Termalization');
print('termalization', '-dpng');

end