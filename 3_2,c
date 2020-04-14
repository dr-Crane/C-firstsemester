/*
Дана целочисленная матрица порядка n на m. Определить k - количество "особых" элементов матрицы,
считая элемент "особым", если он больше суммы остальных элементов своей строки.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int **create_matrix(int height, int width, int min, int max) {
    int **matrix = (int**) malloc(height*sizeof(int*)); // int* - размер указателя типа int
    if (matrix) {
        for (int i = 0; i < height; i++) {
            matrix[i] = (int*) malloc(width*sizeof(int)); // sizeof(int) - размер переменной типа int (4 байта)
            if (matrix[i]) {
                for (int j = 0; j < width; j++) {
                    matrix[i][j] = rand() % (max-min+1) + min;
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

void main()
{
    srand(time(NULL));
    int height = rand() % 5 + 2;
    int width  = rand() % 5 + 2;  // Width должен быть маленьким, чтобы отдельные элементы значили больше для суммы
    int count = 0, sum = 0, min, max;
    srand(time(NULL));
    printf("Enter floor:\n");
    scanf("%d", &min);
    printf("Enter roof:\n");
    scanf("%d", &max);
    int **matrix = create_matrix(height, width, min, max);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) sum += matrix[i][j]; // Считаем сумму строки (sum)
        for (int j = 0; j < width; j++) // Проверяем элементы на "особенность"
            if ( matrix[i][j] > (sum - matrix[i][j]) ) {
                count++; // Нашли "особенный" элемент в строке
                printf("(%d,%d): %d\n", i+1, j+1, matrix[i][j]); // Вывод "особого" элемента (i,j): число

            }
        sum = 0;
    }
    printf("\n");
    // Вывод матрицы
    free(matrix); 

    printf("Count of \"special\" elements in matrix : %d", count);

}
