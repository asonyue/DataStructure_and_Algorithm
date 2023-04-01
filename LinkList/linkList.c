//
// Created by Ason Yue on 3/31/23.
//
#include <stdlib.h>
#include "linkList.h"

// Create single node
struct Node* createNewNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at tail function
void InsertAtTail(struct Node** head, int value) {
    struct Node* newNode = createNewNode(value);
    if(*head==NULL) {
        *head = newNode;
        return;
    }
    struct Node* tempNode = *head;
    while(tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
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
struct Node* LSearch(struct Node** head_ref, int key) {
    struct Node *current= *head_ref;
    struct Node *q = NULL;
    while(current != NULL) {
        if(key == current->data) {
            q->next = current->next;
            current->next = *head_ref;
            *head_ref = current;
            return current;
        }
        q = current;
        current = current->next;
    }
    return NULL;
}

// Insert node into the link list
void Insert(struct Node** head_ref, int index, int value) {
    struct Node *current = *head_ref;
    struct Node *t = NULL;

    if(index < 0 || index > count(*head_ref)) {
        return;
    }
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;

    if(index == 0) {
        t->next = *head_ref;
        *head_ref = t;
    } else {
        for(int i=0; i<index-1; i++) {
            current = current->next;
        }
        t->next = current->next;
        current->next = t;
    }
}

// Delete node from the link list
int Delete(struct Node** head_ref, int index) {
    struct Node* q = NULL;
    struct Node* current = *head_ref;
    int x = -1;

    if(index < 1 || index > (count(*head_ref))) {
        return -1;
    }
    if(index == 1) {
        q = *head_ref;
        x = (*head_ref)->data;
        *head_ref = (*head_ref)->next;
        free(q);
        return x;
    } else {
        for(int i=0; i<index-1; i++) {
            q=current;
            current = current->next;
        }
        q->next = current->next;
        x = current->data;
        free(current);
        return x;
    }
}

// Reverse a link list
void Reverse(struct Node** head_ref) {
    struct Node* q = NULL, *r = NULL;
    struct Node* current = *head_ref;

    while(current != NULL) {
        r = q;
        q = current;
        current = current->next;
        q->next = r;
    }
    *head_ref = q;
}

// Merge two sorted list
void mergeTwoSorted(struct Node** head1, struct Node** head2, struct Node** head3) {
    struct Node* temp1 = *head1;
    struct Node* temp2 = *head2;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> data <= temp2 ->data) {
            InsertAtTail(head3, temp1->data);
            temp1 = temp1->next;
        } else {
            InsertAtTail(head3, temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL) {
        InsertAtTail(head3, temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        InsertAtTail(head3, temp2->data);
        temp2 = temp2->next;
    }
}
