/**
 * File: statistics.c
 *
 * Author:zhaozhenngjie
 * ID:211250109
 * Date:2021.10.22
 */
#include <stdio.h>
int main(){
  int n = 0;
  scanf("%d", &n);
  char ary[n + 1];
  scanf("%s", ary);
  int a[26][2] = {0};
  int i = 0;
  int j = 0;
  for (i = 0; i < 26; i++) 
  for (j = 0; j < 2; j++){
    a[i][0] = i + 97;
    a[i][1] = 0;
  }
  //count numbers
  int m = 0;
  for (int u = 0; u < n; u++) {
    m = ary[u];
    a[m -97][1]++;
  }
  //get the height
  int height = a[0][1];
  for (int i = 0; i < 26; i++) {
    if (a[i][1] >= height) {
      height = a[i][1];
    }
  }
  //output equals sign line by line
  for (int u = height; u > 0; u--) {
    for (int s = 0;s < 3 * 26; s++) {//get the function by calculating
      if (a[(s + 2) / 3 - 1][1] == u) {
        printf("=");
        a[(s + 2) / 3 - 1][1]--; 
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  for (int s = 0; s < 78; s++) {
    printf("-");
  }
    printf("\n");
  for (i = 0; i < 26; i++) {
    printf(" %c ", a[i][0]);
  }
  return 0;
}