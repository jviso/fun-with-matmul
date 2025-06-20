#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Matrix Matrix;

struct Matrix {
    int rows;
    int cols;
    int** data;
};

typedef enum InitStrategy InitStrategy;

enum InitStrategy {
    RANDOM,
    FROM_ARRAY
};

void print_matrix(Matrix m);

void matmul(Matrix* a, Matrix* b, Matrix* result);

int init_matrix(Matrix* m, int rows, int cols, InitStrategy strategy, int* values);

int main() {

    srand((unsigned int)time(NULL));

    Matrix a;
    if (init_matrix(&a, 2, 2, RANDOM, NULL) != 0) {
        printf("Failed to initialize matrix.\n");
        return 1;
    }

    Matrix b;
    int values[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    if (init_matrix(&b, 3, 3, FROM_ARRAY, values) != 0) {
        printf("Failed to initialize matrix.\n");
        return 1;
    }

    print_matrix(a);
    print_matrix(b);

    return 0;
}

int init_matrix(Matrix* m, int rows, int cols, InitStrategy strategy, int* values) {
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof *m->data * m->rows);
    for (int i = 0; i < m->cols; i++) {
        m->data[i] = malloc(sizeof *m->data[i] * m->cols);
    }

    switch (strategy) {
        case RANDOM:
            for (int i = 0; i < m->rows; i++) {
                for (int j = 0; j < m->cols; j++) {
                    m->data[i][j] = rand() % 100;
                }
            }
            break;
        case FROM_ARRAY:
            if (!values) {
                printf("Array of values for matrix initialization must not be null.\n");
                return 1;
            }
            /* TODO: We also assume here that the `values` array has at least `rows * cols` elements. */
            int index = 0;
            for (int i = 0; i < m->rows; i++) {
                for (int j = 0; j < m->cols; j++) {
                    m->data[i][j] = values[index];
                    index++;
                }
            }
            break;
    }

    return 0;
}

void matmul(Matrix* a, Matrix* b, Matrix* result) {
    int element = 0;
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            for (int k = 0; k < a->cols; k++) {
                element += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = element;
            element = 0;
        }
    }
}

void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%*d", 3, m.data[i][j]);
        }
        printf("\n");
    }
}
