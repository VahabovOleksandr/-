#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, i;
    int *arr;

    while (scanf("%d", &N) == 1) {
        int ind1 = 0, ind2 = N - 1, i, j, num = 0;
        arr = (int*)malloc(N * sizeof(int));
        
        for (i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, N, sizeof(int), compare);

        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        for (i = N - 1; i > -1; i--) {
            printf("ZOV\n");
            if (arr[i] > 199) {
                printf("ALLO1\n");
                num++;
                ind2--;
            } else {
                break;
            }
        }
        for (i = 0; i < N; i++) {
            if (ind1 == ind2) {
                num++;
                printf("ALLO2\n");
                break;
            } else if (ind1 > ind2) {
                break;
            }
            if (arr[ind1] + arr[ind2] < 301) {
                printf("ALLO3\n");
                num++;
                ind1++;
                ind2--;
            } else {
                printf("ALLO4\n");
                num++;
                ind2--;
            }
        }

        printf("%d\n", num);
        free(arr);
    }

    return 0;
}