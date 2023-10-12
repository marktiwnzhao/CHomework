/**
 * File: gray.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */

#include <stdio.h>

int main() {
  int number;
    scanf("%d", &number);
  int a = number % 2;
  int b = (number / 2) % 2;
  int c = ((number / 2) / 2) % 2;
  int d = (((number / 2) / 2) / 2) % 2;
    printf("%d%d%d%d\n",d,d^c,c^b,b^a);



    return 0;
}