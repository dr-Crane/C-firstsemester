#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{   
    int num = 0;
    printf("Введите число: ");
    int q = scanf("%d", &num);
    if(q == 1)
    {
    
    int buffer = num;
    int space = 0;
    
    while ((buffer / 10) != 0) {
        space += buffer % 10;
        space *= 10;
        buffer = buffer / 10;
    }
    space += buffer;
    
    if (num == space) printf("Число %d - палиндром!", num);
    else printf("Число %d - не палиндром.", num);
    }
    
    else
    printf("Неправильные данные");

}
