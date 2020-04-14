#include <stdio.h>
#include <math.h>

int main()
{

    double x, old = 0, new = 0, n=0, element = 1, eps;

    printf("Enter  x<1 :\n");
    scanf("%lf", &x);
    if((x < 1) && (x >= 0) ) {
        printf("Enter eps<1:\n");
        scanf("%lf", &eps);
        if(eps < 1 && eps >= 0) {
            double buffer = x;
            do {
                element = 1;
                old = new;
                element *= 2.0 * buffer / (2.0 * n + 1.0);
                new = old + element;
                n += 1.0;
                buffer *= x*x;

            } while (fabs(old - new) > eps);

            printf("Expression: %lf\nln((1+x)/(1-x)): %lf\n", new, log(1 + x)-log(1 - x));
        }
        else printf("Eps must be lower then 1\n");
    }
    else printf(" |x| < 1\n");

}
