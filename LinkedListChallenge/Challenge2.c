//
// Created by Ason Yue on 4/3/23.
//
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int col;
    int val;
    struct Node* next;
}*p;

void Create(int m, int n, struct Node** A) {

    int nz, c, v;

    for(int i=0; i<m; i++) {
        A[i] = NULL;
        printf("Enter the number of non-zero elements in %d rows", i+1);
        scanf("%d", &nz);

        for(int j=0; j<nz; j++) {
            if(A[i] == NULL) {
                A[i] = (struct Node*)malloc(sizeof(struct Node));
                p = A[i];
                printf("Enter the column and the value: ");
                scanf("%d %d", &c, &v);
                p->col = c;
                p->val = v;
                p->next = NULL;
            } else {
                p->next = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter the column and the value: ");
                scanf("%d %d", &c, &v);
                p = p->next;
                p->col = c;
                p->val = v;
                p->next = NULL;
            }
        }
    }
}

void Display(int m, int n, struct Node** A) {
    for (int i = 0; i < m; i++) {
        p = A[i];
        for (int j = 0; j < n; j++) {
            if (p != NULL && j == p->col) {
                printf("%d", p->val);
                p = p->next;
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}


int main() {

    int m, n;
    printf("Enter the number of rows and column: ");
    scanf("%d %d", &m, &n);
    struct Node** A;
    A = (struct Node**)malloc(m * sizeof(struct Node*));
    Create(m, n, A);
    Display(m, n, A);
    return 0;
}