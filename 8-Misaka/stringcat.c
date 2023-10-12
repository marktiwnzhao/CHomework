//
// Created by Misaka on 2021/12/3.
//

#include <stdio.h>
#include <stdlib.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    char ** s1 = malloc(10005 * sizeof(char *));
    char ** s2 = malloc(10005 * sizeof(char *));
    for (int i = 0; i < n; i ++) {
        *(s1 + i) = malloc(10005 * sizeof(char));
        *(s2 + i) = malloc(10005 * sizeof(char));
        scanf("%s %s", *(s1 + i), *(s2 + i));
    }
    for (int i = 0; i < n; i ++) {
        int len = 0;
        int tj = 0;
        while (*(*(s1 + i) + len)) {
            if (*(*(s1 + i) + len) == *(*(s2 + i))) {
                int q = len;
                while (*(*(s1 + i) + q) == *(*(s2 + i) + q - len) && *(*(s1 + i) + q)) {
                    q ++;
                }
                tj = q - len;
                if (*(*(s1 + i) + q) == '\0') {
                    for (int y = 0; y < q - len; y ++) {
                        *(*(s2 + i) + y) = '\0';
                    }
                }
            }
            len ++;
        }
        int w = 0;
        int len1 = 0;
        int len2 = 0;
        for(w = tj; *(*(s2 + i) + w) != '\0'; w++) {
            len1++;
        }
        for(w = 0; *(*(s1 + i) + w) != '\0'; w++) {
            len2++;
        }
        for(w = 0; w < len1; w++) {
            *(*(s1 + i) + len2 + w) = *(*(s2 + i) + w + tj);
        }
        printf("%s\n", *(s1 + i));
    }
    for (int i = 0; i < n; i ++) {
        free(*(s1 + i));
        free(*(s2 + i));
    }
    free(s1);
    free(s2);

    return 0;
}