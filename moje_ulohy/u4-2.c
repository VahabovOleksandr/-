#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[52];

    while (scanf("%s", str) != EOF) {
        int max_v = 0, max_c = 0, flag = 0;
        int vowels = 0, consonants = 0, questions = 0, ind = 0, length = 0;

        while (str[length] != '\0') {
            length++;
        }
        int arr[length];

        while (str[ind] != '\0') {
            if (str[ind] == 'a' || str[ind] == 'e' || str[ind] == 'i' || str[ind] == 'o' || str[ind] == 'u' ||
                str[ind] == 'A' || str[ind] == 'E' || str[ind] == 'I' || str[ind] == 'O' || str[ind] == 'U') {
                arr[ind] = 0;
            } else if ((str[ind] >= 'A' && str[ind] <= 'Z') || (str[ind] >= 'a' && str[ind] <= 'z')) {
                arr[ind] = 1;
            } else if (str[ind] == '?') {
                arr[ind] = 2;
            }
            ind++;
        }

        for (int i = 0; i < length; i++) {
            if (arr[i] == 0) {
                vowels++;
                consonants = 0;
            } else if (arr[i] == 1) {  
                consonants++;
                vowels = 0;
            } else if (arr[i] == 2) {
                questions++;
                if ((i > 1) && (length - i > 3) && (arr[i - 1] == 0 && arr[i - 2] == 0) && (arr[i + 1] == 1 && arr[i + 2] == 1 && arr[i + 3] == 1 && arr[i + 4] == 1)) {
                    flag = 1;
                    printf("paci\n");
                    break;
                } else if ((i > 2) && (length - i > 1) && (arr[i - 1] == 1 && arr[i - 2] == 1 && arr[i - 3] == 1 && arr[i - 4] == 1) && (arr[i + 1] == 0 && arr[i + 2] == 0)) {
                    flag = 1;
                    printf("paci\n");
                    break;
                }
            }
    
            if (vowels > max_v) max_v = vowels;
            if (consonants > max_c) max_c = consonants;
        }

        // printf("%d %d %d\n", max_v, max_c, questions);
        if (flag == 0) {
            if (max_c > 4 || max_v > 2) {
                printf("paci\n");
            } else if (max_c + questions > 4 || max_v + questions > 2) {
                printf("neviem\n");
            } else {
                printf("nepaci\n");
            }
        }
    }

    return 0;
}