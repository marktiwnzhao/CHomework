/**
 * File: integration.c
 *
 * Author:zhaozhengjie
 * ID:211250209
 * Date:2021.11.17
 */
#include <stdio.h>
#include <math.h>
int n = 0;
int p = 0;
int as[25] = {0};
double a = 0;
double b = 0;
double F(double x);
double Inte(double a1, double b1);
double S(double a2, double b2);
int main(){
    scanf("%d %d", &n, &p);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &as[i]);
    }
    scanf("%lf %lf", &a, &b);
    printf("%f", S(a, b));

  return 0;
}
double F(double x) {
    double fx = 0;
    for (int i = 0; i <= n; i++) {
        fx += as[i] * pow(x, i);
    }
    return pow(fx, p);
}

double Inte(double a1, double b1) {
    return (4 * F((a1 + b1) / 2) + F(a1) + F(b1)) / 6 * (b1 - a1);
}

double S(double a2, double b2) {
    double s = Inte(a2, b2);
    double sl = Inte(a2, (a2 + b2) / 2);
    double sr = Inte((a2 + b2) / 2, b2);
    if (fabs(sl + sr - s) <= 1e-5) {
        return sl + sr + (sl + sr - s) / 15;
    }
    else {
        return S(a2, (a2 + b2)/ 2) + S((a2 + b2) / 2, b2);
    }

}

