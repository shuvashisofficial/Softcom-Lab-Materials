% Read the original image
originalImg = imread('input1.jpg');

% Manually flip the image vertically
flippedImg = originalImg(end:-1:1, :, :);

% Manually merge the images vertically
mergedImg = zeros(size(originalImg, 1) * 2, size(originalImg, 2), size(originalImg, 3), 'uint8');
mergedImg(1:size(originalImg, 1), :, :) = originalImg;
mergedImg(size(originalImg, 1) + 1:end, :, :) = flippedImg;

% Display the results
imshow(mergedImg);
title('Merged Image');

% Save the merged image
imwrite(mergedImg, 'output1.jpg');