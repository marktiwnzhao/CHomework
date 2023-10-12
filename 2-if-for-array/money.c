/**
 * File: money.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.22
 */
#include <stdio.h>
int main(){
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int a = 0;
    int m = 0;
    int s1 = 0;
    int s2 = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &m, &a);
        if (m == 1) {
            s1 += a;
        } else {
            s2 += a;
        }
    }
    printf("%d", s2 - s1);

  return 0;
}