#include <stdlib.h>
#include <stdio.h>
#include <string.h>  // Добавляем для memset()

int heels(int height, int width, unsigned long long matrix[height][width]) {
    int i, j;
    memset(matrix, 0, sizeof(unsigned long long) * height * width);
    matrix[0][0] = 1;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (matrix[j][i] != 0) {
                if (j - 1 >= 0 && i + 1 < width) {
                    matrix[j - 1][i + 1] += matrix[j][i];
                }

                if (i + 1 < width) {
                    matrix[j][i + 1] += matrix[j][i];
                }

                if (j + 1 < height && i + 1 < width) {
                    matrix[j + 1][i + 1] += matrix[j][i];
                }
            }
        }
    }

    return matrix[0][width - 1];
}

int main() {
    int games, width, height;

    scanf("%d", &games);
    
    while (games-- > 0) {
        unsigned long long res = 0;
        scanf("%d%d", &width, &height);
        height++;
        width++;

        unsigned long long matrix[height][width];
        unsigned long long matrix2[height][width];

        res += heels(height, width, matrix);
        res -= heels(height - 1, width, matrix2);

        printf("%llu\n", res % 100000007);
    }

    return 0;
}
