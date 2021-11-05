tm1 = (37.2/3)*(1/4000);
tm2 = -(41.3/28)*(1/4000);
tt = -0.00025:0.000008:0.00025;
x1 = 20*cos(2*pi*4000*tt-(74.4*pi/3));
x2 = 24*cos(2*pi*4000*tt+(41.3*pi/14));
x3 = -39.88*cos(2*pi*4000*tt+(0.62*pi/180));
x4 = real(20*exp(j*2*pi*4000*tt)*exp(j*-74.4*pi/3));

subplot(4,1,1);
plot(tt, x1), grid on
title('Harun Selman Karakaş SINUSOID X1')

subplot(4,1,2);
plot(tt, x2), grid on
title('SINUSOID X2')

subplot(4,1,3);
plot(tt, x3), grid on
title('SINUSOID X3')

subplot(4,1,4);
plot(tt, x4), grid on
title('SINUSOID X1 BY COMPLEX AMPLITUDE')
xlabel('TIME(sec)')
