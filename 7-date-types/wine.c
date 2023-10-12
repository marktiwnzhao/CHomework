//
// Created by 赵政杰 on 2021/11/25.
//
#include <stdio.h>
#define MAX 10002

int wine[2][MAX] = {0};

int Money(int n, int l, int money);
int main() {
    int n, L;
    scanf("%d %d", &n, &L);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
        scanf("%d", &wine[i][j]);
        }
    }
    printf("%d", Money(n, L, 0));
    return 0;
}
int Money(int n, int l, int money) {
   int max = 0;
   int max_index = 0;
   for (int i = 0; i < n; i++) {
       if (max < wine[0][i]) {
           max = wine[0][i];
           max_index = i;
       }
   }
   if (l <= 0 || max == 0) {
       return money;
   }
   if (wine[1][max_index] <= l) {
       money += wine[1][max_index] * max;
       l -= wine[1][max_index];
       wine[0][max_index] = 0;
       return Money(n, l, money);
   }
    return money + l * wine[0][max_index];
}
