/**
 * File: inverse.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */

#include <stdio.h>

int main(){
    double frequency;
    scanf("%lf", &frequency);
    const double h = 6.626e-34;
    printf("%.2e",h * frequency);

    return 0;
}