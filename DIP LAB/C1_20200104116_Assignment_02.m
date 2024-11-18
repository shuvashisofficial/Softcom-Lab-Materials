I = imread('pollen.jpg');
input = I;
I = im2double(I);
[row, col, ch] = size(I);

% Compute min and max for each channel
A = min(min(I, [], 1), [], 2);
B = max(max(I, [], 1), [], 2);

% Ensure A and B are replicated across all rows and columns
A_rep = repmat(A, [row, col, 1]);
B_rep = repmat(B, [row, col, 1]);

D = B_rep - A_rep;
M = 255;

R = I - A_rep;
R = R ./ D;
R = R * M;
R = R + A_rep;

R = uint8(R);

figure;
subplot(2, 2, 1);
imshow(input);
title('Input Image');

subplot(2, 2, 2);
imshow(R);
title('Contrast Stretched Image');
