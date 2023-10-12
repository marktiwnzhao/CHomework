//
// Created by Misaka on 2021/12/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char * str = malloc(205 * sizeof(char));
    char split_flag;
    char ** after = malloc(105 * sizeof(char *));
    char ** output = after;
    scanf("%s\n", str);
    scanf("%c", &split_flag);
    int row = 0;
    int n = 0;
    int k = 0;
    * output = malloc(105 * sizeof(char));
    while (*(str + k)) {
        if (*(str + k) != split_flag) {
            *(*(output + row) + n) = *(str + k);
            n ++;
        } else {
            row ++;
            * (output + row) = malloc(105 * sizeof(char));
            n = 0;
        }
        k ++;
    }

    int * pointer = malloc((row + 5) * sizeof(int));
    for (int i = 0; i < row + 1; i ++) {
        *(pointer + i) = i;
    }
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < row - i; j ++) {
            if (strcmp(*(output + *(pointer + j)), *(output + *(pointer + j + 1))) > 0) {
                int t = *(pointer + j);
                *(pointer + j) = *(pointer + j + 1);
                *(pointer + j + 1) = t;
            }
        }
    }

    for (int i = 0; i < row + 1; i ++) {
        int p = 0;
        while (*(*(output + *(pointer + i)) + p)) {
            printf("%c", *(*(output + *(pointer + i)) + p));
            p ++;
        }
        printf("\n");
    }

    for (int i = 0; i < row + 1; i ++) {
        free(*(after + i));
    }
    free(after);
    free(str);
    free(pointer);

    return 0;
}