/**
 * File: calculator.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.20.23
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    long long int a = 0;
    long long int b = 0;
    char op[100];
    while (scanf("%lld %s %lld", &a , op, &b) != EOF) {
       if (strncmp(op, "+", 1) == 0) {
                printf("%lld\n", a + b);
       } else if (strncmp(op, "-", 2) == 0) {
           printf("%lld\n", a - b);
       } else if (strncmp(op, "*", 2) == 0) {
           printf("%lld\n", a * b);
       } else if (strncmp(op, "/", 2) == 0) {
           printf("%lld\n",  a / b);
       } else if (strncmp(op, "/*", 3) == 0) {
           printf("%.3f\n", (double) a / (double) b);
       } else if (strncmp(op, "**", 3) == 0) {
           printf("%lld\n",(int)pow(a, b));
       } else if (strncmp(op, "%", 2) == 0) {
           printf("%lld\n", a % b);
       }
    }
    return 0;
}