//
// Created by Ason Yue on 3/31/23.
//
#include <stdlib.h>
#include "linkList.h"

struct Node *first = NULL;

// Creation of a single link list
void create(int A[], int n) {
    int i;
    struct Node* t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Display the linked list
void Display(struct Node* p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}