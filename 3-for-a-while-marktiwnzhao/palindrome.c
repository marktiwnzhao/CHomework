/**
 * File: palindrome.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.1
 */
#include <stdio.h>
#include <string.h>
#define MAX 2001

int main() {
    int n = 0;
    char str[MAX];
    scanf("%d%s", &n, str);

    for(int i = 0, j = n - 1; i < j; i++, j--) {
        if (str[i] == '?') {
            str[i] = str[j];
        } else {
            str[j] = str[i];
        }
    }

    printf("%s", str);
    return 0;
}