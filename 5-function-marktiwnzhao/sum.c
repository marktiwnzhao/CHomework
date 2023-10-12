/**
 * File: sum.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.10
 */

#include <stdio.h>
#include <math.h>

int Item(int item, int n);

int main() {
    int n = 0;
    int t = 0;
    scanf("%d%d", &n, &t);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += Item(0, i) * t;
    }

    printf("%d\n", sum);

  return 0;
}

int Item(int item, int n) {
    for (int i = 0; i < n; i++) {
        item += (int)pow(10, i);
    }
    return item;
}
