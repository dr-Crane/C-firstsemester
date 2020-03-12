/*
 * Протабулировать функцию ln((1+x)/(1-x)) от a до b с шагом h
 *
 * Функция определена для x < |1|
 */
#include <stdio.h>
#include <math.h>

int main ()
{
    double a, b, h;

    printf("Enter a, b, h:\n");
    int q = scanf("%lf%lf%lf", &a, &b, &h);
    if(q == 3){
        if ( (a <= b && h < 0) || (a >= b && h > 0) ) printf("Something is wrong\n");
        else
            if(a > 1){
                a = 1+h;
            }
            while(1){
                if(a<=b&&h>0&&a<0.999999){
                    printf("ln(%lf) = %lf\n", (1+a)/(1-a), log(1+a)-log(1-a));
                    a = a+h;
                }
                else if(a>=b&&h<0&&a>-0.999999){
                    printf("ln(%lf) = %lf\n", (1+a)/(1-a), log(1+a)-log(1-a));
                    a = a+h;
                }
                else break;
            }
    }
    else
        printf("ERROR");
    return 0;
}
