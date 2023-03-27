clear all;
close all;

% Set Style
cal_orange = [237 125 49]/255;
cal_blue = [50 142 216]/255;
cal_grey_light = [0.95 0.95 0.95];
cal_grey_dark = [0.35 0.35 0.35];

% Read the data output from the C++ RK4 Method
RK4Times = readmatrix('RK4Times.csv');
RK4Vectors = readmatrix("RK4Vectors.csv");

% Extract the relevant data from the variables
times = RK4Times(:,2);
y = RK4Vectors(:,2:end);

% Extract the elements of the vector y
y1 = y(:,1);
y2 = y(:,2);

% Evaluate the analytical expressions of the elements
y1_analytic = 7 .* exp(times);
y2_analytic = 22 .* exp(-1 .* times);


% Plot y1
figure(1)
% set figure position and size:
set(gcf,'position',[160 200 500 400])

% keep position and size when printing:
set(gcf,'PaperPositionMode','auto')

hold on
plot(times,y1,"b",'Linewidth',1,'DisplayName','Numerical')
plot(times,y1_analytic,"r",'Linewidth',1,'DisplayName','Analytic')
hold off

xlabel('Time');
ylabel('y1');

%leg = legend('location','northoutside','orientation','horizontal');
legend();

% set fonts and frame:
set(gca,'Fontn','Times','FontSize',18,'linewidth',1)

% % For a vectorial figure (for latex):
% print -deps2c y1.eps
% 
% % For an image figure at resolution 300 pixels/inch (for word):
% print -dpng -r300 y1.png




% Plot y2
figure(2)
% set figure position and size:
set(gcf,'position',[160 200 500 400])

% keep position and size when printing:
set(gcf,'PaperPositionMode','auto')

hold on
plot(times,y2,"b",'Linewidth',1,'DisplayName','Numerical')
plot(times,y2_analytic,"r",'Linewidth',1,'DisplayName','Analytic')
hold off

xlabel('Time');
ylabel('y2');

%leg = legend('location','northoutside','orientation','horizontal');
legend();

% set fonts and frame:
set(gca,'Fontn','Times','FontSize',18,'linewidth',1)

% % For a vectorial figure (for latex):
% print -deps2c y2.eps
% 
% % For an image figure at resolution 300 pixels/inch (for word):
% print -dpng -r300 y2.png
