#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Matrix Matrix;

struct Matrix {
    int rows;
    int cols;
    int** data;
};

void print_matrix(Matrix m);

void init_matrix(Matrix* m);

int main() {

    srand((unsigned int)time(NULL));

    Matrix a = {
        .rows = 2,
        .cols = 2
    };

    init_matrix(&a);

    print_matrix(a);

    return 0;
}

void init_matrix(Matrix* m) {
    m->data = malloc(sizeof *m->data * m->rows);
    for (int i = 0; i < m->cols; i++) {
        m->data[i] = malloc(sizeof *m->data[i] * m->cols);
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = rand() % 100;
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
