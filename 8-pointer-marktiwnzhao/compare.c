#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
    int ans = 1;
    char *str = malloc(5000 * sizeof *str);
    memset(str,0,5000);
    gets(str);
    char *str1 = malloc(5000 * sizeof *str1);
    //while (gets(str1) != NULL) strcat(str,str1);
    //memset(str1,0,5000);
    int len = (int) strlen(str);
    for (int i = 0;i < len;i++)
    {
        if ((*(str + i) >= 0 && *(str + i) <= 31)
            || (*(str + i) >= 34 && *(str + i) <= 41)
            || *(str + i) == 44
            || *(str + i) == 58
            || *(str + i) == 63
            || *(str + i) == 64
            || (*(str + i) >=91 && *(str + i) <= 94)
            || *(str + i) == 96
            || (*(str + i) >= 123 && *(str + i) <= 127))
            ans = 0;
        if (*(str + i) == '-' && *(str + i + 1) != ' ')
            ans = 0;
        if (*(str + i) == '.' && *(str + i + 1) == '.')
            ans = 0;
        if (*(str + i) >= 48 && *(str + i) <= 57)
        {
            int j = i;
            while (*(str + j) >= 48 && *(str + j) <= 57) j++;
            if (*(str + j) != '.' && *(str + j) != ' ' && *(str + j) != ';')
                ans = 0;
        }
    }
    if (ans == 0)
    {
        printf("Compile Error");
        return 0;
    }
    for (int i = 0;i < len;i++)
    {
        if (*(str + i) == ' ')
            continue;
        if (*(str + i) == ';')
        {
            printf("\n");
            continue;
        }
        if (((*(str + i - 1) == ' ' || *(str + i - 1) == ';') && i > 0) || i == 0)
        {
            int j = 0;
            while (*(str + i + j) != ' ' && *(str + i + j) != ';') j++;
            strncpy(str1,str + i,j);
            int len1 = (int) strlen(str1);
            if (*str1 >= 48 && *str1 <= 57)
            {
                int mark = 0;
                for (int k = 0;k < len1;k++)
                    if (*(str1 + k) == '.') mark = 1;
                if (mark == 1) printf("float ");
                else printf("integer ");
            }
            else
            {
                if (strcmp(str1,"const") == 0
                    || strcmp(str1,"int") == 0
                    || strcmp(str1,"float") == 0
                    || strcmp(str1,"double") == 0
                    || strcmp(str1,"long") == 0
                    || strcmp(str1,"static") == 0
                    || strcmp(str1,"void") == 0
                    || strcmp(str1,"char") == 0
                    || strcmp(str1,"extern") == 0
                    || strcmp(str1,"return") == 0
                    || strcmp(str1,"break") == 0
                    || strcmp(str1,"enum") == 0
                    || strcmp(str1,"struct") == 0
                    || strcmp(str1,"typedef") == 0
                    || strcmp(str1,"union") == 0
                    || strcmp(str1,"goto") == 0)
                    printf("reserved ");
                else if (strcmp(str1,"+") == 0
                         || strcmp(str1,"-") == 0
                         || strcmp(str1,"*") == 0
                         || strcmp(str1,"/") == 0
                         || strcmp(str1,"=") == 0
                         || strcmp(str1,"==") == 0
                         || strcmp(str1,"!=") == 0
                         || strcmp(str1,">=") == 0
                         || strcmp(str1,"<=") == 0
                         || strcmp(str1,">") == 0
                         || strcmp(str1,"<") == 0)
                    printf("operator ");
                else printf("variable ");
            }
            memset(str1,0,5000);
        }
    }
    free(str);
    free(str1);
    return 0;
}

