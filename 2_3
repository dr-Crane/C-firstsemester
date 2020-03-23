/*
 *
 * Из упорядоченных массивов A длины n и B длины m сформировать, путем слияния,  упорядоченный массив C длины n+m.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int *create_mas(int N, int min, int max) {
    int *A = (int*) malloc(N*sizeof(int));
    if (A) {
        for (int i = 0; i < N; i++) {
            A[i] = rand() % (max-min+1) + min;
        }
    } else
        return NULL;

    return A;
}


int main() {
    int size1,size2,min,max,a=0,b=0,c=0,d=0;
    printf("Enter size1:\n");
    a = scanf("%d", &size1); if(a==0) return 0;
    printf("Enter size2:\n");
    b = scanf("%d", &size2); if(b==0) return 0;
    printf("Enter min:\n");
    c = scanf("%d", &min);   if(c==0) return 0;
    printf("Enter max:\n");
    d = scanf("%d", &max);   if(d==0) return 0;
    int size = size1 + size2;

    srand(time(NULL));
    int *A = create_mas(size1, min, max); sort(A, size1);
    int *B = create_mas(size2, min, max); sort(B, size2);
    int *C = create_mas(size, min, max);

    int i=0, j=0, k=0;
        while((i < size1)&&(j < size2)) {
            if (A[i] >= B[j]){
                C[k] = B[j];
                j++;
                k++;
            }
            else{
                C[k] = A[i];
                i++;
                k++;
            }
        }
        if(i == size1){
            for(; j < size2; j++){
                C[k] = B[j];
                k++;
            }
        }
        else{
            for(; i < size1; i++){
                C[k] = A[i];
                k++;
            }
        }

    for (int i = 0; i < size1; i++) printf("%d ", A[i]); printf("\n");
    for (int i = 0; i < size2; i++) printf("%d ", B[i]); printf("\n");
    for (int i = 0; i < size; i++) printf("%d ", C[i]);
    return 0;
}
