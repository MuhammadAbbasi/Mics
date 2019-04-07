% Q3 part 1

n = -8:15;
x = zeros(size(n));
close all
subplot(4,1,1)
x = (n+3).*[n>=-2 & n<=4] + (11-n).*[n>4 & n<=10];
stem(n,x,"filled","linewidth",2)
grid
xlabel("Amplitude")
ylabel("n")
title("x[n]")
 
subplot(4,1,2)
y = 2.*((n-2).*[n>=2 & n<=9] + (16-n).*[n>9 & n<=15])
stem(n,y)
grid
xlabel("Amplitude")
ylabel("n")
title("2x[n-5]")

subplot(4,1,3)
z = -3.*(((n+7).*[n>=-6 & n<=0]) + (7-n).*[n>0 & n<=6])
stem(n,z)
grid
xlabel("Amplitude")
ylabel("n")
title("-3x[n+4]")

subplot(4,1,4)
t = y + z
stem(n,t)