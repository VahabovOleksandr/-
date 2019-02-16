#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, A, B, i, j;
    int *T, *positions;
    while (scanf("%d", &N) == 1){
        int sum = 0;

        T = (int*)malloc(N * sizeof(int));
        for (i = 0; i < N; i++) {
            scanf("%d", &T[i]);
        }
        
        scanf("%d%d", &A, &B);
        B += 1;
        positions = (int*)malloc((B) * sizeof(int));

        positions[0] = 0;
        for (i = 1; i < B; i++) {
            int res = 0;
            for (j = 0; j < N; j++) {
                if (i - T[j] > -1 && positions[i - T[j]] == 0) {
                    res = 1;
                    break;
                }
            }
            positions[i] = res;
        }
        for (i = A; i < B; i++) {
            if (positions[i] == 1) sum++;
        }
        printf("%d\n", sum);

        free(T);
        free(positions);
    }
    
    return 0;
}
