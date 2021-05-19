#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

struct ListNode *head;

int main() {

int choice;
printf("Welcome to List program : \n");
printf("1. Print\n");
printf("2. Insert\n");
printf("3. Delete\n");
printf("4. Get Length\n");
printf("5. Reverse\n");
printf("6. Sort \n");
printf("7. End\n\n\n");


scanf("%d",&choice);

printf("choice is : %d",choice);

return 0;

}
