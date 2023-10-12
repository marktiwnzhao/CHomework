//
// Created by 赵政杰 on 2021/11/25.
//
#include <stdio.h>
#define MAX 100005

char stack[MAX] = {' '};

char s[32][100005] = {' '};
int IsLegal(char m[]);
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < T; i++) {
        if (IsLegal(s[i])) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return 0;
}

int IsLegal(char m[]) {
    int top = 0;
    int len = 0;
    while(m[len] != '\0') {
        len++;
    }
    if (len & 1) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (m[i] == '[') {
            stack[top] = '[';
            top++;
        }
        if (m[i] == '{') {
            stack[top] = '{';
            top++;
        }
        if (m[i] == '(') {
            stack[top] = '(';
            top++;
        }
        if (m[i] == ']') {
            if (top == 0 || stack[top - 1] != '[') {
                return 0;
            } else {
                stack[top - 1] = '\0';
                top--;
            }
        }
        if (m[i] == '}') {
            if (top == 0 || stack[top - 1] != '{') {
                return 0;
            } else {
                stack[top - 1] = '\0';
                top--;
            }
        }
        if (m[i] == ')') {
            if (top == 0 || stack[top - 1] != '(') {
                return 0;
            } else {
                stack[top - 1] = '\0';
                top--;
            }
        }

    }
    return top == 0;

}