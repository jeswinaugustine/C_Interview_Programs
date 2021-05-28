#include <stdio.h>

#define MAX_CAPACITY 1000

typedef struct stack_t {
    int data;
    struct stack_t *next;
} Stack;

Stack *top;
int capacity = MAX_CAPACITY;
int current_capacity = 0;

void display() {

    Stack *temp=top;
    if (temp == NULL) {
        printf("Stack isnt initialized !\n");
        return;
    }
    printf(" Current Capacity is %d \n",current_capacity);

    while (temp!=NULL){
        if(temp == top ) {
            printf("%d <- TOP \n",temp->data);
        } else {
            printf("%d\n",temp->data);
        }
        temp=temp->next;
    }
}

void push(int num) {

    Stack *new_elem = (Stack*) malloc(sizeof(Stack));
    if(new_elem != NULL) {
        new_elem->data=num;
        new_elem->next=NULL;
    }
    if (current_capacity < MAX_CAPACITY) {
        if(top == NULL) {
            top = new_elem;
        } else {
            new_elem->next = top;
            top = new_elem;
        }
        current_capacity++;
    }
}

void pop() {

    Stack *temp=top;
    if(temp == NULL) {
        printf("Stack is Empty !\n");
        return;
    }
    top=temp->next;
    current_capacity--;
    printf("%d is removed from stack !\n",temp->data);
    free(temp);
}


void peek() {

    if(top == NULL) {
        printf("Stack is Empty !\n");
        return;
    }
    printf(" Top element is %d \n",top->data);
    printf(" Current Capacity is %d \n",current_capacity);
}

int main() {
    int choice=0,num=0;

    while (choice != 5) {
        printf("1. Display\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. End\n\n\n");

        scanf("%d",&choice);

        switch(choice){
            case 1:
                display();
                break;
            case 2:

                printf("Enter the number: \n");
                scanf("%d",&num);
                push(num);
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("End Program ! \n");
                break;
            default:
                printf("Invalid Choice !\n");
        }
    }
}
