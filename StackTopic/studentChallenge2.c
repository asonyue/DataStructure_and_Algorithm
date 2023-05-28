//
// Created by Ason Yue on 4/9/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
}*top=NULL;

void push(char x) {
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t == NULL) {
        printf("Stack is Full\n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop() {
    struct Node* t;
    char x = -1;
    if(top == NULL) {
        printf("Stack is Empty!\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isOperand(char x) {
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') {
        return 0;
    } else {
        return 1;
    }
}

int outPre(char x) {
    if(x == '+' || x == '-') {
        return 1;
    } else if(x == '*' || x == '/') {
        return 3;
    } else if(x == '^') {
        return 6;
    } else if(x == '(') {
        return 7;
    }
    return 0;
}

int inPre(char x) {
    if(x == '+' || x == '-') {
        return 2;
    } else if(x == '*' || x == '/') {
        return 4;
    } else if(x == '^') {
        return 5;
    } else if(x == '(') {
        return 0;
    }
    return 0;
}

char* inToPost(char* infix) {
    int i = 0, j = 0;
    char* postfix;
    int len = strlen(infix);
    postfix = (char*)malloc((len + 1) * sizeof(char));

    while(infix[i] != '\0') {
        if(isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if(top == NULL || outPre(infix[i]) > inPre(top->data)) {
                push(infix[i++]);
            } else if(outPre(infix[i]) == inPre(top->data)) {
                pop();
                i++;
            } else {
                postfix[j++] = pop();
            }
        }
        }

    while(top != NULL) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char* infix = "((a+b)*c)-d^e^f";

    char* postfix = inToPost(infix);

    printf("%s ", postfix);

    return 0;
}













