% Q3 part 2
% 
% n = -15:15;
% x = zeros(size(n));
% close all
% subplot(5,1,1)
% x = (n+3).*[n>=-2 & n<=4] + (11-n).*[n>4 & n<=10];
% stem(n,x,"filled","linewidth",2)
% grid
% xlabel("Amplitude")
% ylabel("n")
% title("x[n]")
%  
% subplot(5,1,2)
% a = -(n).*[n>=1 & n<=7] + (n-14).*[n>7 & n<=13]
% stem(n,a,"filled","linewidth",2)
% grid
% xlabel("Amplitude")
% ylabel("n")
% title("x[3-n]")
% 
% subplot(5,1,3)
% b = (n+5).*[n>=-4 & n<=2] + (9-n).*[n>2 & n<=8]
% stem(n,b,"filled","linewidth",2)
% grid
% xlabel("Amplitude")
% ylabel("n")
% title("x[n-2]")
% 
% subplot(5,1,4)
% c = b .* x
% stem(n,c,"filled","linewidth",2)
% grid
% xlabel("Amplitude")
% ylabel("n")
% title("x[n].x[n-2]")
% 
% subplot(5,1,5)
% d = c .* a
% stem(n,d,"filled","linewidth",2)
% grid
% xlabel("Amplitude")
% ylabel("n")
% title("z[n]")
syms t x n
int(exp(-t/2),0,pi)