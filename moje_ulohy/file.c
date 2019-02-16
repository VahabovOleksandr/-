#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, M, *h, sum;
    int i, j;
    while (scanf("%d%d%d", &N, &K, &M) == 3) {
        sum = 0;
        h = (int*)malloc(M * sizeof(int));
        for (i = 0; i < M; i++) {
            scanf("%d", &h[i]);
        }
        for (i = 0; i < K; i++) {
            int max_ind = 0;
            for (j = 0; j < M; j++) {
                if (h[j] > h[max_ind]) {
                    max_ind = j;
                }
            }
            sum += h[max_ind];
            h[max_ind] = 0;
        }
    
        if (sum > N) {
            printf("Nie\n");
        } else {
            printf("Ano\n");
        }
        free(h);
    }
    return 0;
}