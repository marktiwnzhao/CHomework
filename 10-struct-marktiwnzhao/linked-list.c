/**
 * File: linked-list.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.25
 */
#include <stdio.h>
int linkedlist[300000];
int len = 0;
int pointer = 0;

void Forward(int m, int *point);
void Backward(int m, int *point);
void Print(int point);
void Remove(int *point, int *l);
void Insert(int *point, int m, int *l);

int main(){
    int T = 0;
    scanf("%d %d", &len, &T);
    for (int i = 0; i < len; i++) {
        linkedlist[i] = i + 1;
    }
    char str[15];
    int m = 0;
    for (int i = 0; i < T; i++) {
        scanf("%s", str);
        if(str[0] == 'F') {
            scanf("%d", &m);
            Forward(m, &pointer);
        }
        if(str[0] == 'B') {
            scanf("%d", &m);
            Backward(m, &pointer);
        }
        if(str[0] == 'P') Print(pointer);
        if(str[0] == 'R') Remove(&pointer, &len);
        if(str[0] == 'I') {
            scanf("%d", &m);
            Insert(&pointer, m, &len);
        }
    }
    return 0;
}

void Forward(int m, int *point) {
    int k = m % len;
    if (*point + k < len) {
        *point = *point + k;
        return;
    } else {
        *point = *point + k - len;
        return;
    }
}

void Backward(int m, int *point) {
    int k = m % len;
    if(*point - k >= 0) {
        *point = *point - k;
        return;
    } else {
        *point = *point - k + len;
        return;
    }
}

void Print(int point) {
    printf("%d\n", linkedlist[point]);
}

void Remove(int *point, int *l) {
    if (*point == *l - 1) {
        *point = 0;
        (*l)--;
        return;
    } else {
        for (int i = *point; i < *l - 1; i++) {
            linkedlist[i] = linkedlist[i + 1];
        }
        (*l)--;
        return;
    }
}

void Insert(int *point, int m, int *l) {
    if (*point == *l - 1) {
        linkedlist[*point + 1] = m;
        (*l)++;
        return;
    } else {
        for (int i = *l; i > *point + 1; i--) {
            linkedlist[i] = linkedlist[i - 1];
        }
        linkedlist[*point + 1] = m;
        (*l)++;
        return;
    }
}