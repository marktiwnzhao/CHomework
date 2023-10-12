//
// Created by Misaka on 2021/12/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    char * input = malloc(8 * sizeof(char));
    char * bin = malloc(32 * sizeof(char));
    scanf("%s", input);
    for (int i = 0; i < 8; i ++) {
        for (int j = 4 * i + 3; j >= 4 * i; j --) {
            if (*(input + i) < 58) {
                *(bin + j) = (*(input + i) - 48) % 2 + 48;
                *(input + i) = (*(input + i) - 48) / 2 + 48;
            } else {
                *(bin + j) = (*(input + i) - 87) % 2 + 48;
                *(input + i) = (*(input + i) - 87) / 2 + 48;
            }
        }
    }

    //十进制整数
    long long int dec = 0;
    if (*bin == '1') {
        printf("-");
        char * bin_after = malloc(32 * sizeof(char));
        for (int i = 31; i >= 0; i --) {
            *(bin_after + i) = !(*(bin + i) - 48) + 48;
        }
        for (int i = 31; i >= 1; i --) {
            dec += (*(bin_after + i) - 48) * pow(2, 31 - i);
        }
        dec ++;
        printf("%lld", dec);
        free(bin_after);
    } else {
        for (int i = 31; i >= 0; i --) {
            dec += (*(bin + i) - 48) * pow(2, 31 - i);
        }
        printf("%lld", dec);
    }

    printf("\n");


    //十进制无符号整数
    long long int udec = 0;
    for (int i = 31; i >= 0; i --) {
        udec += (*(bin + i) - 48) * pow(2, 31 - i);
    }
    printf("%lld", udec);
    printf("\n");


    //32位浮点数
    double flo = 0;
    if (*bin == '1') {
        printf("-");
    }
    double exp = 0;
    double fra = 0;
    for (int i = 8; i >= 1; i --) {
        exp += (*(bin + i) - 48) * pow(2, 8 - i);
    }
    for (int i = 31; i >= 9; i --) {
        fra += (*(bin + i) - 48) * pow(2, -(i - 8));
    }
    if (exp == 0) {
        flo = fra * pow(2, exp - 126);
    } else {
        flo = (1 + fra) * pow(2, exp - 127);
    }
    printf("%.6f", flo);
    printf("\n");


    free(input);

    return 0;
}