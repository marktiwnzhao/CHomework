#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 4500
int main() {
    char *str = malloc(MAX * sizeof(str));
    gets(str);
    char *str_1 = malloc(MAX * sizeof(str_1));
    while (gets(str_1) != NULL) {
        strcat(str, str_1);
        memset(str_1,0, sizeof(str_1));
    }

    int len = strlen(str);

    int true = 1;
    for (int i = 0; i < len; i++) {
        if (*(str + i) < 32 ||
            (*(str + i) > 33 && *(str + i) < 42) ||
            *(str + i) == 44 ||
            *(str + i) == 58 ||
            *(str + i) == 63 ||
            *(str + i) == 64 ||
            (*(str + i) > 90 && *(str + i) < 95) ||
            *(str + i) == 96 ||
            (*(str + i) > 122 && *(str + i) <= 127) ||
            (*(str + i) == '-' && *(str + i + 1) != ' ') ||
            (*(str + i) == '.' && *(str + i + 1) == '.')) {
            true = 0;
            break;
        }
        if (*(str + i) > 47 && *(str + i) < 58) {
            int j = i + 1;
            while (*(str + j) > 47 && *(str + j) < 58) {
                j++;
            }
            if(*(str + j) != ' ' && *(str + j) != ';' && *(str + j) != '.') {
                true = 0;
                break;
            }
        }
    }

    if (true == 0) {
        printf("Compile Error\n");
    } else {
        char *tmp = malloc(MAX * sizeof(tmp));
        for (int i = 0; i < len; i++) {
            if (*(str + i) == ' ') {
                continue;
            }
            if (*(str + i) == ';') {
                printf("\n");
                continue;
            }
            int k = 0;
            while (*(str + i) != ' ' && *(str + i) != ';' && *(str + i) != '\0') {
                *(tmp + (k++)) = *(str + i);
                i++;
            }
            *(tmp + k) = '\0';
            if (*tmp > 47 && *tmp < 58 ) {
                if (strchr(tmp, '.') != NULL) {
                    printf("float ");
                } else {
                    printf("integer ");
                }
            } else {
                if (strcmp(tmp, "const") == 0 || strcmp(tmp, "int") == 0 || strcmp(tmp, "float") == 0 ||
                    strcmp(tmp, "double") == 0 || strcmp(tmp, "long") == 0 || strcmp(tmp, "static") == 0 ||
                    strcmp(tmp, "void") == 0 || strcmp(tmp, "char") == 0 || strcmp(tmp, "extern") == 0 ||
                    strcmp(tmp, "return") == 0 || strcmp(tmp, "break") == 0 || strcmp(tmp, "enum") == 0 ||
                    strcmp(tmp, "struct") == 0 || strcmp(tmp, "typedef") == 0 || strcmp(tmp, "union") == 0 ||
                    strcmp(tmp, "goto") == 0) {
                    printf("reserved ");
                } else if (strcmp(tmp, "+") == 0 || strcmp(tmp, "-") == 0 || strcmp(tmp, "*") == 0 || strcmp(tmp, "/") == 0 ||
                    strcmp(tmp, "=") == 0 || strcmp(tmp, "==") == 0 || strcmp(tmp, "!=") == 0 || strcmp(tmp, ">=") == 0 ||
                    strcmp(tmp, "<=") == 0 || strcmp(tmp, "<") == 0 || strcmp(tmp, ">") == 0) {
                    printf("operator ");
                } else {
                    printf("variable ");
                }
            }
            i--;
            printf("%s\n", tmp);
            memset(tmp, 0, sizeof(tmp));
        }
        free(tmp);
    }
    free(str);
    free(str_1);

    return 0;
}
