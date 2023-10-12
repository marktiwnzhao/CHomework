//
// Created by 赵政杰 on 2021/11/23.
//
#include <stdio.h>
#include <string.h>
#define STACK_SIZE 10005

char contents[STACK_SIZE] = {'\0'};


int top = 0;
void Push(char c) {
    contents[top] = c;
    top++;
}

void Pop(void) {
    if (top == 0) {
        printf("Empty\n");
        return;
    }
    contents[top - 1] = '\0';
    top--;
}

void Top(void) {
    if (top == 0) {
        printf("Empty\n");
        return;
    }
    printf("%c\n", contents[top - 1]);
}

void Print(void) {
    if (top == 0) {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i < top; i++) {
        printf("| %c |\n", contents[top - 1 - i]);
    }
    printf("|===|\n");
}

int main() {
    int n = 0;
    scanf("%d", &n);
    char strs[10005][10] = {' '};
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);
        if (strncmp(strs[i], "push", 4) == 0) {
            scanf(" %c", &strs[i][5]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (strncmp(strs[i], "push", 4) == 0) {
            Push(strs[i][5]);
        }
        if (strncmp(strs[i], "pop", 3) == 0) {
            Pop();
        }
        if (strncmp(strs[i], "top", 3) == 0) {
            Top();
        }
        if (strncmp(strs[i], "print", 3) == 0) {
            Print();
        }
    }
    return 0;
}


