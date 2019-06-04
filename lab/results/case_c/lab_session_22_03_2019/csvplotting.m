% simple = importdata('Simple_allocation_13_08_24.csv');

data = importdata('22_03_measured_vs_desired_path_speed02_kp_20_kd_40_17_18_40.csv');

heading_step = 150;

% xpos_simple = simple.data(:,1);
% 
% ypos_simple = simple.data(:,2);s
% 
% heading_simple = simple.data(:,3);
% 
% tau_surge_simple = simple.data(:,4);
% 
% tau_sway_simple = simple.data(:,5);
% 
% tau_yaw_simple = simple.data(:,6);


% figure;
% plot(ypos, xpos);
% hold on;
% quiver(ypos(1:heading_step:end), xpos(1:heading_step:end), ... 
%     sin(heading(1:heading_step:end)), cos(heading(1:heading_step:end)));
% title('Ship position');
% xlabel('E-position');
% ylabel('N-position');

switch_signal = data.data(:,17);

% mask = switch_signal > 0;



xpos = data.data(:,4);

ypos = data.data(:,5);

heading = data.data(:,6);

xpos_des = data.data(:,1);

ypos_des = data.data(:,2);

heading_des = data.data(:,3);

j_control = data.data(:,19);

j_measurement = data.data(:,18);



s = data.data(:,16);

figure;
subplot(2,3,1);
hold on
plot(j_measurement); 
legend('j_measurement');

subplot(2,3,2)
hold on
plot(j_control);
legend('j_control');

subplot(2,3,3)
hold on
plot(s)
legend('s');

subplot(2,3,4)
hold on 
plot(switch_signal);
legend('Switch signal');

subplot(2,3,5)
hold on
plot(heading);
legend('heading');
figure;
hold on
plot(ypos,xpos);
plot(ypos_des,xpos_des);
quiver(ypos(1:heading_step:end), xpos(1:heading_step:end), ... 
    sin(heading(1:heading_step:end)), cos(heading(1:heading_step:end)));
title('Ship position'); 
legend('Actual','Desired');
axis equal;
xlabel('Y-position');
ylabel('X-position');



%corresponding movements
% figure;
% plot(ypos_full, xpos_full);
% hold on;
% quiver(ypos_full(1:heading_step:end), xpos_full(1:heading_step:end), ... 
%     sin(heading_full(1:heading_step:end)), cos(heading_full(1:heading_step:end)));
% title('Ship position');
% xlabel('E-position');
% ylabel('N-position');
% 
% %Plotting commanded thrusts
% figure;
% subplot(311)
% mtit('Commanded thrust')
% plot(tau_surge_full)
% ylabel('surge[N]')
% subplot(312)
% plot(tau_sway_full)
% ylabel('sway[N]')
% subplot(313)
% plot(tau_yaw_full)
% ylabel('yaw[N]')


