#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int** data;
};

void print_matrix(struct Matrix m);

int main() {

    struct Matrix m = {
        .rows = 2,
        .cols = 2
    };

    m.data = malloc(sizeof *m.data * m.rows);
    for (int i = 0; i < m.cols; i++) {
        m.data[i] = malloc(sizeof *m.data[i] * m.cols);
    }

    int v = 5;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            m.data[i][j] = v;
            v++;
        }
    }

    print_matrix(m);

    return 0;
}

void print_matrix(struct Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%*d", 2, m.data[i][j]);
        }
        printf("\n");
    }
}
