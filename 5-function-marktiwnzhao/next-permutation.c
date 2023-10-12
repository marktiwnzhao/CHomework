/**
 * File: next-permutation.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.11
 */
#include <stdio.h>
#define MAX 5000


int main(){
    int n = 0;
    int numbers[MAX] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }

    int m = 1;
    for (int i = n; i > 1; i--) {
        if (numbers[i - 1] > numbers[i]) {
            m++;
        } else {
            break;
        }
    }

    int px = 0;
    int index = 0;
    for (int i = n; i > n - m; i--) {
        if (numbers[i] > numbers[n - m]) {
                px = numbers[i];
                index = i;
                break;
        }
    }

    numbers[index] = numbers[n - m];
    numbers[n - m] = px;



    int new_numbers[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        if (i <= n - m) {
            new_numbers[i] = numbers[i];
        } else {
            new_numbers[i] = numbers[2 * n - m + 1 - i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", new_numbers[i]);
    }
    return 0;
}
