// #include <stdio.h>
// #include <stdlib.h>

// struct 

// int main() {
//     char str[50];

//     scanf("%s", str);

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 50

int factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int combinations(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int count_evaluations(const char *str, int *index) {
    if (isdigit(str[*index]) || (str[*index] == '-' && isdigit(str[*index + 1]))) {
        while (*index < strlen(str) && (isdigit(str[*index]) || str[*index] == '-')) {
            (*index)++;
        }
        return 1;
    }

    if ((str[*index] == '/' || str[*index] == '*' || str[*index] == '+') 
        && (isdigit(str[*index + 1]) && (str[*index + 2] == '\n' || str[*index + 2] == '\0'))) {
        return 0;
    }

    int res = 0, znaky = 0, digits = 0;
    int ind = *index;

    while (str[ind] == '/' || str[ind] == '*' || str[ind] == '+' || str[ind] == '-') {
        ind++;
        znaky++;
    }

    while (str[ind] != '\0') {
        ind++;
        digits++;
    }

    return combinations(digits - 1, znaky);
}

int main() {
    char str[52];
    while(scanf("%s", str) != 0) {
        int index = 0;
        int result = count_evaluations(str, &index);
        
        printf("count: %d\n", result);
    }
    
    return 0;
}
