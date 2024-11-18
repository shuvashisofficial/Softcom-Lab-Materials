img = imread('apples.jpg');

if size(img, 3) > 1
    img_gray = rgb2gray(img);
else
    img_gray = img;
end

img_gray = double(img_gray);

[rows, cols] = size(img_gray);

central_edge = zeros(rows, cols);
backward_edge = zeros(rows, cols);

for i = 2:rows-1
    for j = 1:cols
        central_edge(i, j) = (img_gray(i+1, j) - img_gray(i-1, j));
    end
end

for i = 2:rows
    for j = 1:cols
        backward_edge(i, j) = img_gray(i, j) - img_gray(i-1, j);
    end
end

central_enhanced = img_gray + central_edge;
backward_enhanced = img_gray + backward_edge;

central_edge = uint8(central_edge);
backward_edge = uint8(backward_edge);
central_enhanced = uint8(central_enhanced);
backward_enhanced = uint8(backward_enhanced);

figure;

subplot(3, 2, 1);
imshow(uint8(img_gray));
title('Original Image');

subplot(3, 2, 2);
imshow(uint8(img_gray));
title('Original Image');

subplot(3, 2, 3);
imshow(central_edge);
title('Central Derivative)');

subplot(3, 2, 4);
imshow(backward_edge);
title('(Backward Derivative)');

subplot(3, 2, 5);
imshow(central_enhanced);
title('Enhanced Image');

subplot(3, 2, 6);
imshow(backward_enhanced);
title('Enhanced Image');
