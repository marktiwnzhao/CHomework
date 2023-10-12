//
// Created by Misaka on 2021/12/3.
//

#include <stdio.h>
#include <stdlib.h>

int main () {
    char * input = malloc(10000 * sizeof(char));
    gets(input);
    if (*input > 91) {
        *input -= 32;
    }
    int i = 1;
    while (*(input + i)) {
        if (*(input + i) < 91 && *(input + i) > 64) {
            *(input + i) += 32;
        } else if (*(input + i) == ' ') {
            if (*(input + i + 1) > 91) {
                *(input + i + 1) -= 32;
            }
            i ++;
        }
        i ++;
    }
    printf("%s", input);

    return 0;
}