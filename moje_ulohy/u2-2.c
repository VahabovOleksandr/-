#include <stdio.h>
#include <stdlib.h>

int min_sum = 999;

void recursive(char *str, int res, int left, int pluses, int index) {
    if (str[index] == '\0') {
        if (left == res) {
            if (min_sum == -1 || pluses < min_sum) 
                min_sum = pluses;
        }
        return;
    }

    int num = 0;
    for (int i = index; str[index] != '\0'; i++) {
        num = num * 10 + (int)(str[i] - '0');

        recursive(str + 1, res, left + num, pluses + (index > 0), i + 1);
    }
}

int main() {

    char str[11];
    int res;
    
    while (scanf("%s %d", str, &res) == 2) {
        min_sum = -1;
        recursive(str, res, 0, 0, 0);

        if (min_sum == -1) 
            printf("IMPOSSIBLE\n");
        else 
            printf("%d\n", min_sum);
    }

    return 0;
}


