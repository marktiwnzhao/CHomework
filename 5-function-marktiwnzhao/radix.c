/**
 * File: radix.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.11
 */
#include <stdio.h>

int DecimalToTen (int a, int x);
int ItemMax (int x);

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d", &a, &b, &c);
    int max = ItemMax(a);
    if (max <= ItemMax(b)) {
        if (ItemMax(b) <= ItemMax(c)) {
            max = ItemMax(c);
        } else {
            max = ItemMax(b);
        }
    } else {
        if (max <= ItemMax(c)) {
            max = ItemMax(c);
        }
    }
    int is_true = 1;
    for (int i = max + 1; i <= 40; i++) {
        if (DecimalToTen(a, i) * DecimalToTen(b, i) == DecimalToTen(c, i)) {
            printf("%d\n", i);
            is_true = 0;
            break;
        }
    }
    if (is_true) {
        printf("0\n");
    }


  return 0;
}
int DecimalToTen (int a, int x) {
    return a / 10 * x + a % 10;
}
int ItemMax (int x) {
    if (x / 10 <= x % 10) {
        return x % 10;
    } else {
        return x / 10;
    }
}
