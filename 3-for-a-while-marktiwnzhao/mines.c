/**
 * File: mines.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.2
 */
#include <stdio.h>
#define MAX 105

int main() {
    int n = 0;
    scanf("%d", &n);
    char str[MAX][MAX];
    for (int row = 0; row < n; row++) {
            scanf("%s", str[row]);
    }

    int nums[MAX][MAX];
    for (int row = 0; row <= n + 1; row++) {
        for (int col = 0; col <= n + 1; col++) {
            if (str[row - 1][col - 1] == '*') {
                nums[row][col] = 1;
            } else {
                nums[row][col] = 0;
            }

        }
    }
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            int sum = nums[row - 1][col - 1]
                    + nums[row - 1][col]
                    + nums[row - 1][col + 1]
                    + nums[row][col - 1]
                    + nums[row][col + 1]
                    + nums[row + 1][col - 1]
                    + nums[row + 1][col]
                    + nums[row + 1][col + 1];
            if (nums[row][col] != 1) {
                printf("%d", sum);
            }  else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}