/**
 * File: inverse.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */
#include <stdio.h>
int main() {
  int number;
    scanf("%d", &number);
  int a = number / 100;
  int b = (number % 100) / 10;
  int c = (number % 100) % 10;
    printf("%d%d%d\n",c,b,a);
  return 0;
}

