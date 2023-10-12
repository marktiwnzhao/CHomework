/**
 * File: ternary-search.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.11
 */
#include <stdio.h>
#include <math.h>
double Fx (double x, const int a[], int n);

int main(){
    int N = 0;
    scanf("%d", &N);
    int a[30] = {0};
    for (int i = 0; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    double l = 0;
    double r = 0;
    scanf("%lf %lf", &l, &r);

    while (r - l > 1e-8) {
        double p1 = l + (r - l) * 1.0 / 3;
        double p2 = l + (r - l) * 2.0 / 3;

        if (Fx(p1, a, N) >= Fx(p2, a, N)) {
            r = p2;
        } else {
            l = p1;
        }
    }

    printf("%lf\n", r);

    return 0;
}

double Fx (double x, const int a[], int n) {
    double fx = 0;
    for (int i = 0; i <= n; i++) {
       fx += a[i] * pow(x, n - i);
    }
    return fx;
}
