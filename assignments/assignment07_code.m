% Simulation of a single integrator maneuvering example of Exercise set 7.
% 
% Roger Skjetne - 28.02.2019
%

% Simulation cases:
Task_mode = 10.1; % Choose between 10.1, 10.2, 11.1, 11.2 (corresponding to problem text).

switch Task_mode
    case 10.1
        % Task 10.1
        Tsim      = 3;
        Path_mode = 1;  % 1: Straight-line, 2: Ellipsoid
        mu        = 0;
        p_init    = [6;5];
        s_init    = 0.0;
    case 10.2
        % Task 10.2
        Tsim      = 3;
        Path_mode = 1;  % 1: Straight-line, 2: Ellipsoid
        mu        = 10;
        p_init    = [6;5];
        s_init    = 0.0;
    case 11.1
        % Task 11.1
        Tsim      = 25;
        Path_mode = 2;  % 1: Straight-line, 2: Ellipsoid
        mu        = 0;
        p_init    = [7;2];
        s_init    = 0.0;
    case 11.2
        % Task 11.2
        Tsim      = 25;
        Path_mode = 2;  % 1: Straight-line, 2: Ellipsoid
        mu        = 10;
        p_init    = [7;2];
        s_init    = 0.0;
end

% Simulation parameters
h    = 0.001;
t    = [0:h:Tsim];
N    = length(t);

p_log  = zeros(2,N);
pd_log = zeros(2,N);
s_log  = zeros(1,N);


% Path and controller parameters
p0   = [ 2; 0];
p1   = [10; 4];
pc   = [6; 0];
Rxy  = diag([5,3]);

v0   = 1.0;

K    = 1.0*eye(2);



% Simulation
p_new = p_init;
s_new = s_init;
    
for k = 1:N
    s = s_new;
    p = p_new;
    
    switch Path_mode
        case 1
            pd   = (1-s)*p0 + s*p1;
            pd_s = p1-p0;
        case 2
            xi   = [cos(2*pi*s); sin(2*pi*s)];
            xi_s = 2*pi*[-sin(2*pi*s); cos(2*pi*s)];
            pd   = pc + Rxy*xi;
            pd_s = Rxy*xi_s;
        otherwise 
            pd = (1-s)*p0 + s*p1;
            pd_s = p1-p0;
    end    
    vs    = v0/norm(pd_s);
    V_s   = -(p-pd)'*pd_s;
    omega = mu*V_s/norm(pd_s);
    
    u = -K*(p - pd) + pd_s*vs;
    
    s_new = s + h*(vs - omega);
    p_new = p + h*u;

    s_log(k)    = s;
    p_log(:,k)  = p;
    pd_log(:,k) = pd;
end

N_int = floor(N/10);
figure(1);
% p2 = (1-1.5)*p0+1.5*p1;
% plot([p0(2) p2(2)],[p0(1) p2(1)],'g:'); hold on;
plot(pd_log(2,:),pd_log(1,:),'r:',p_log(2,:),p_log(1,:),'b:'); hold on; 
plot(pd_log(2,1:N_int:end),pd_log(1,1:N_int:end),'rs',p_log(2,1:N_int:end),p_log(1,1:N_int:end),'bo'); hold off;
grid on; axis equal;


figure(2);
plot(t,s_log); grid on;


