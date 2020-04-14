/*
Дана целочисленная квадратная матрица порядка n. Найти s - сумму элементов из заштрихованной области
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **create_matrix(int size, int min, int max) {
    int **matrix = (int**) malloc(size*sizeof(int*)); // int* - размер указателя типа int
    if (matrix) {
        for (int i = 0; i < size; i++) {
            matrix[i] = (int*) malloc(size*sizeof(int)); // sizeof(int) - размер переменной типа int (4 байта)
            if (matrix[i]) {
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = rand() % (max-min+1) + min;
                }
            } else {
                for (int i = 0; i < size; i++)
                    free(matrix[i]);
                return NULL;
            }
        }
    } else {
        return NULL;
    }
    return matrix;
}

void main()
{
    int size, sum = 0, max, min;
    printf("Enter a size of matrix:\n"); scanf("%d", &size);
    printf("Enter floor:\n");
    scanf("%d", &min);
    printf("Enter roof:\n");
    scanf("%d", &max);
    if (size > 1) {
        srand(time(NULL));
        int **matrix = create_matrix(size, min , max);
        // Вывод матрицы
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) printf("%d ", matrix[i][j]);
            printf("\n");
        }

        for (int i = 0; i < size; i++)
            sum += matrix[0][i] + matrix[size-1][i] + matrix[i][0] + matrix[i][size-1];
        // Суммируем первый столбец и строку, последний столбец и строку
        // Угловые элементы [0][0], [0][size-1], [size-1][0], [size-1][size-1] суммировались дважды
        // Необходимо вычесть их (один раз)
        sum = sum - matrix[0][0] - matrix[size-1][0] - matrix[0][size-1] - matrix[size-1][size-1];
        printf("\nSum: %d", sum);
        free(matrix);
    } else {
        printf("ERROR");
    }
}
