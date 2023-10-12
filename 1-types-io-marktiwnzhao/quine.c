/**
 * File: quine.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.10.16
 */
#include <stdio.h>

    char* s = "#include <stdio.h>%cint main(){%c     char* s = %c%s%c;%c    printf(s,10,10,34,s,34,10,10);%c}";
int main() {
printf(s,10,10,34,s,34,10,10);
}
