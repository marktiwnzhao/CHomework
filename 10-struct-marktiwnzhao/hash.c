/**
 * File: hash.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.26
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char s[1005];
    struct node *next;
} Node;
Node *list[100000];

int Hash(const char *s) {
    int len = (int)strlen(s);
    int ret = 0;
    for(int i = 0; i < len; i++) ret = (ret + s[i] * (i+1)) % 100000;
    return ret;
}

int main(){
    int m = 0;
    int q = 0;
    scanf("%d %d", &m, &q);
    char str[1005];
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        if (list[Hash(str)] == NULL) {
            list[Hash(str)] = malloc(sizeof(Node));
            strcpy(list[Hash(str)]->s, str);
            list[Hash(str)]->next = NULL;
        } else {
            int save = 1;
            Node *tail = list[Hash(str)];
            while (tail->next != NULL) {
                if (strcmp(tail->s, str) == 0) {
                    save = 0;
                    break;
                }
                tail = tail->next;
            }
            if (strcmp(tail->s, str) == 0) save = 0;
            if (save) {
                tail->next = malloc(sizeof(Node));
                tail->next->next = NULL;
                strcpy(tail->next->s, str);
            } else continue;
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%s", str);
        if (list[Hash(str)] == NULL) {
            printf("No\n");
            continue;
        } else {
            int true = 0;
            Node *j = list[Hash(str)];
            do {
                if (strcmp(j->s, str) == 0) {
                    true = 1;
                    break;
                }
                j = j->next;
            } while (j != NULL);
            if (true) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
