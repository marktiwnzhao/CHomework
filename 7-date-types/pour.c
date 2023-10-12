//
// Created by 赵政杰 on 2021/11/25.
//
#include <stdio.h>
int main() {
    int k, a, b, c, a_0, b_0, c_0;
    long long v_a, v_b, v_c;
    scanf("%d %lld %lld %d %d %d %d %d %d"
          ,&k, &v_a, &v_b, &v_c,
          &a, &b, &c, &a_0, &b_0, &c_0);
    if (a_0 == 0 && b_0 == 0 && c_0 == 0) {
        printf("No\n");
    } else if (a_0 > 0 && b_0 > 0 && c_0 > 0) {
        if (a == a_0 && b == b_0 && c == c_0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (a_0 > 0 && b_0 == 0 && c_0 == 0) {
        if ((a + b + c == a_0 || (a_0 == v_a && a + b + c >= a_0)) && k >= 2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (a_0 == 0 && b_0 > 0 && c_0 == 0) {
        if ((a + b + c == b_0 || (a_0 == v_a && a + b + c >= b_0)) && k >= 2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (a_0 == 0 && b_0 == 0 && c_0 > 0) {
        if ((a + b + c == c_0 || (a_0 == v_a && a + b + c >= c_0)) && k >= 2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (a_0 > 0 && b_0 > 0 && c_0 == 0) {
        if (a == a_0) {

        }
    }




    return 0;
}
