//
// Created by Misaka on 2021/12/3.
//

#include <stdio.h>
#include <stdlib.h>

int main () {
    char * S = malloc(100005);
    char * T = malloc(100005);
    scanf("%s\n", S);
    scanf("%s", T);
    //测量T长度
    int size = 0;
    while (*(T + size)) {
        size ++;
    }
    int i = 0;
    while (*(S + i)) {
        if (*(S + i) == *T) {
            int save_i = i;
            int j = 0;
            int tj = 0; //统计相同字符长度
            while (*(S + i) == *(T + j) && *(S + i)) {
                tj ++;
                i ++;
                j ++;
            }
            i = save_i;
            if (tj == size) {
                printf("%d ", i);
            }
        }
        i ++;
    }

    return 0;
}