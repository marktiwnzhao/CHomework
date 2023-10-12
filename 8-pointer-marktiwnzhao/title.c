/**
 * File: title.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.6
 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 4200

int main(){
    char *str = malloc(LEN * sizeof(*str));
    gets(str);

    for (int k = 0; *(str + k) != '\0'; k++) {
        if ((k == 0 || *(str + k - 1) == ' ') && *(str + k) >= 97) {
            *(str + k) -= 32;
        }
        if (*(str + k) == ' ') {
            continue;
        }
        if (k > 0 && *(str + k - 1) != ' ' && *(str + k) <= 90) {
            *(str + k) += 32;
        }
    }
    for (int s = 0; *(str + s) != '\0'; s++) {
        printf("%c", *(str + s));
    }
    printf("\n");
    free(str);

  return 0;
}
