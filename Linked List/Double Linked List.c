#include <stdio.h>

typedef struct DLLNODE {
    int data;
    struct DLLNODE *next;
    struct DLLNODE *prev;
} DLLNode;

DLLNode *head;


void DLLInsert(int data,int pos) {

    DLLNode *current = head, *new_node;
    int i=1;

    new_node = (DLLNode*) malloc(sizeof(DLLNode));
    if(!new_node) {
        printf("Allocation Error !");
        return;
    }
    new_node->data = data;

    if (pos == 1) {
        new_node->next = head;
        new_node->prev = NULL;
        if(head) {
            head->prev = new_node;
        }
        head = new_node;
        printf("%d inserted in %d!\n",data,pos);
        return;
    }

    while ( (i<pos-1) && (current->next != NULL)) {
        current = current->next;
        i++;
    }

    if(i != pos-1){
        printf("Invalid pos ! \n");
        free(new_node);
        return;
    }

    new_node->next=current->next;
    new_node->prev=current;
    if(current->next)
        current->next->prev = new_node;
    current->next = new_node;
    printf("%d inserted in %d!\n",data,pos);
    return;

}

void DLLDelete(int pos) {
    DLLNode *current=head, *new_node;
    int i=1;
    if(head==NULL) {
        printf("List is empty \n");
        return;
    }
    if(pos == 1) {
        head=head->next;
        if(head!=NULL){
            head->prev == NULL;
        }
        free(current);
        return;
    }
    while(i<pos && (current!=NULL)) {
        i++;
        current=current->next;
    }
    if(i!=pos){
        printf("invalid pos !\n");
        return;
    }
    current->prev->next = current->next;
    if(current->next)
        current->next->prev= current->prev;
    printf("%d from %d position \n",current->data,pos);
    free(current);
    return;
}

void DLLDisplay(){
    DLLNode *current= head;

    if (current==NULL) {
        printf("DLL list is empty\n\n");
        return;
    }
    while(current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL\n\n");

}


int main() {

    int choice,data,pos;

    DLLInsert(20,1);
    DLLInsert(21,1);
    DLLInsert(22,1);
    DLLInsert(23,1);

    do{
        printf("----  Main Menu ----\n");
        printf("\n1. Add an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Display the list");
        printf("\n4. Exit the list");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: \n");
                scanf("%d",&data);
                printf("Enter the position: \n");
                scanf("%d",&pos);
                DLLInsert(data,pos);
                break;
            case 2:
                printf("Enter the position: \n");
                scanf("%d",&pos);
                DLLDelete(pos);
                break;
            case 3:
                DLLDisplay();
                break;
        }
    }while(choice != 4);

    return 0;
}



