#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int **create_matrix(int height, int width, int floor, int roof) {
    int **matrix = (int**) malloc(height*sizeof(int*)); // int* - размер указателя типа int
    if (matrix) {
        for (int i = 0; i < height; i++) {
            matrix[i] = (int*) malloc(width*sizeof(int)); // sizeof(int) - размер переменной типа int (4 байта)
            if (matrix[i]) {
                for (int j = 0; j < width; j++) {
                    matrix[i][j] = rand() % (roof-floor+1) + floor;
                }
            } else {
                for (int i = 0; i < width; i++)
                free(matrix[i]);
                return NULL;
            }
        }
    } else {
        return NULL;
    }
    return matrix;
}

void main() {
    srand(time(NULL));
    int height = rand() % 5 + 2;
    int width = rand() % 5 + 2;
    int floor, roof;
    printf("Enter floor:\n");
    scanf("%d", &floor);
    printf("Enter roof:\n");
    scanf("%d", &roof);

    int **matrix = create_matrix(height, width, floor, roof);

    int max = matrix[0][0];
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] >= max) {
                max = matrix[i][j];
                max_i = i;
                max_j = j;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int *buffer[width];
    int temp;
    for (int j = 0; j < width; j++) {
        buffer[j] = matrix[0][j];
        matrix[0][j] = matrix[max_i][j];
        matrix[max_i][j] = buffer[j];
    }

    // Поменяли местами первую строку (matrix[0]) и i-ю строку (matrix[max_i]);

    for (int i = 0; i < height; i++) {
        temp = matrix[i][0];
        matrix[i][0] = matrix[i][max_j];
        matrix[i][max_j] = temp;
    }
    printf("\nMax: %d\nMax_i: %d\nMax_j: %d\n\n", max, max_i+1, max_j+1);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }



}

