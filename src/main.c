#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** matrix, int rows, int cols);

int main() {

    int rows = 2;
    int cols = 2;
    int** m;

    m = malloc(sizeof *m * rows);
    for (int i = 0; i < cols; i++) {
        m[i] = malloc(sizeof *m[i] * cols);
    }

    int v = 5;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = v;
            v++;
        }
    }

    print_matrix(m, rows, cols);

    return 0;
}

void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%*d", 2, matrix[i][j]);
        }
        printf("\n");
    }
}
