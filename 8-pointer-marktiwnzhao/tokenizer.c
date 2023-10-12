/*
 * 函数: split()
 * 功能: 指定分隔符分割字符串
 * 返回值: 一个指向包含char*指针的数组的指针，即char **pt
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split(const char *str, char flag);

int main() {
    char *str = malloc(20000 * sizeof(str));
    scanf("%s ", str);
    char del;
    scanf("%c", &del);
    char **res;
    res = split(str, del);
    for (int i = 0; *(res + i) != NULL; i++) {
        printf("%s\n", *(res + i));
    }
    free(str);
    free(res);
    return 0;
}


char **split(const char *str, char flag) {
    char **p;
    int len = strlen(str);

    int count = 1;
    // 动态分配一个 *tmp
    char *tmp = (char *)malloc((len + 1) * sizeof(char));
    *tmp = '\0';

    for (int i = 0; i < len; ++i) {
        if (*(str + i) == flag && *(str + i + 1) == '\0') {
            continue;
        }
        else if (*(str + i) == flag && *(str + i + 1) != flag) {
            count++;
        }
    }
    // 多分配一个char*，是为了设置结束标志
    p = (char **)malloc((count + 1) * sizeof(char *));
    count = 0;
    int j = 0;
    int n = 0;
    for (int i = 0; i < len; ++i) {
        if (i == len - 1 && *(str + i) != flag) {
            *(tmp + (n++)) = *(str + i);
            *(tmp + n) = '\0';  // 字符串末尾添加空字符
            j = strlen(tmp) + 1;
            *(p + count) = malloc(j * sizeof(char));
            strcpy(*(p + (count++)), tmp);
        }
        else if (*(str + i) == flag) {
            j = strlen(tmp);
            if (j != 0) {
                *(tmp + n) = '\0';  // 字符串末尾添加空字符
                *(p + count) = malloc((j + 1) * sizeof(char));
                strcpy(*(p + (count++)), tmp);
                // 重置tmp
                n = 0;
                *(tmp + 0) = '\0';
            }
        }
        else {
            *(tmp + (n++)) = *(str + i);
        }
    }
    // 设置结束标志
    *(p + count) = NULL;
    char *tmep = NULL;
    for (int i = 0; i < count - 1; i++) {
        for (int k = i + 1; k < count; k++) {
            if (strcmp(*(p + i), *(p + k)) > 0) {
                tmep = *(p + i);
                *(p + i) = *(p + k);
                *(p + k) = tmep;
            }
        }

    }
    // 释放tmp
    free(tmp);
    return p;
}
