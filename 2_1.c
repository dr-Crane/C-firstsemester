/*
 *
 *  Задан числовой массив А. Подсчитать число разных чисел в А.
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *create_mas(int N, int min, int max) {
    int *A = (int*) malloc(N*sizeof(int));
    if (A) {
        for (int i = 0; i < N; i++) {
            A[i] = rand() % (max-min+1) + min;
        }
    } else{
        return NULL;
    }
    return A;
}



int main()
{
    srand(time(NULL));
    int size, min, max;
    printf("Enter a size of matrix:\n");
    scanf("%d", &size);
    if(size<0) {
        printf("Size can't be lower then zero");
        return 0;
    }
    printf("Enter floor:\n");
    int a = scanf("%d", &min);
    if(a==1){
        printf("Enter roof:\n");
        int b = scanf("%d", &max);
        if(b == 1) {
            int count = 0, check = 1;
            int *a = create_mas(size, min, max);
            for (int i = 0; i < size; i++) printf("%d ", a[i]);
            printf("\nDifferent nums are: ");
            for (int i = 0; i < size; i++) {
                for (int j = i; j < size; j++) {
                    if ((i != j) && (a[i] == a[j])) {
                        check = 0;
                        break;
                    }
                }

                if (check == 1) {
                    count++;
                    printf("%d ", a[i]);
                } else check = 1;
            }
            printf("\nCount: %d", count);
            free(a);
        }
        else printf("ERROR");
    }
    else printf("ERROR");

}
