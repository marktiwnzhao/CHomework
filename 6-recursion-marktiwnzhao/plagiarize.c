/**
 * File: plagiarize.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.16
 */
#include <stdio.h>
int f[100005] = {0};
int Find(int x);

int main(){
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", Find(i));
    }

  return 0;
}

int Find(int x) {
    if (f[x] == x) {
        return x;
    }
    return Find(f[x]);
}