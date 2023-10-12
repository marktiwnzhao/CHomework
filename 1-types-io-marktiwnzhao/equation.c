/**
 * File: equation.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.15
 */

#include <stdio.h>
#include <math.h>

int main() {
  // Well, `a`, `b`, `c` are actually meaningful identifiers here.
  double a,b,c,discriminant;
  scanf("%lf%lf%lf", &a, &b, &c);
  discriminant = b * b - 4 * a * c;
    printf("%.3lf %.3lf\n",(-b - sqrt(discriminant)) / (2 * a),(-b + sqrt(discriminant)) / (2 * a));

  return 0;
}