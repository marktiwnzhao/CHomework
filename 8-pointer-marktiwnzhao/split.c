/**
 * File: split.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.7
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **split (const char *str, char del);
int main() {
    char *str = malloc(20000 * sizeof(str));
    scanf("%s ", str);
    char del;
    scanf("%c", &del);
    char **res = split(str, del);
    for (int i = 0; *(res + i) != NULL; i++) {
        printf("%s\n", *(res + i));
    }
    free(str);
    free(res);

  return 0;
}



char **split (const char *str, char del) {
    int len = strlen(str);
    char *str_1 = malloc((len + 1) * sizeof(str_1));
    strcpy(str_1, str);
    *(str_1 + len) = '\0';
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (*(str + i) == del) {
            count++;
        }
    }
    char **p = (char **)malloc((count + 1) * sizeof(char *));
    char *tmp = malloc((len + 1) * sizeof(tmp));
    int num = 0;
    for (int i = 0; i < len; i++) {
        *(p + num) = str_1 + i;
        while (*(str_1 + i) != '\0') {
            i++;
        }
        num++;
    }
    *(p + num) = NULL;
    char *tmep = NULL;
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (strcmp(*(p + i), *(p + j)) > 0) {
                tmep = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = tmep;
            }
        }

    }
    free(str_1);
    return p;
}