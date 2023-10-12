/**
 * File: flip.c
 *
 * Author:zhazhengjie
 * ID:211250109
 * Date:2021.10.23
 */
#include <stdio.h>
int main(){
    long int n = 0;
    scanf("%ld", &n);
    int a[n];
    long int i = 0;
    long int j = 0;
    for (i = 0; i < n; i++) {
      a[i] = 0;
    }
    for (i = 0; i < n; i++) {
      for (j = 1; j <= n / (i + 1); j++) {
          if (a[j * (i + 1) - 1] == 1) {
            a[j * (i + 1) - 1] = 0;
          }
          else {
            a[j * (i + 1) - 1] = 1;
          }
        }
      }/*
       for (j = i + 1; j <= n; j += (i + 1)) {
         if (a[j - 1] == 1) {
           a[j - 1] = 0;
         } else {
           a[j - 1] = 1;
            }
        }
    }*/
    for (i = 0; i < n; i++) {
      if (a[i] == 1) {
        printf("%lld ", i + 1);
      }
    }
    return 0;
}