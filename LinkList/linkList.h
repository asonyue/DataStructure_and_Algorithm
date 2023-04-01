//
// Created by Ason Yue on 3/31/23.
//
#include <stdio.h>
#ifndef DATASTRUCTURE_AND_ALGORITHM_LINKLIST_H
#define DATASTRUCTURE_AND_ALGORITHM_LINKLIST_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNewNode(int value);
void InsertAtTail(struct Node** head, int value);
void Display(struct Node* p);
int count(struct Node* p);
int sum(struct Node* p);
int max(struct Node* p);
struct Node* LSearch(struct Node** p, int key);
void Insert(struct Node** head_ref, int index, int value);
int Delete(struct Node** head_ref, int index);
void Reverse(struct Node** head_ref);
void mergeTwoSorted(struct Node** head1, struct Node** head2, struct Node** head3);
#endif //DATASTRUCTURE_AND_ALGORITHM_LINKLIST_H
