/**
 * File: josephus.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.1
 */
#include <stdio.h>
#define MAX 10000

int main() {
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    int t = n;
    int a[MAX] = {0};
    int b[MAX] = {0};
    int c[MAX] = {0};

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
        b[i] = k % (n - i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t - 1; ++j) {
            if (j + b[i] + 1 <= t) {
                c[j] = a[j + b[i]];
            } else {
                c[j] = a[j + b[i] - t];
            }
        }
        for (int u = 0; u < t; ++u) {
            a[u] = c[u];
            //printf("%d ", a[u]);
            c[u] = 0;
        }
        //printf("\n");
        t -= 1;
        if (t == 1) {
            break;
        }
    }

    //for (int i = 0; i < n; ++i) {
        printf("%d ", a[0]);
    //}
  return 0;
}