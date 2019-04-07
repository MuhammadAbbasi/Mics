n= 0:15;
L = 2;
x = sin(n);
close all;

subplot(2,2,1);
stem(n,x,"filled","linewidth",2)
title("Original Signal")

subplot(2,2,2)
a = n.*L;
y = sin(L.*a);
stem(n,y,"filled","linewidth",2)
title("y[n]")

subplot(2,2,3)
b = n./L;
z = sin(b./L);
stem(n,z,"filled","linewidth",2)
title("z[n]")

