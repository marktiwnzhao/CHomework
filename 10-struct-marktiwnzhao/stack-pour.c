/**
 * File: stack-pour.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.25
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *pre;
    int val;
    struct node *next;
} Node;
Node *stack[1000000];
int ep[1000000];

void Pour(int x, int y);
int main() {
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        stack[i] = malloc(sizeof (Node));
    }
    for (int i = 0; i < n; i++) {
        stack[i]->pre = NULL;
        stack[i]->val = i + 1;
        stack[i]->next = NULL;
        ep[i] = i;
    }

    int x = 0;
    int y = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        if (x > 0 && y > 0) {
            Pour(x, y);
        }
    }

    for (int i = 0; i < n; i++) {
        if (ep[i] < 0) {
            printf("0\n");
        } else {
            Node *j = stack[ep[i]];
            do {
                printf("%d ", j->val);
                j = j->next;
            } while (j != NULL);
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        free(stack[i]);
    }
    return 0;
}
void Pour(int x, int y) {
    if (ep[x - 1] < 0) {
        return;
    }
    Node *k = stack[ep[x - 1]];
    do {
        Node *tmp = k->pre;
        k->pre = k->next;
        k->next = tmp;
        if (k->pre != NULL) {
            k = k->pre;
        }
    } while (k->pre != NULL);
    if (ep[y - 1] >= 0) {
        Node *tail_y = stack[ep[y - 1]];
        while (tail_y->next != NULL) {
            tail_y = tail_y->next;
        }
        tail_y->next = k;
        k->pre = tail_y;
    } else {
        ep[y - 1] = k->val - 1;
    }
    ep[x - 1] = -1;
}