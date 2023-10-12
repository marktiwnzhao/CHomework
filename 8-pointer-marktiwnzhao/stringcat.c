/**
 * File: stringcat.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.6
 */
#include <stdlib.h>
#include <stdio.h>
#define MAX 2005
void MyStrcat(char *p_1, char *p_2);
int main(){
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char *str_1 = malloc(MAX * sizeof(*str_1));
        char *str_2 = malloc(MAX * sizeof(*str_2));
        scanf("%s %s", str_1, str_2);
        int len_1 = 0;
        while (*(str_1 + len_1) != '\0') {
            len_1++;
        }
        int len_2 = 0;
        while (*(str_2 + len_2) != '\0') {
            len_2++;
        }
        //printf("%d %d\n", len_1, len_2);

        for (int s = 0; s < len_1; s++) {
            int k = 1;
            for (int j = s; j < len_1 && j - s < len_2; j++) {
                if (*(str_1 + j) != *(str_2 + j - s)) {
                    k = 0;
                    break;
                }
            }
            if (k) {
                for (int m = s; m < s + len_2; m++) {
                    *(str_1 + m) = *(str_2 + m - s);
                }
                for (int u = 0; u < s + len_2; u++) {
                    printf("%c", *(str_1 + u));
                }
                printf("\n");
                break;
            }
        }
        free(str_1);
        free(str_2);
    }

    return 0;
}

void MyStrcat(char *p_1, char *p_2) {
    int len_1 = 0;
    while (*(p_1 + len_1) != '\0') {
        len_1++;
    }
    int len_2 = 0;
    while (*(p_2 + len_2) != '\0') {
        len_2++;
    }
    printf("%d %d", len_1, len_2);
    for (int i = 0; i < len_1; i++) {
        int k = 1;
        for (int j = i; j < len_1 && j - i < len_2; j++) {
            if (*(p_1 + j) != *(p_2 + j - i)) {
                k = 0;
                break;
            }
        }
        if (k) {
            for (int m = i; m < i + len_2; m++) {
                *(p_1 + m) = *(p_2 + m - i);
            }
            break;
        }
    }
    printf("%s\n", p_1);
}
