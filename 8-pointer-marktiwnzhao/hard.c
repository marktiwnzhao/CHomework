/**
 * File: tokenizer.c
 *
 * Author:
 * ID:
 * Date:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000

int main() {
   char *str = malloc(MAX * sizeof(str));
   gets(str);
   char *str_1 = malloc(MAX * sizeof(str_1));
   while (gets(str_1) != NULL) {
       strcat(str, str_1);
       memset(str_1, 0, sizeof(str_1));
   }
   free(str_1);
   int len = strlen(str);
   for (int i = 0; i < len; i++) {
       if (*(str + i) == ' ') {
           *(str + i) = '\0';
       }
       if (*(str + i) == ';') {
           *(str + i) = '\n';
       }
   }
   char *tmp = malloc(20 * sizeof(tmp));
   char **p = malloc(MAX * sizeof(char *));
   int count = 0;
   for (int i = 0; i < len; i++) {
       if (*(str + i) == '\0' || *(str + i) == '\n') continue;
       int k = 0;
       while (*(str + i) != '\0' && *(str + i) != '\n') {
           *(tmp + (k++)) = *(str + i);
           i++;
       }
       *(tmp + k + 1) = '\0';
        int len_s = strlen(tmp);
        *(p + count) = malloc((len_s) * sizeof(char));
        strcpy (*(p + (count++)), tmp);

        memset(tmp, 0, len_s);
   }
   int true = 1;
   for (int i = 0; i < len; i++) {
       if ((*(str + i) > 0 && *(str + i) <= 41 && *(str + i) != 33 && *(str + i) != 32) ||
            *(str + i) == 44 ||
            *(str + i) == 58 ||
            *(str + i) == 59 ||
            *(str + i) == 63 ||
            *(str + i) == 64 ||
            (*(str + i) > 90 && *(str + i) < 96 && *(str + i) != 95) ||
            *(str + i) > 122 ||
            (*(str + i) == '.' && *(str + i + 1) == '.') ||
            (*(str + i) == '-' && (*(str + i + 1) != '\0' || *(str + i + 1)) != '\n') ) {
           true = 0;
           break;
       }
   }
   for (int i = 0; i < count; i++) {
       int len_t = strlen(*(p + i));
       for (int j = 0; j < len_t; j++) {
           if (*(*(p + i) + j) > 47 && *(*(p + i) + j) < 58 &&
              (*(*(p + i) + j + 1) != '\0' || *(*(p + i) + j + 1) != '.')) {
               true = 0;
               break;
           }
       }
       if (true == 0) {
           break;
       }
   }
   if(true == 0) {
       printf("Compile Error\n");
   }





    free(str);
    free(tmp);
    return 0;
}