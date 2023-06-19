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

struct Node *RInsert(struct Node *p, int key) {

    struct Node *t = NULL;
    if(p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if(key < p->data) {
        p->lChild = RInsert(p->lChild, key);
    } else if(key > p->data) {
        p->rChild = RInsert(p->rChild, key);
    }
    return p;
}


int main() {

    struct Node* temp;

    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

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