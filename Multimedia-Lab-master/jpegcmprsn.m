clc
clear

img = imread('peppers.png');
img = rgb2gray(img);
dim = 512;
img = imresize(img, [dim dim]);

plotd = 2;
subplot(plotd, plotd, 1);
imshow(img);
title('Original Image')

[rows columns] = size(img);


in = 1;
tmp = img;
res = img;


for i =  1 : 8 : dim
    for j = 1 : 8 : dim
        timg = img(i:i+8-1, j:j+8-1);
        in = in + 1;
        dctimg = dct(timg, 100);
        tmp(i:i+8-1, j:j+8-1) = dctimg(1:8, 1:8);
        idc = idct2(dctimg);
        res(i:i+8-1, j:j+8-1) = idc(1:8, 1:8);
    end
end

subplot(plotd, plotd, 2)
imshow(tmp);
title('After DCT')

subplot(plotd, plotd, 3)
imshow(res);
title('Reconstructed')






