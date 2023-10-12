/**
 * File: magic-square.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.11
 */
#include <stdio.h>
#define MAX 5000
int num[MAX][MAX] = {0};

int main(){
    int n = 0;
    scanf("%d", &n);

    int u = 0;
    int v = n / 2;
    num[u][v] = 1;
    for (int i = 2; i <= n * n; i++) {
        int uj = u;
        int vj = v;
        u--;
        v++;
        if (u < 0) {
            u = n - 1;
        }
        if (v > n - 1) {
            v = 0;
        }
        if (num[u][v] != 0) {
           u = uj + 1;
           v = vj;
        }
        num[u][v] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}
