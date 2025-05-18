#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find_max_element(const int *arr, int size, int *max_value, int *max_index) {
    *max_value = arr[0];
    *max_index = 0;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max_value) {
            *max_value = arr[i];
            *max_index = i;
        }
    }
}

void fill_array(int *arr, int size, int min_val, int max_val) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
}

void print_array(const int *arr, int size, const char *name) {
    printf("Масив %s: [", name);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    system("chcp 65001");
    srand(time(NULL));
    
    int N, M;

    do {
        printf("Введіть розмір масиву x(N) (N < 80): ");
        scanf("%d", &N);
    } while (N >= 80 || N <= 0);
    
    do {
        printf("Введіть розмір масиву y(M) (M < 70): ");
        scanf("%d", &M);
    } while (M >= 70 || M <= 0);

    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(M * sizeof(int));

    fill_array(x, N, 0, 100);
    fill_array(y, M, 0, 100);

    print_array(x, N, "x");
    print_array(y, M, "y");

    int max_x, max_x_index;
    int max_y, max_y_index;
    
    find_max_element(x, N, &max_x, &max_x_index);
    find_max_element(y, M, &max_y, &max_y_index);

    printf("\nРезультати:\n");
    printf("У масиві x(N):\n");
    printf("  Найбільший елемент = %d\n", max_x);
    printf("  Його індекс = %d (порядковий номер = %d)\n", max_x_index, max_x_index + 1);
    
    printf("У масиві y(M):\n");
    printf("  Найбільший елемент = %d\n", max_y);
    printf("  Його індекс = %d (порядковий номер = %d)\n", max_y_index, max_y_index + 1);

    free(x);
    free(y);
    
    return 0;
}