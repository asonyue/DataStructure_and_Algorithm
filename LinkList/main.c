//
// Created by Ason Yue on 3/31/23.
//
#include "linkList.h"

int main() {

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;

    InsertAtTail(&head1, 10);
    InsertAtTail(&head1, 15);
    InsertAtTail(&head1, 17);

    InsertAtTail(&head2, 12);
    InsertAtTail(&head2, 13);
    InsertAtTail(&head2, 20);

    Display(head1);
    printf("\n");

    Display(head2);
    printf("\n");

    mergeTwoSorted(&head1, &head2, &head3);
    Display(head3);

    return 0;
}
