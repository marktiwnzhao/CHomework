/**
 * File: binary.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.1
 */
#include <stdio.h>
#include <math.h>

int main() {
    int len = 0;
    scanf("%d", &len);
    char lens[31];
    scanf("%s", lens);



    long long int sum = 0;
    int m = 0;
    for (int i = 0; i < len; ++i) {
        m = lens[i] - '0';
        sum += m * pow(2, len - 1 - i);
    }

    printf("%lld", sum);
    return 0;
}
