//
// Created by Ason Yue on 4/3/23.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*Head=NULL;

void Create(int* arr, int n) {

    struct Node* temp, *prev;

    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = arr[0];
    Head->next = NULL;
    prev = Head;

    for(int i=1; i<n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }
}

void Display(struct Node* p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node* p) {
    int l = 0;
    while(p != NULL) {
        l++;
        p = p->next;
    }
    return l;
}

struct Node* findMiddle() {
    struct Node* p, *q;
    p = q = Head;
    while(q) {
        q = q->next;
        if(q) {
            q = q->next;
        }
        if(q) {
            p =p->next;
        }
    }
    return p;
}

int main() {

    int arr[] = {8, 6, 3, 9, 10, 4, 2, 13};
    Create(arr, 8);
    Display(Head);
    struct Node* result = findMiddle();
    printf("%d ", result->data);
    return 0;
}
