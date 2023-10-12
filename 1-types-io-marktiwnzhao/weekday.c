/**
 * File: weekday.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */
#include <stdio.h>
#include <math.h>
int main() {
    int year,month,day;
    scanf("%d %d %d", &year, &month, &day);
    int Y,m;
    if(month == 1 || month == 2)
    {
        Y = year - 1;m = month + 10;
    }
    else if(month > 2)
    {
        Y = year;m = month - 2;
    }
    int y = Y % 100;
    int c = Y / 100;
    double x = day + floor(2.6 * m - 0.2 ) + y + floor(y / 4.0) + floor(c / 4.0) - 2 * c;
    int w = (int) x % 7;
    while (w < 0)
    {
        w = w + 7;
    }
    printf("%d",w);
    return 0;
}