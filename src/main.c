#include <stdio.h>

int main() {
    int matrix[2][2];

    // Assign values like so:
    // 1 2
    // 3 4
    int value = 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            matrix[i][j] = value;
            value++;
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%*d", 2, matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
