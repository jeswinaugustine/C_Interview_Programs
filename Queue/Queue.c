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
    //temp = malloc(sizeof(struct ListNode));
    Q->front = Q->rear = NULL;

    return Q;

};

int isEmptyQueue(struct Queue* Q) {

    return (Q->front==NULL);

}

void EnQueue (struct Queue *Q,int data){

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    if(!new_node){
        printf("Enqueue failed\n");
        return;
    }

    new_node->data=data;
    new_node->next=NULL;

    if (isEmptyQueue(Q)) {
        Q->front=new_node;
        Q->rear=new_node;
    } else {
        Q->rear->next=new_node;
        Q->rear=new_node;
    }
    printf("%d inserted at rear!\n",data);
}

void DeQueue (struct Queue *Q){

    if (isEmptyQueue(Q)) {
        printf("Queue is empty\n;");
        return;
    }
    struct ListNode *temp = Q->front;

    Q->front = temp->next;
    free(temp);

    return;

}

void printQueue(struct Queue*Q){
    if(isEmptyQueue(Q)){
        printf("Queue is empty ! \n");
        return;
    }
    struct ListNode* list_node = Q->front;
    printf("F->");
    while(list_node!=Q->rear){
        printf(" %d ",list_node->data);
        list_node=list_node->next;
    }
    printf("->R\n");
}

int main(){
    struct Queue *Q= CreateQueue();

    for(int i=0;i<10;i++){
        EnQueue(Q,i+10);
    }
    printQueue(Q);
    DeQueue(Q);
    printQueue(Q);

}



