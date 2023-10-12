/**
 * File: time.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */
#include <stdio.h>
int main() {
  /**
   * input example: November 17 1968 Sunday 6 6 6
   * output example: Sun Nov 17 06:06:06 1968
   */
   char month[30],weekday[30];
   int day,year,hour,minute,second;
   scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
    printf("%.3s %.3s %02d %02d:%02d:%02d %04d",weekday,month,day,hour,minute,second,year);

  return 0;
}