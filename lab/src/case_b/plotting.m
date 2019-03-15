%% Plotting

clc
clear all
close all

load('eta.mat');
load('eta_hat.mat');
load('nu_hat.mat');
load('b_hat.mat');
load('nu.mat');
load('u.mat');


% POSITION PLOTS
figure;
subplot(2,2,1);
plot(eta(1,:),eta(2,:),eta_hat(1,:),eta_hat(2,:));
legend('Surge','Surge_{est}');
xlabel('Time [s]');
ylabel('x-position [m]');

subplot(2,2,2);
plot(eta(1,:),eta(3,:),eta_hat(1,:),eta_hat(3,:));
legend('Sway','Sway_{est}');
xlabel('Time [s]');
ylabel('y-position [m]');

subplot(2,2,3);
plot(eta(1,:), (180/pi)*eta(4,:),eta_hat(1,:), (180/pi)*eta_hat(4,:));
legend('Yaw','Yaw_{est}');
xlabel('Time [s]');
ylabel('Heading [degs]');


% VELOCITY PLOTS
figure;
subplot(2,2,1);
plot(nu(1,:), nu(2,:), nu_hat(1,:), nu_hat(2,:));
legend('Surge velocity','Surge velocity, est.');
xlabel('Time [s]');
ylabel('Velocity [m/s]');

subplot(2,2,2);
plot(nu(1,:), nu(3,:), nu_hat(1,:),nu_hat(3,:));
legend('Sway velocity','Sway velocity, est.');
xlabel('Time [s]');
ylabel('Velocity [m/s]');

subplot(2,2,3);
plot(nu(1,:), (180/pi)*nu(4,:), nu_hat(1,:), (180/pi)*nu_hat(4,:));
legend('Yaw velocity','Yaw velocity, est.');
xlabel('Time [s]');
ylabel('Angular velocity [degree/s]');

% THRUST PLOTS
figure;
subplot(1,2,1);
plot(u(1,:), u(2,:), u(1,:), u(3,:),  u(1,:), u(4,:));
legend('u BT','u VSP1', 'u VSP2');
xlabel('Time [s]');
ylabel('Newton [-]');
ylim([-1.1 1.1]);

subplot(1,2,2);
plot(u(1,:), (180/pi)*u(5,:), u(1,:), (180/pi)*u(6,:));
legend('VSP1 angle','VSP2 angle');
xlabel('Time [s]');
ylabel('Angle [deg]');
ylim([-185 185]);