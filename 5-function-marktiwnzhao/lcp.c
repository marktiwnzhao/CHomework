/**
 * File: lcp.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.11
 */
#include <stdio.h>
#include <string.h>
#define LEN 105
int Lcp (const char s1[], const char s2[]);

int main() {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    char str[LEN][LEN] = {' '};
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    int qnum[LEN][2] = {0};
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &qnum[i][j]);
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", Lcp(str[qnum[i][0] - 1], str[qnum[i][1] - 1]));
    }
    return 0;
}

int Lcp (const char s1[], const char s2[]) {
    int ns1 = 0;
    int ns2 = 0;
    while (s1[ns1] != '\0') {
        ns1++;
    }
    while (s2[ns2] != '\0') {
        ns2++;
    }
    int x = 1;
    while (x <= ns1 && x <= ns2) {
        if (strncmp(s1, s2, x) != 0) {
            return x - 1;
        }
        x++;
    }
    return x - 1;
}
