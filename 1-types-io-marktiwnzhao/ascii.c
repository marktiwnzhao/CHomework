/**
 * File: ascii.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.15
 */
#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    if(65 <= x && x <= 90) {
        printf("%d\n%c\n%c\n", x,x + 32,x);
    }
    else if(97 <= x && x<= 122){
        printf("%d\n%c\n%c\n",x,x,x - 32);
    }
    return 0;
}