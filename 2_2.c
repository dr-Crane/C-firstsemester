#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define min 0
#define max 100

int *create_mas(int size) {
    int *A = (int*) malloc(size*sizeof(int));
    if (A) {
        for (int i = 0; i < size; i++) {
            A[i] = rand() % (max-min+1) + min;
        }
    } else
        return NULL;
    return A;
}

int is_pal(int num) {
    int buffer = num;
    int space = 0;

    while ((buffer / 10) != 0) {
        space += buffer % 10;
        space *= 10;
        buffer = buffer / 10;
    }
    space += buffer;

    if (num == space) printf("%d - is a palindrome\n", num);
    else printf("%d - is not a palindrome\n", num);
}

void main() {
    int size;
    printf("Enter a size of matrix:");
    int q = scanf("%d", &size);
    if(q == 1) {
        srand(time(NULL));
        int *matrix = create_mas(size);
        for (int i = 0; i < size; i++) printf("%d ", matrix[i]); printf("\n");
        for (int i = 0; i < size; i++) is_pal(matrix[i]);

    }
    else printf("ERROR");
}
