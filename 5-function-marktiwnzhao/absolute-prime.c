/**
 * File: absolute-prime.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.10
 */
#include <stdio.h>
#include <math.h>

int AbsolutePrime (int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (AbsolutePrime(i)) {
            int x = 0;
            int j = i;
            while (j != 0) {
                x = x * 10 + j % 10;
                j /= 10;
            }
            if (AbsolutePrime(x)) {
                count++;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}

int AbsolutePrime (int n) {
    for (int i = 2; i <= sqrt(n + 0.5); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}