/**
 * File: sudoku.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.4
 */
#include <stdio.h>
#define LEN 9

int main() {
    int sudu[LEN][LEN] = {0};
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            scanf("%d", &sudu[i][j]);
        }
    }
    int ry = 1, cy = 1, sy = 1;
    for (int row = 0; row < LEN; row++) {
        for (int j = 0; j < LEN - 1; j++) {
            for (int k = j + 1; k < LEN; k++) {
                if (sudu[row][j] == sudu[row][k]) {
                    ry = 0;
                    goto w1;
                }
            }
        }
    }
    w1:
    for (int col = 0; col < LEN; col++) {
        for (int j = 0; j < LEN - 1; j++) {
            for (int k = j + 1; k < LEN; k++) {
                if (sudu[col][j] == sudu[col][k]) {
                    cy = 0;
                    goto w2;
                }
            }
        }
    }
    w2:
    for (int u = 0; u < 2; u++) {
        for (int row = 0; row < LEN; row++) {
            for (int col = 0; col < LEN; col++) {
                if (row != (row / 3) * 3 + u && col != (col / 3) * 3) {
                    if (sudu[row][col] == sudu[(row / 3) * 3 + u][(col / 3) * 3]) {
                        sy = 0;
                        goto w3;
                    }
                }
            }
        }
    }
    w3:
    for (int u = 0; u < 2; u++) {
        for (int row = 0; row < LEN; row++) {
            for (int col = 0; col < LEN; col++) {
                if (row != (row / 3) * 3 && col != (col / 3) * 3 + u) {
                    if (sudu[row][col] == sudu[(row / 3) * 3][(col / 3) * 3 + u]) {
                        sy = 0;
                        goto w4;
                    }
                }
            }
        }
    }
    w4:
    if (ry == 0 || cy == 0 || sy == 0) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

  return 0;
}