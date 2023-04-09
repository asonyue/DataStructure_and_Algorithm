//
// Created by Ason Yue on 4/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coefficient;
    int exp;
    struct Node* next;
}*poly=NULL;

void Create() {
    struct Node* t, *last;
    int num;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coefficient and exp\n");

    for(int i=0; i<num; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &t->coefficient, &t->exp);
        t->next = NULL;
        if(poly == NULL) {
            poly = last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
}

void Display(struct Node* p) {
    while(p) {
        printf("%dx%d +", p->coefficient, p->exp);
        p = p->next;
    }
    printf("\n");
}

double Eval(struct Node* p, int x) {
    double val = 0;
    while(p) {
        val += p->coefficient * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main() {
    Create();
    Display(poly);
    printf("%.1lf\n", Eval(poly, 1));
    return 0;
}


