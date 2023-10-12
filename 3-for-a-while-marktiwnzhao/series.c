/*
 * File:binary.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.1
 */
#include <stdio.h>
#include <math.h>

int main() {
    double n = 0;
    double x = 0;
    scanf("%lf%lf", &n, &x);

    double sum = 0;
    double s = 1;
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            sum += 1;
        } else {
            s *= i;
            sum += pow(x, i) / s * 1.0;
        }
    }

    printf("%.3lf", sum);
    return 0;
}
