/**
 * File: max.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.11.17
 */
#include <stdio.h>
long long a[3][100005] = {0};
long Max(long l, long r) {
    long max = l;
    for (long i = l + 1; i <= r; i++) {
        if (a[0][i] > a[0][max]) {
            max = i;
        }
    }
    return max;
}

void MaxPrint(long l, long r);

int main() {
    long n = 0;
    scanf("%ld", &n);
    for (long i = 1; i <= n; i++) {
        scanf("%lld", &a[0][i]);
    }
    MaxPrint(1, n);
    for (long i = 1; i <= n; i++) {
        printf("%d %d\n", a[1][i], a[2][i]);
    }
    return 0;
}

void MaxPrint(long l, long r) {
    if (l == r) {
        a[1][l] = l;
        a[2][r] = r;
    } else {
        a[1][Max(l, r)] = l;
        a[2][Max(l, r)] = r;
        if (Max(l, r) > l) {
            MaxPrint(l, Max(l, r) - 1);
        }
        if (Max(l, r) < r) {
            MaxPrint(Max(l, r) + 1, r);
        }
    }
}






















































/**
long long nums[100005] = {0};
long Max(long l, long r) {
    long max = l;
    for (long i = l + 1; i <= r; i++) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }
    return max;
}

void MaxPrint(long j, long l, long r);


int main(){
    long n = 0;
    scanf("%ld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]);
    }

    for (int i = 1; i <= n; i++) {
        MaxPrint(i, 1, n);
        printf("\n");
    }



  return 0;
}

void MaxPrint(long j, long l, long r) {
    if (j == Max(l, r) || l == r) {
        printf("%ld %ld", l, r);
    } else if (j < Max(l, r)) {
        MaxPrint(j, l, Max(l, r) - 1);
    } else {
        MaxPrint(j, Max(l, r) + 1, r);
    }
}*/




