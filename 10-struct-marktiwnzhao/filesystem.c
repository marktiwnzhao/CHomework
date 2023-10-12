/**
 * File: filesystem.c
 *
 * Author:zhaozhengjie
 * ID:211250109
 * Date:2021.12.25
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct file {
    char name[15];
    struct file *sub_1;
    struct file *sub_2;
} File;
File *node[10000];

File *Find(const char *s, int n);
void Remove(File **root);
void Query(File *root, int *count);

int main(){
    int n = 0;
    int q = 0;
    scanf("%d %d", &n, &q);

    node[0] = malloc(sizeof(File));

    scanf("%s ~~~", node[0]->name);
    node[0]->sub_1 = NULL;
    node[0]->sub_2 = NULL;

    char str[15];
    for (int i = 1; i < n; i++) {
        node[i] = malloc(sizeof(File));
        node[i]->sub_1 = NULL;
        node[i]->sub_2 = NULL;
        scanf("%s %s", node[i]->name, str);
        for (int j = 0; j <= i - 1; j++) {
            if (strcmp(str, node[j]->name) == 0) {
                if (node[j]->sub_1 == NULL) {
                    node[j]->sub_1 = node[i];
                } else {
                    node[j]->sub_2 = node[i];
                }
            }
        }
    }

    char str_1[15];
    char str_2[15];
    for (int i = 0; i < q; i++) {
        scanf("%s %s", str_1, str_2);
        if (strcmp(str_1, "remove") == 0) {
            File *tmp = Find(str_2, n);
            Remove(&tmp);
        } else if (strcmp(str_1, "query") == 0) {
            int count = 0;
            Query(Find(str_2, n), &count);
            printf("%d\n",count);
        }
    }
    return 0;
}

File *Find(const char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(node[i]->name, s) == 0) {
            return node[i];
        }
    }
    return NULL;
}

void Remove(File **root) {
    if (*root != NULL) {
        Remove(&((*root)->sub_1));
        Remove(&((*root)->sub_2));
        free(*root);
        *root = NULL;
    }
}

void Query(File *root, int *count) {
    if (root != NULL) {
        (*count)++;
    } else {
        return;
    }
    Query(root->sub_1, count);
    Query(root->sub_2, count);
}