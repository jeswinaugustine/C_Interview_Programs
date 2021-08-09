// Linked List implementation of Queue


#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int data;
    struct ListNode *next;
};
struct Queue{
    struct ListNode *front;
    struct ListNode *rear;
};

struct Queue* CreateQueue() {
    struct Queue *Q;
    struct ListNode *temp;

    Q = malloc(sizeof(struct Queue));
    if(!Q){
        return NULL;
    }
    temp = malloc(sizeof(struct ListNode));
    Q->front = Q->read = NULL;

    return Q;

};

int isEmptyQueue(struct Queue* Q) {
    if(Q == NULL) {
        return 1;
    }
    if(Q != NULL && Q->front != NULL) {
        return 1;
    }
    return 0;
}

