//
// Created by 赵政杰 on 2021/11/25.
//
#include <stdio.h>
long long v_a, v_b, v_c;
int a_0, b_0, c_0;
int CanFind(int k, int a, int b, int c);
int Max(int a, int b, int c) {
    if (a + b <= c) {
        return a + b;
    } else {
        return c;
    }
}
int main() {
    int k, a, b, c;
    scanf("%d %lld %lld %lld %d %d %d %d %d %d",
          &k, &v_a, &v_b, &v_c, &a, &b, &c, &a_0, &b_0, &c_0);
    if (CanFind(k, a, b, c)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    //printf("%d ", CanFind(k, a, b, c));
    return 0;
}

int CanFind(int k, int a, int b, int c) {
    if (a == a_0 && b == b_0 && c == c_0) {
        return k >= 0;
    } else if (k < 0){
        return 0;
    }
    return CanFind(k - 1, Max(a , b, v_a),0, c) |
           CanFind(k - 1, Max(a, c, v_a), b, 0) |
           CanFind(k - 1, 0, Max(a, b, v_b), c) |
           CanFind(k - 1, a, Max(b, c, v_b), 0) |
           CanFind(k - 1, 0, b, Max(a, c, v_c)) |
           CanFind(k - 1, a, 0, Max(b, c, v_c));
}

