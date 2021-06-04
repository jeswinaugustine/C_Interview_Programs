#include <stdio.h>

typedef struct CLLNODE {
    int data;
    struct CLLNODE *next;
} CLLNode;

CLLNode *head;


void CLLInsert(int data,int pos) {

    CLLNode *current = head, *new_node;
    int i=1;

    new_node = (CLLNode*) malloc(sizeof(CLLNode));
    if(!new_node) {
        printf("Allocation Error !");
        return;
    }

    new_node->data = data;

    if (pos == 1) {
        new_node->next = current;
        if(current != NULL) {
            while(current->next != head) {
                current=current->next;
            }
            current->next=new_node;
        } else {
            new_node->next=new_node;
        }
        head = new_node;
        printf("%d inserted in %d!\n",data,pos);
        return;
    }

    while ( (i<pos-1) && (current->next != head)) {
        current = current->next;
        i++;
    }

    if(i != pos-1){
        printf("Invalid pos ! \n");
        free(new_node);
        return;
    }

    new_node->next=current->next;
    current->next = new_node;
    printf("%d inserted in %d!\n",data,pos);

    return;

}

void CLLDelete(int pos) {
    CLLNode *prev, *del_node=head;
    int i=1;
    if(head==NULL) {
        printf("List is empty \n");
        return;
    }

    if (pos == 1) {
        del_node = head;
        prev=head;
        while(prev->next != del_node) {
            prev=prev->next;
        }
        head = del_node->next;
        prev->next=head;
        free(del_node);
        del_node=NULL;
        return;
    }

    while( (i<pos-1) && (del_node->next != head)) {
        i++;
        prev=del_node;
        del_node=del_node->next;
    }

    if(i!=pos-1){
        printf("invalid pos !\n");
        return;
    }
    prev->next = del_node->next;

    printf("%d from %d position \n",del_node->data,pos);
    free(del_node);

    return;
}

void CLLDisplay(){
    CLLNode *current= head;

    if (current==NULL) {
        printf("CLL list is empty\n\n");
        return;
    }
    do {
        printf("%d -> ",current->data);
        current=current->next;
    }
    while(current != head);
    printf(" | \n");
    return;
}


int main() {

    int choice,data,pos;

    CLLInsert(20,1);
    CLLInsert(21,1);
    CLLInsert(22,1);
    CLLInsert(23,1);

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
                CLLInsert(data,pos);
                break;
            case 2:
                printf("Enter the position: \n");
                scanf("%d",&pos);
                CLLDelete(pos);
                break;
            case 3:
                CLLDisplay();
                break;
        }
    }while(choice != 4);

    return 0;
}



