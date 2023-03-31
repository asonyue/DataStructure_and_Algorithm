//
// Created by Ason Yue on 3/31/23.
//
#include "linkList.h"

struct Node *first = NULL;

int main() {

    struct Node *temp;

    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);

    Display(first);

    return 0;
}
