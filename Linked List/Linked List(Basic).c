#include <stdio.h>
#include <stdlib.h>


#define MENU_ITEM_LEN 12


typedef struct ListNode{
    int data;
    struct ListNode *next;
}Node;

Node *head =NULL;


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
    Node *curr = head,*prev;
    int i=1;
    Node *new_node = (Node*) malloc(sizeof(Node*));
    if(new_node == NULL) {
        printf("New node insertion failed. Try again! \n");
    }
    new_node->data= num;
    new_node->next= NULL;

    if (pos == 1) {
        new_node->next=head;
        head = new_node;
        printf(" Node with %d inserted in %d\n",num,pos );
    } else {
        while( (curr != NULL) && (i<pos) ) {
            i++;
            prev=curr;
            curr=curr->next;
        }
        if (i == pos) {
            prev->next = new_node;
            new_node->next=curr;
            printf(" Node with %d inserted in %d\n",num,pos );
        } else {
            printf("Invalid Insertion \n");
        }
    }
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



void node_generate (){

insert_at_position(25, 1);
insert_at_position(12, 1);
insert_at_position(20, 1);
insert_at_position(8, 1);
insert_at_position(29, 1);
insert_at_position(31, 1);
insert_at_position(15, 1);
}

void node_del (){

    printf("************************\n Delete \n************************\n");
    int num=0;
    printf(" Enter the data to be deleted: ");
    scanf("%d",&num);

    Node *curr=head,*prev=NULL;
    if (curr == NULL) {
        printf("Node is empty !\n");
        return;
    }
    if(curr->data == num ) {
        head = curr->next;
        free(curr);
        return;
    }
    prev=head;
    curr=curr->next;
    while(curr != NULL) {
        if(curr->data == num){
            prev->next = curr->next;
            curr->next = NULL;
            printf("Node with value %d deleted! \n",curr->data);
            free(curr);
            return;
        } else {
            prev=curr;
            curr=curr->next;
        }
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

    Node *curr = head, *new_head=NULL, *next_node=NULL;

    while(curr){
        next_node = curr->next;
        curr->next=new_head;
        new_head=curr;
        curr=next_node;
    }
    head=new_head;

    printf("Reversed list \n");
    node_traverse();
    printf("************************\n");
}

void print_reverse(Node* node){
    /* base case */
    if(node == NULL )
        return;
    /* print the list after head node */
    print_reverse(node->next);
    /* Print  everything */
    printf("%d -> ",node->data);
}

/* Function to reverse the linked list */
void node_print_reverse()
{
    // Base case
    if (head == NULL) {
        printf("Empty List \n");
        return;
    }
    // print the list after head node
    print_reverse(head);
    printf("NULL");

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

void merge_sort(Node *headref) {
    Node *curr = headref,*a=NULL,*b=NULL;

    /* Base case -- length 0 or 1 */
    if ((curr == NULL) || (curr->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    front_back_split(curr, &a, &b);

    /* Recursively sort the sublists */
    merge_sort(a);
    merge_sort(b);

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
    merge_sort(head);

    node_traverse();

    printf("************************\n");
}
void node_get_middle(){

    Node *slowptr = head, *fastptr = head;
	int i =0, count=1;
	if (fastptr == NULL) {
        printf("Empty List! \n");
        return ;
	}
	while(fastptr->next != NULL) {
		if(i==0) {
            fastptr=fastptr->next;
            i=1;
		} else if (i==1) {
            slowptr=slowptr->next;
            fastptr=fastptr->next;
            i=0;
            count++;
        }
	}
    printf("Middle of the list is %d at %d \n",slowptr->data,count);

}


void node_remove_duplicate() {
	Node *current = head;
	if (current == NULL)
        return; // do nothing if the list is empty

    // Compare current node with next node
    while(current->next!=NULL) {
        if (current->data == current->next->data)
        {
            struct node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next; // only advance if no deletion
        }
    }
}


void node_seg_even_odd() {

    Node *left_head=NULL,*right_head=NULL,*temp=head,*left_ptr=NULL,*right_ptr=NULL;

    /* 1. increment Left pointer when data is odd,
       2. increment right pointer when data is even
       3. finally join righ head at the end of left pointer.
    */
    if (temp == NULL) {
        printf("Empty List !\n");
        return;
    }

    while(temp) {
        if (temp->data%2) {
            /*odd*/
            if (left_head==NULL) {
                left_head=temp;
                left_ptr=temp;
                temp=temp->next;
                left_ptr->next=NULL;
            } else {
                left_ptr->next=temp;
                left_ptr=left_ptr->next;
                temp=temp->next;
                left_ptr->next=NULL;
            }
        } else {
            if (right_head==NULL) {
                right_head=temp;
                right_ptr=temp;
                temp=temp->next;
                right_ptr->next=NULL;
            } else {
                right_ptr->next=temp;
                right_ptr=right_ptr->next;
                temp=temp->next;
                right_ptr->next=NULL;
            }
        }
    }

    if(left_head == NULL && right_head != NULL) {
        head =right_head;
        return;
    }
    if(left_head != NULL && right_head == NULL) {
        head =left_head;
        return;
    }

    temp=left_head;
    while (temp->next != NULL){
            temp=temp->next;
        }
    temp->next=right_head;

    head = left_head;
}


int main() {

int choice = 1,i;
void (*op_fun[])()={node_generate,
                    node_traverse,
                    node_insert,
                    node_insert_pos,
                    node_del,
                    node_get_len,
                    node_rev,
                    node_print_reverse,
                    node_sort,
                    node_get_middle,
                    node_seg_even_odd,
                    node_remove_duplicate};

while(choice != MENU_ITEM_LEN+1) {
    i=0;
    printf("\n\n Welcome to List program : \n",i++);
    printf("%d. Generate a random list\n",i++);
    printf("%d. Traverse\n",i++);
    printf("%d. Insert at the end\n",i++);
    printf("%d. Insert at a position\n",i++);
    printf("%d. Delete\n",i++);
    printf("%d. Get Length\n",i++);
    printf("%d. Reverse\n",i++);
    printf("%d. Print Reverse\n",i++);
    printf("%d. Sort \n",i++);
    printf("%d. Get Middle \n",i++);
    printf("%d. Segregate Even and Odd \n",i++);
    printf("%d. Remove Duplicates \n",i++);
    printf("%d. End\n\n\n",i++);

    scanf("%d",&choice);

    printf("choice is : %d\n\n",choice);

    if (choice >=1 && choice <=MENU_ITEM_LEN) {
        op_fun[choice-1]();
    }
}
return 0;

}
