/**
 * File: substr.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.6
 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 100005
int main(){
    char *str_S = malloc(LEN * sizeof(str_S));
    char *str_T = malloc(LEN * sizeof(str_T));
    scanf("%s %s", str_S, str_T);
    int len_T = 0;
    while (*(str_T + len_T) != '\0') {
        len_T++;
    }
    int len_S = 0;
    while (*(str_S + len_S) != '\0') {
        len_S++;
    }
    for (int i = 0; i <= len_S - len_T; i++) {
        int k = 1;
        for (int j = 0; j < len_T; j++) {
            if (*(str_S + i + j) != *(str_T + j)) {
                k = 0;
                break;
            }
        }
        if (k) {
            printf("%d ", i);
        }
    }
    free(str_S);
    free(str_T);
    return 0;
}
