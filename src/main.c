#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    FROM_ARRAY,
    NO_VALUES
};

void print_matrix(Matrix m);
void matmul(Matrix* a, Matrix* b, Matrix* result);
int init_matrix(Matrix* m, int rows, int cols, InitStrategy strategy, int* values);
bool matrices_are_equal(Matrix* a, Matrix* b);
int test_matmul_2x2();

int main() {

    /* TODO
     * Write unit tests for matmul implementation.
     * Add timing values printed to `stdout`.
     * Log timing values to file.
     */
    srand((unsigned int)time(NULL));

    if (test_matmul_2x2() != 0) {
        printf("Failed to run matmul tests.\n");
    }

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
            /* TODO
             * We also assume here that the `values` array has at least `rows * cols` elements.
             * Can that be fundamentally improved to be more safe?
             */
            int index = 0;
            for (int i = 0; i < m->rows; i++) {
                for (int j = 0; j < m->cols; j++) {
                    m->data[i][j] = values[index];
                    index++;
                }
            }
            break;
        case NO_VALUES:
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

int test_matmul_2x2() {
    Matrix a, b;
    int a_values[4] = { 1, 2, 3, 4 };
    if (init_matrix(&a, 2, 2, FROM_ARRAY, a_values) != 0) {
        printf("Failed to initialize matrix.\n");
        return 1;
    }
    int b_values[4] = { 5, 6, 7, 8 };
    if (init_matrix(&b, 2, 2, FROM_ARRAY, b_values) != 0) {
        printf("Failed to initialize matrix.\n");
        return 1;
    }
    Matrix actual;
    if (init_matrix(&actual, 2, 2, NO_VALUES, NULL) != 0) {
        printf("Failed to initialize matrix.\n");
        return 1;
    }
    matmul(&a, &b, &actual);

    Matrix expected;
    int expected_values[4] = { 19, 22, 43, 50 };
    if (init_matrix(&expected, 2, 2, FROM_ARRAY, expected_values) != 0) {
        printf("Failed to initialize matrix.\n");
        return 1;
    }

    if (!matrices_are_equal(&actual, &expected)) {
        printf("2x2 matmul was incorrect.\n");
        printf("Expected:\n");
        print_matrix(expected);
        printf("Actual:\n");
        print_matrix(actual);
    }

    return 0;
}

void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%*d", 3, m.data[i][j]);
        }
        printf("\n");
    }
}

bool matrices_are_equal(Matrix* a, Matrix* b) {
    if (a->rows != b-> rows || a->cols != b->cols) {
        return false;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            if (a->data[i][j] != b->data[i][j]) {
                return false;
            }
        }
    }

    return true;
}
