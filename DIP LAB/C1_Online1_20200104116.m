
originalImg = imread('turkey.jpg');

imgF = zeros(size(originalImg), 'uint8');


for i=1:size(originalImg,1)
    for j=1:size(originalImg,2)
        currentPixel = squeeze(originalImg(i,j,:));
        if currentPixel(1) > 200 && currentPixel(2) < 55 && currentPixel(3) < 55
            continue;
        else if
                currentPixel(1) > 200 && currentPixel(2) > 200 && currentPixel(3) > 200
                continue;  
            else
            imgF(i, j, 1) = 255; 
            imgF(i, j, 3) = 255;
            end
        end
    end
Figure;
subplot(1,2,1);
imshow(originalImg);
title('Original Image');

subplot(1,2,2);         
                
        
        
        
        