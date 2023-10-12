//
// Created by Misaka on 2021/12/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * Judgement (char * str) {
    if (!strcmp(str, "const") || !strcmp(str, "int") || !strcmp(str, "float") || !strcmp(str, "double")
        || !strcmp(str, "long") || !strcmp(str, "static") || !strcmp(str, "void") || !strcmp(str, "char")
        || !strcmp(str, "extern") || !strcmp(str, "return") || !strcmp(str, "break") || !strcmp(str, "enum")
        || !strcmp(str, "struct") || !strcmp(str, "typedef") || !strcmp(str, "union") || !strcmp(str, "goto"))
    {
        return "reserved ";
    }
    if (!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/")
        || !strcmp(str, "=") || !strcmp(str, "==") || !strcmp(str, "!=") || !strcmp(str, ">=")
        || !strcmp(str, "<=") || !strcmp(str, ">") || !strcmp(str, "<"))
    {
        return "operator ";
    }
    if (*str == '.') {
        int k = 1;
        while (*(str + k)) {
            if (*(str + k) > 57 || *(str + k) < 48) {
                return NULL;
            }
            k ++;
        }
        return "float ";
    }
    if (*str <= 57 && *str >= 48) {
        int k = 1;
        int n = 0;
        while (*(str + k)) {
            if (*(str + k) > 57 || *(str + k) < 48) {
                if (*(str + k) == '.') {
                    n ++;
                } else {
                    return NULL;
                }
            }
            k ++;
        }
        if (n == 0) {
            return "integer ";
        } else if (n == 1) {
            return "float ";
        } else {
            return NULL;
        }
    }
    if (*str == '_') {
        int k = 1;
        int n = 0;
        while (*(str + k)) {
            if ((*(str + k) >= 65 && *(str + k) <= 90) || (*(str + k) >= 97 && *(str + k) <= 122)) {
                n ++;
            }
            k ++;
        }
        if (n == 0) {
            return NULL;
        }
    }
    if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122) || (*str == '_')) {
        int k = 1;
        while (*(str + k)) {
            if (((*(str + k) < 65) || (*(str + k) > 90)) && ((*(str + k) < 97) || (*(str + k) > 122)) && (*(str + k) != '_')
                && (*(str + k) > 57) || (*(str + k) < 48)) {
                return NULL;
            }
            k ++;
        }
        return "variable ";
    }
    if (*str == '\0' || *str == '\n') {
        return "";
    }
    return NULL;
}

int main () {
    char ** input = malloc(5005);
    for (int i = 0; i < 5005; i ++) {
        *(input + i) = malloc(5005);
    }
    int row = 0;
    while (fgets(*(input + row), 5005, stdin) != NULL) {
        row ++;
    }

    char *** out = malloc(5005 * sizeof(char **));
    for (int i = 0; i < 5005; i ++) {
        *(out + i) = malloc(5005 * sizeof(char *));
    }


    int flag = 1;
    for (int r = 0; r < row; r ++) {
        char **after = malloc(5005 * sizeof(char *));
        char **output = after;
        int n = 0;
        int line = 0;
        int k = 0;
        *output = malloc(5005 * sizeof(char));
        while (*(*(input + r) + k)) {
            if ((*(*(input + r) + k) != ' ') && (*(*(input + r) + k) != ';') && (*(*(input + r) + k) != '\n')) {
                *(*(output + line) + n) = *(*(input + r) + k);
                n ++;
            } else {
                line ++;
                *(output + line) = malloc(5005 * sizeof(char));
                n = 0;
            }
            k ++;
        }

        int j = 0;
        while (*(output + j)) {
            if (Judgement(*(output + j)) == NULL) {
                flag  = 0;
                break;
            } else {
                *(*(out + r) + j) = malloc(10);
                *(*(out + r) + j) = Judgement(*(output + j));
            }
            j ++;
        }
        if (flag == 0) {
            printf("Compile Error");
            break;
        }
    }


    if (flag) {
        for (int r = 0; r < row; r ++) {
            int l = 0;
            while (*(*(out + r) + l)) {
                printf("%s", *(*(out + r) + l));
                l ++;
            }
            printf("\n");
        }
    }

    return 0;
}