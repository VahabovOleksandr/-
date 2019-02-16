#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 4;  // Количество бит (например, для 4-битных значений)
    int max_val = (1 << n);  // 2^n

    for (int i = 0; i < max_val; i++) {
        printf("num: %d, : ", i);

        for (int j = n - 1; j >= 0; j--) {
            printf("%d", (i >> j) & 1);
        }
        printf("\n");
    }
}


// #define MAX_LEN 10

// int length(char *str) {
//     int length = 0;
//     while (str[length] != '\0') length++;
//     return length;
// }

// // Функция вычисляет минимальное количество "+" для достижения target_sum
// int min_additions_to_sum(char *number_str, int target_sum) {
//     int n = strlen(number_str);
//     int min_pluses = 999; // Заменяем INT_MAX на большое число
    
//     int max_masks = 1 << (n - 1); // 2^(n-1)

//     for (int mask = 0; mask < max_masks; mask++) {
//         int sum = 0, num = 0, plus_count = 0;
        
//         for (int i = 0; i < n; i++) {
//             num = num * 10 + (number_str[i] - '0'); // Собираем число
            
//             if (i == n - 1 || (mask & (1 << i))) { // Вставляем "+"
//                 sum += num;
//                 num = 0;
//                 if (i != n - 1) plus_count++;
//             }
//         }

//         if (sum == target_sum && plus_count < min_pluses) {
//             min_pluses = plus_count;
//         }
//     }
    
//     return (min_pluses == 999) ? -1 : min_pluses;
// }

// int main() {
//     char number_str[MAX_LEN + 1];
//     int target_sum;
    
//     while (scanf("%s %d", number_str, &target_sum) == 2) {
//         int result = min_additions_to_sum(number_str, target_sum);
//         if (result == -1) {
//             printf("IMPOSSIBLE\n");
//         } else {
//             printf("%d\n", result);
//         }
//     }
    
//     return 0;
// }
