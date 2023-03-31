//
// Created by Ason Yue on 3/31/23.
//
#include <stdio.h>
#ifndef DATASTRUCTURE_AND_ALGORITHM_LINKLIST_H
#define DATASTRUCTURE_AND_ALGORITHM_LINKLIST_H

struct Node {
    int data;
    struct Node* next;
}extern *first;

void create(int A[], int n);
void Display(struct Node* p);

#endif //DATASTRUCTURE_AND_ALGORITHM_LINKLIST_H
