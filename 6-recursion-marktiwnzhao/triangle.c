/**
 * File: triangle.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.15
 */
#include <stdio.h>
#include <math.h>
char stts[1050][2050] = {'\0'};

void Triangle(int a, int b, int c);
int main(){
    int n = 0;
    scanf("%d", &n);
    Triangle(n, 0, 0);
    for (int i = 0; i < pow(2, n); i++) {
        for (int j = 0; j < pow(2, n + 1); ++j) {
            if (stts[i][j] == '\0') {
                printf(" ");
            } else {
            printf("%c", stts[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

void Triangle(int a, int b, int c) {
    if (a == 1) {
        stts[b][c + 1] = '/';
        stts[b + 1][c] = '/';
        stts[b][c + 2] = '\\';
        stts[b + 1][c + 3] = '\\';
        stts[b + 1][c + 1] = '_';
        stts[b + 1][c + 2] = '_';
        return;
    }
    Triangle(a - 1, b, c + (int) pow(2, a - 1));
    Triangle(a - 1, b + (int) pow(2, a - 1), c);
    Triangle(a - 1, b + (int) pow(2, a - 1), c + (int) pow(2, a));
}
