%% Plotting lab data

folder_path = "../../results/case_c/lab_session_22_03_2019/";

file_name = "measured_vs_desired_path_16_02_56.csv";

results = importdata(strcat(folder_path, file_name));

eta_measured = [    
                    results.data(:,4)';
                    results.data(:,5)';
                    results.data(:,6)'
               ];
           
figure();
hold on;

subplot(1,3,1);
plot(eta_measured(1,:));
title('Measured x-position');

subplot(1,3,2);
plot(eta_measured(2,:));
title('Measured y-position');

subplot(1,3,3);
plot(eta_measured(3,:));
title('Measured yaw heading');