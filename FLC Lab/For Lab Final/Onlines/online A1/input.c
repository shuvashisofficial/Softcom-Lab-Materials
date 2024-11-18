#include<stdio.h>
int add(int a, int b, int c)
{
    return a+b+c;
}
void multiplication(int a, int b, int c)
{
    printf("product: %d", a*b*c);
}
printf("product : %d", a*b*c);
int main()
{
    int a, b, c;
    scanf("%d %d %d",&a,&b,&c);
    int sum =
        add(a,b,c);
    printf("sum: %d", sum);
    multiplication(a,b,c);
    return 0;
}
