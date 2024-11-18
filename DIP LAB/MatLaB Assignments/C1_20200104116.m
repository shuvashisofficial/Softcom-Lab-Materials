originalImg = imread('input.jpg');

originalGray = rgb2gray(originalImg);

flippedGray = originalGray(end:-1:1, :);

mergedImg = zeros(size(originalGray, 1) * 2, size(originalGray, 2), 'uint8');
mergedImg(1:size(originalGray, 1), :) = originalGray;
mergedImg(size(originalGray, 1) + 1:end, :) = flippedGray;

subplot(1, 3, 1);
imshow(originalGray);
title('Original Image');

subplot(1, 3, 2);
imshow(flippedGray);
title('Flipped Image');

subplot(1, 3, 3);
imshow(mergedImg);
title('Merged Image');

imwrite(mergedImg, 'output.jpg');
