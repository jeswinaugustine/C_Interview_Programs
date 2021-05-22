#include <stdio.h>
#include <stdlib.h>


#define MENU_ITEM_LEN 7


typedef struct ListNode{
    int data;
    struct ListNode *next;
}Node;

Node *head =NULL;

void node_generate (){


}
void node_traverse(){
    printf("************************\n Traverse \n************************\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printf("************************\n");
}

void node_insert() {

    printf("************************\n Insert at the end \n************************\n");
    int num=0;
    printf("Enter the number: \n");
    scanf("%d",&num);

    Node *temp = head;
    Node *new_node = (Node*) malloc(sizeof(Node*));
    if(new_node == NULL) {
        printf("New node insertion failed. Try again! \n");
    }
    new_node->data= num;
    new_node->next= NULL;

    if (head == NULL) {
        head=new_node;
        new_node->next=NULL;
        return;
    }
    while (temp->next != NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    node_traverse();
    printf("************************\n");
}

void insert_at_position(int num,int pos) {
    Node *temp = head;
    int i=0;
    Node *new_node = (Node*) malloc(sizeof(Node*));
    if(new_node == NULL) {
        printf("New node insertion failed. Try again! \n");
    }
    new_node->data= num;
    new_node->next= NULL;

    if (pos == 0) {
        head = new_node;
    } else {
        while (i<pos) {
            if(temp !=NULL) {
                temp=temp->next;
                i++;
            } else {
                printf("Invalid Insert Entry!\n");
                return;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf(" Node with %d inserted in %d\n",num,pos);
}
void node_insert_pos() {

    printf("************************\n Insert at a position \n************************\n");
    int num=0,pos=0;
    printf("Enter the number: \n");
    scanf("%d",&num);

    printf("Enter the position: \n");
    scanf("%d",&pos);

    insert_at_position(num, pos);

    return;
}

void node_del (){

    printf("************************\n Delete \n************************\n");
    int num=0;
    printf(" Enter the data to be deleted: ");
    scanf("%d",&num);

    Node *temp=head;
    if (temp == NULL) {
        printf("Node is empty !\n");
        return;
    }
    if(temp->data == num ) {
        head = temp->next;
        free(temp);
        return;
    }
    Node *prev=temp;
    while(temp->next != NULL) {
        temp=temp->next;
        if(temp->data == num){
            prev->next = temp->next;
            temp->next = NULL;
            printf("Node with value %d deleted! \n",temp->data);
            free(temp);
            return;
        }
        prev=prev->next;
    }
    printf("Requested value %d not found ! \n",num);

    printf("************************\n");
}
void node_get_len() {
    printf("************************\n Get Length \n************************\n");
    int len=0;

    if (head == NULL) {
        printf(" Length is : %d\n\n",len);
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        len++;
        temp=temp->next;
    }
    printf(" Length is : %d \n\n",len);

    printf("************************\n");
}

void node_rev () {
    printf("************************\n Reverse \n************************\n");

    Node *curr = head, *temp=NULL, *next_node=NULL;

    while(curr){
        next_node = curr->next;
        curr->next=temp;
        temp=curr;
        curr=next_node;
    }
    head=temp;

    printf("Reversed list \n");
    node_traverse();
    printf("************************\n");
}


/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void front_back_split(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node* sorted_merge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = sorted_merge(a->next, b);
    }
    else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return (result);
}

void merge_sort() {
    Node *curr = head,*a=NULL,*b=NULL;

    /* Base case -- length 0 or 1 */
    if ((curr == NULL) || (curr->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    front_back_split(curr, &a, &b);

    /* Recursively sort the sublists */
    merge_sort(&a);
    merge_sort(&b);

    /* answer = merge the two sorted lists together */
    curr = sorted_merge(a, b);

    head = curr;
}

void node_sort(){
    printf("************************\n Sort \n************************\n");

    /* Merge sort is often preferred for sorting a linked list.
       The slow random-access performance of a linked list makes some other
       algorithms (such as quicksort) perform poorly, and others (such as
       heapsort) completely impossible.
    */

    /* Algorithm
     *
    MergeSort(headRef)
    1) If the head is NULL or there is only one element in the Linked List
       then return.
    2) Else divide the linked list into two halves.
       FrontBackSplit(head, &a, &b); ( a and b are two halves )
    3) Sort the two halves a and b.
       MergeSort(a);
       MergeSort(b);
    4) Merge the sorted a and b (using SortedMerge() discussed here)
       and update the head pointer using headRef.
       *headRef = SortedMerge(a, b);
   */
    merge_sort();

    node_traverse();

    printf("************************\n");
}


int main() {

int choice = 1;
void (*op_fun[])()={node_generate,node_traverse, node_insert,node_insert_pos, node_del, node_get_len, node_rev,node_sort};

while(choice !=7 ) {
    printf("\n\n Welcome to List program : \n");
    printf("0. Generate a random list\n");
    printf("1. Traverse\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at a position\n");
    printf("4. Delete\n");
    printf("5. Get Length\n");
    printf("6. Reverse\n");
    printf("7. Sort \n");
    printf("8. End\n\n\n");

    scanf("%d",&choice);

    printf("choice is : %d\n\n",choice);

    if (choice >=0 && choice <=MENU_ITEM_LEN) {
        op_fun[choice]();
    }
}
return 0;

}
