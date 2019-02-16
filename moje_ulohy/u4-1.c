#include <stdlib.h>
#include <stdio.h>

long long heels(int height, int width, long long **matrix) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = 1;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (matrix[j][i] != 0 && j < width - i) {
                matrix[j][i] %= 100000007;

                if (j - 1 == 0 && i + 1 == width - 1) {
                    matrix[j - 1][i + 1] += matrix[j][i];
                } else if (j - 1 > 0 && i + 1 != width) {
                    matrix[j - 1][i + 1] += matrix[j][i];
                }

                if (i + 1 != width && j > 0) {
                    matrix[j][i + 1] += matrix[j][i];
                }

                if (i + 1 != width && j + 1 != height) {
                    matrix[j + 1][i + 1] += matrix[j][i];
                }
            }
        }
    }

    return matrix[0][width - 1];
}

int main() {
    int games, width, height, i, j;

    scanf("%d", &games);
    
    while (games-- != 0) {
        long long res = 0;
        long long num1 , num2;

        scanf("%d%d", &width, &height);
        height++;
        width++;

        long long **matrix = (long long **)malloc(height * sizeof(long long *));
        for (i = 0; i < height; i++) {
            matrix[i] = (long long *)malloc(width * sizeof(long long));
        }
        num1= heels(height, width, matrix);
        for (i = 0; i < height; i++) {
            free(matrix[i]);
        }
        free(matrix);


        long long **matrix2 = (long long **)malloc((height - 1) * sizeof(long long *));
        for (i = 0; i < (height - 1); i++) {
            matrix2[i] = (long long *)malloc(width * sizeof(long long));
        }
        num2= heels(height - 1, width, matrix2);
        for (i = 0; i < (height - 1); i++) {
            free(matrix2[i]);
        }
        free(matrix2);

        res = (num1 - num2);
        if (res < 0) {
            res += 100000007;
        }
        printf("%lld\n", res);
    }

    return 0;
}
