function plot_data()

load('test_eta.mat');
load('test_tau.mat');
load('test_u_polar.mat');
load('test_u_rect.mat');


figure()
plot(eta(1,:), eta(2,:), eta(1,:), eta(3,:), eta(1,:), eta(4,:));
title('Eta')
legend('Surge', 'Sway', 'Yaw')

figure()
plot(tau(1,:), tau(2,:), tau(1,:), tau(3,:), tau(1,:), tau(4,:));
title('Tau')
legend('Surge force', 'Sway force', 'Yaw moment')

figure()
subplot(2,1,1)
plot(u_polar(1,:), u_polar(2,:), u_polar(1,:), u_polar(3,:), u_polar(1,:), u_polar(4,:));
title('Polar u')
legend('u_1', 'u_2', 'u_3')

subplot(2,1,2)
plot(u_rect(1,:), u_rect(2,:), u_rect(1,:), u_rect(3,:), u_rect(1,:), u_rect(4,:));
title('Rectangular u')
legend('u_1', 'u_2', 'u_3')

figure()
subplot(2,1,1)
plot(u_polar(1,:), (180/pi)*u_polar(5,:), u_polar(1,:), (180/pi)*u_polar(6,:));
title('Polar vsp angles')
ylim([-180 180])
legend('alpha_1', 'alpha_2')

subplot(2,1,2)
plot(u_rect(1,:), (180/pi)*u_rect(5,:), u_rect(1,:), (180/pi)*u_rect(6,:));
title('Rectangular vsp angles')
ylim([-180 180])
legend('alpha_1', 'alpha_2')

end