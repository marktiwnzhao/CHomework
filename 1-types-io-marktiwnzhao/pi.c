/**
 * File: pi.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */
#include <stdio.h>
#include <math.h>

int main() {
    double pi1 = 16 * atan(0.2) -4 * atan(1.0 /239);
    double pi2 = log(pow(640320.0,3) + 744) / sqrt(163.0);
    printf("%.15lf\n%.15lf",pi1,pi2);
    return 0;
}