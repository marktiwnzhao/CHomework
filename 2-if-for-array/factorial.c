/**
 * File: factorial.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.23
 */
/*#include <stdio.h>
int main(){
       int n = 0;
       scanf("%d", &n);
       long long int s = 1;
       long long int t = 0;
       for (long long int i = 1; 1 <= n; i++) {
           s *= (i % 10007);
           t += s % 10007;
       }
       printf("%lld\n", t % 10007);
       return 0;
}*/
#include <stdio.h>
    int main(){
        int n = 0;
        scanf("%d", &n);
        long long int s = 1;
        long long int t = 0;
        for (long long int i = 1; i <= n; i++) {
            s *= (i % 10007) ;
            t += s % 10007;
        }
        printf("%lld\n", t % 10007);
        return 0;
    }