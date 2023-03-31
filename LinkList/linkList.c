//
// Created by Ason Yue on 3/31/23.
//
#include <stdlib.h>
#include "linkList.h"

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

// Count the numbers of node in the link list
int count(struct Node* p) {
    int l = 0;
    while(p != NULL) {
        l++;
        p = p->next;
    }
    return l;
}

// Sum the value of each node in the link list
int sum(struct Node* p) {
    int s = 0;
    while(p != NULL) {
        s += p->data;
        p = p->next;
    }
    return s;
}

// Find out the maximum value in the link list
int max(struct Node* p) {
    int max = INT32_MIN;
    while(p != NULL) {
        if(p->data > max) {
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

// Improved linear search for given node
struct Node* LSearch(struct Node* p, int key) {
    struct Node *q;
    while(p != NULL) {
        if(key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}