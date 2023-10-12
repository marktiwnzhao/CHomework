//
// Created by 赵政杰 on 2021/11/23.
//
#include <stdio.h>
#define MAX 1005
int matrix[MAX][MAX] = {0};

int main() {
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int col[MAX] = {0};
    int colmax = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > col[j]) {
                col[j] = matrix[i][j];
            }
        }
        if (col[j] > colmax) {
            colmax = col[j];
        }
    }


    int len[MAX] = {0};
    int lenmax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > len[i]) {
                len[i] = matrix[i][j];
            }
        }
        if (len[i] > lenmax) {
            lenmax = len[i];
        }
    }

    for (int i = colmax; i > 0; i--) {
        for (int j = 0; j < m; j++) {
            if (i == col[j]) {
                printf("*");
                col[j]--;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int j = lenmax; j > 0; j--) {
        for (int i = 0; i < n; i++) {
            if (j == len[i]) {
                printf("*");
                len[i]--;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
