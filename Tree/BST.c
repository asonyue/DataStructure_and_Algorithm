#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lChild;
    int data;
    struct Node* rChild;
}*root=NULL;

void Insert(int key) {
    struct Node*t = root;
    struct Node* r, *p;

    if(root == NULL) {
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->lChild = p->rChild = NULL;
        root = p;
        return;
    }

    while(t != NULL) {
        r=t;
        if(key < t->data) {
            t = t->lChild;
        } else if (key > t->data) {
            t = t->rChild;
        } else {
            return;
        }
    }

    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->lChild = p->rChild = NULL;

    if(key < r->data) {
        r->lChild = p;
    } else {
        r->rChild= p;
    }
}

void Inorder(struct Node* p) {
    if(p) {
        Inorder(p->lChild);
        printf("%d ", p->data);
        Inorder(p->rChild);
    }
}

struct Node* Search(int key) {
    struct Node *t = root;
    while(t != NULL) {
        if(key == t->data) {
            return t;
        } else if(key < t->data) {
            t = t->lChild;
        } else {
            t = t->rChild;
        }
    }
    return NULL;
}

int main() {

    struct Node* temp;

    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);
    printf("\n");

    temp = Search(20);
    if(temp!=NULL) {
        printf("Element %d is found\n", temp->data);
    } else {
        printf("Element is not found\n");
    }

    return 0;
}