% Aqsa Project
% MRI Image transmission

image_1 = imread('a3.jpg','jpg');
subplot(121)
imagesc(image_1)

[a b] = size(image_1)
s = a/b
% x_image = ceil(a./5)
% y_image = ceil(b./5)

J = imresize(image_1,0.5)

[x y] = size(J)
subplot(122)
imagesc(J)

% 
% new_image = zeros(x_image,y_image);
% 
% for c1 = 1:x_image
%     for c2 = 1:y_image
%         new_image(c1,c2) = image_1(c1.*5,c2.*5) % c1 x x_scale and same for y
%     end
% end
% 
% subplot(121)
% imagesc(image_1)
% axis tight;
% 
% subplot(122)
% imagesc(new_image)
% axis tight;

% pause(10)
% Y = fft2(image_1)
% imagesc(abs(fftshift(Y)))
% pause(10)
% Y_inv = ifft2(Y)
% imagesc(abs(fftshift(Y_inv)))