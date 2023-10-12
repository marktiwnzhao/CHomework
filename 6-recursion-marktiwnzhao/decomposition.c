/**
 * File: decomposition.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.22
 */
#include <stdio.h>
#define MAX 35

void Dec(int m, int k, int n, int nums[]);
int main() {
    int numbers[MAX] = {0};
    int n = 0;
    scanf("%d", &n);
    Dec(1, 0, n, numbers);

  return 0;
}
//k:标识位，用来记录拆分到第几位，每拆一次，k++
//m：1.和n一起来决定来要拆分的次数
//2.把值赋给数组中的项
//3.保证字典序：后面拆出来的数字要大于等于前一次

void Dec(int m, int k, int n, int nums[]) {
    if (n == 0) {
        for (int i = 0; i < k; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }
    if (m <= n) {
        for (int i = m; i <= n; i++) {
            nums[k] = i;
            Dec(i, k + 1, n - i, nums);
        }
    }
}
