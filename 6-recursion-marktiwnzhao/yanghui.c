/**
 * File: yanghui.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.22.15
 */

#include <stdio.h>

long long C(int a, int b);

int main() {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d\n", C(a - 1, b - 1));
    return 0;
}

long long C(int a, int b) {
    if (b == 0 || a == b) {
        return 1;
    }
    return C(a - 1, b - 1) + C(a - 1, b);
}
