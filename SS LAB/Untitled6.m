% Q3 part 3

n = -15:15;
x = zeros(size(n));
close all
subplot(2,1,1)
x = (n+3).*[n>=-2 & n<=4] + (11-n).*[n>4 & n<=10];
stem(n,x,"filled","linewidth",2)
grid
xlabel("Amplitude")
ylabel("n")
title("x[n]")
 
subplot(2,1,2)
b = -(n).*[n>=1 & n<=7] + (n-14).*[n>7 & n<=13]
stem(n,b,"filled","linewidth",2)
grid
xlabel("Amplitude")
ylabel("n")
title("----")