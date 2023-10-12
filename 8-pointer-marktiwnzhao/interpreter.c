/**
 * File: interpreter.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.6
 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 10
int main() {
    char *str = malloc(LEN * sizeof(*str));
    scanf("%s", str);
    int num = 0;
    int *res = &num;
    sscanf(str, "%x", res);
    printf("%ld\n%lu\n", *res, *res);
    float *p = (float *)res;
    printf("%f", *p);
    free(str);
    return 0;
}

