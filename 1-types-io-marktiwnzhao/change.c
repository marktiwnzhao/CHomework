/**
 * File: change.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.15
 */
#include <stdio.h>
int main() {
  int money;
  scanf("%d", &money);
    printf("%d\n%d\n%d\n%d\n",money / 20,money /10 - (money / 20) * 2,money / 5 - (money / 10) * 2,money - (money / 5) * 5);






  return 0;
}

