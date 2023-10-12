/**
 * File: insertion-sort.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.3
 */
#include <stdio.h>
#define MAX 200
int a[MAX] = {0};

int main(){
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", a[0]);

    for (int i = 1; i < n; i++) {
        int m = a[i];
        int j = 0;
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > m) {
                a[j + 1] = a[j];
            } else {
                break;
            }
        }
        a[j + 1] = m;
        for (int k = 0; k <= i; k++) {
        printf("%d ", a[k]);
        }

        printf("\n");
    }



    /*for (int i = 1; i <= n; ++i) {
        int j = 0;
        while (a[j][i] < a[i - 1][0] && j < i) {
            a[j][i] = a[j][i - 1];
            j++;
        }
        if (j) {
            a[j - 1][i] = a[i - 1][0];
            while (j < i) {
              a[j][i] = a[j - 1][i - 1];
              j++;
            }
        } else {
            a[j][i] = a[i - 1][0];
            j++;
            while (j < i) {
                a[j][i] = a[j - 1][i - 1];
                j++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < i; k++) {
            printf("%d ",a[k][i]);
        }
        printf("\n");
    }*/
    return 0;
}