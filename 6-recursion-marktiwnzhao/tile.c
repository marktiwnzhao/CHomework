/**
 * File: tile.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.16
 */
#include <stdio.h>
int Tile(int x);
int main(){
    int n = 0;
    scanf("%d", &n);

    printf("%d\n", Tile(n));
  return 0;
}

int Tile(int x) {
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
    return Tile(x - 1) + Tile(x - 2);
}
