/**
 * File: once.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.22
 */
#include <stdio.h>
int main(){
    int n =0;
    scanf("%d", &n);
    int a[199999] = {0};
    for (int i = 1; i < 2 * n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= 2 * n - 1; i++) {
        if (a[i] > 0) {
        for (int j = i + 1; j <= 2 * n; j++) {
            if (a[i] == a[j]) {
                a[i] = 0;
                a[j] = 0;
                break;
            }
        }
        }
    }
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (a[i] != 0) {
            printf("%d", a[i]);
        }
    }
}