inputImagePath = 'BW-Rose.jpg';
inputImage = imread(inputImagePath);

if size(inputImage, 3) == 1
    inputImage = repmat(inputImage, [1 1 3]);
end

[height, width, ~] = size(inputImage);
mask = triu(true(height, width), 0);

outputImage = inputImage;
outputImage(repmat(mask, [1 1 3])) = 255 - outputImage(repmat(mask, [1 1 3]));

figure;
subplot(1, 2, 1);
imshow(inputImage);
title('Input Image');

subplot(1, 2, 2);
imshow(outputImage);
title('Output Image');
