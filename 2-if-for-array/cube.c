/**
 * File: cube.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.22
 */
#include <stdio.h>
int main() {
    long long int n = 0;
    long long int i = 0;
    scanf("%lld", &n);
    int a[100000] = {0};
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long int s = 0;
    long long int t = n;
    for (i =1; i <= n; i++) {
        s += t * a[i];
        t--;
    }
    printf("%lld", s);
    return 0;
}