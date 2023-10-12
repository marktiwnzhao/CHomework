#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct file {
    char name[15];
    struct file *sub_1;
    struct file *sub_2;
} File;
File *node[100005];
File *node_cpy[100005];

File *Find(const char *s, int n);
void Query(File *root, int *count);

int main(){
    int n = 0;
    int q = 0;
    scanf("%d %d", &n, &q);

    char str[15];
    for (int i = 0; i < n; i++) {
        node[i] = malloc(sizeof(File));
        node[i]->sub_1 = NULL;
        node[i]->sub_2 = NULL;
        scanf("%s %s", node[i]->name, str);
        if (strcmp(str,"~~~") != 0) {
            for (int j = 0; j <= i - 1; j++) {
                if (strcmp(str, node[j]->name) == 0) {
                    if (node[j]->sub_1 == NULL) {
                        node[j]->sub_1 = node[i];
                    } else {
                        node[j]->sub_2 = node[i];
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        node_cpy[i] = node[i];
    }
    char str_1[15];
    char str_2[15];
    for (int i = 0; i < q; i++) {
        scanf("%s %s", str_1, str_2);
        if (strcmp(str_1, "remove") == 0) {
            strcpy(Find(str_2, n)->name, "\0");
        } else if (strcmp(str_1, "query") == 0) {
            int count = 0;
            Query(Find(str_2, n), &count);
            printf("%d\n", count);
        }
    }
    for (int i = 0; i < n; i++) {
        free(node_cpy[i]);
    }
    return 0;
}

File *Find(const char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(node[i]->name, s) == 0) {
            return node[i];
        }
    }
}


void Query(File *root, int *count) {
    if (root == NULL) {
        return;
    } else if(root->name[0] == '\0') {
        return;
    } else {
        (*count)++;
    }
    Query(root->sub_1, count);
    Query(root->sub_2, count);
}
