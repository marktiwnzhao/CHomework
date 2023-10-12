//
// Created by 赵政杰 on 2021/11/25.
//
#include <stdio.h>
#include <math.h>
#define MAX 105
int nums[MAX] = {0};
int Max(int m, int n);
int main() {
    int len = -1;
    while (scanf("%d", &nums[++len]) != EOF);

    int nums_2[100] = {0};
    for (int i = 0; i < len - 1; i++) {
        nums_2[i] = abs(Max(0, i) - Max(i + 1, len - 1));
    }
    int max = 0;
    for (int i = 0; i < len - 1; i++) {
        if (nums_2[i] > max) {
            max = nums_2[i];
        }
    }
    printf("%d\n", max);
    return 0;
}
int Max(int m, int n) {
    int max = nums[m];
    for (int i = m + 1; i <= n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}