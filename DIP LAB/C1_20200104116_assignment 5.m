a=imread('input.png');

figure;
subplot(2,4,1);
imshow(a);

a=im2double(rgb2gray(a));

%Step 2
S=padarray(a,[1 1],0,'both');
f1 = [0 1 0; 1 -4 1; 0 1 0];
I1 = S;
[row, col] = size(S);

for i = 1:row-2
   for j = 1:col-2 
      N = S(i:i+2, j:j+2);
      t1 = sum(sum(N.*f1));
      I1(i+1,j+1) = t1;
    end
end

b=I1(2:row-1,2:col-1);
subplot(2,4,2);
imshow(b,[min(b(:)) max(b(:))]);

%Step 3
c=S-I1;
c=(c(2:row-1,2:col-1));
subplot(2,4,3);
imshow(c);

%Step 4
f1 = [-1 0 1; -2 0 2; -1 0 1];
f2 = [-1 -2 -1; 0 0 0; 1 2 1];

I1 = S;
I2 = S;

[row, col] = size(S);
    

for i = 1:row-2
   for j = 1:col-2 
      N = S(i:i+2, j:j+2);
      t1 = sum(sum(N.*f1));
      t2 = sum(sum(N.*f2));
      I1(i+1,j+1) = t1;
      I2(i+1,j+1) = t2;
    end
end

d=sqrt((I1.^2)+(I2.^2));
d=d(2:row-1,2:col-1);
[row1,col1]=size(d);
for i = 1:row1
   for j = 1:col1 
      if d(i,j)<0.1
          d(i,j)=0;
   
      end
   end
end

subplot(2,4,4);
imshow(d);

%Step 5
% 5*5 Average Filter
q=[1/25 1/25 1/25 1/25 1/25;1/25 1/25 1/25 1/25 1/25;1/25 1/25 1/25 1/25 1/25;1/25 1/25 1/25 1/25 1/25;1/25 1/25 1/25 1/25 1/25];
S=padarray(d,[2 2],0,'both');
e = S;

for i = 1:row-4
    for j = 1:col-4  
        N = S(i:i+4, j:j+4);
        t1 = sum(sum(N.*q));
        e(i+2,j+2) = t1;    
    end
end

[row1, col1] = size(e);
e=e(3:row1-2,3:col1-2);
subplot(2,4,5);
imshow(e);

%Step 6
f=c.*e;
subplot(2,4,6);
imshow(f);

%Step 7
g=a+f;
subplot(2,4,7);
imshow(g);

%Step 8
c=1;
gamma=0.5;
h=c*(g.^gamma);
subplot(2,4,8);
imshow(h);