#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

#define MAX 100000

int stack[MAX]={0};
int top=-1;


void push(int num) {
    if (top<MAX) {
        top++;
        stack[top] = num;
        printf("\n Inserted %d at %d \n",num,top);
    }
}

void pop() {
    if (top >= 0){
        printf("\n Deleted %d at %d \n",stack[top],top);
        stack[top] = 0;
        top--;
    }
}

void create_stack() {
    top=-1;
    memset(stack,0x00,MAX);
}

void print(){
    for(int i=0;i<top;i++){
        printf("%d",stack[i]);
    }
    printf("\n");
}
char * removeKdigits(char *num, int k){

    char *ret_str = malloc(50);

    if(strlen(num) <= k) {
        ret_str[0]='0';
        ret_str[1]='\0';
        return ret_str;
    }

    create_stack();
    push(num[0]-'0');
    int remove_count=0;
    int i,j;


    for(i=1;i<strlen(num);i++) {
        int current_number = num[i]-'0';
        if(current_number < stack[top]) {
            while( current_number < stack[top] && remove_count < k) {
                pop();
                remove_count++;
                if(remove_count==k) {
                    break;
                }
            }
            push(current_number);
        } else {
            push(current_number);
        }
        if(remove_count==k) {
            break;
        }
    }
    for (j=i+1;j<strlen(num);j++){
        push(num[j]-'0');
    }

    /* convert the stack to string */
    for (j=0;j<=top;j++) {
        ret_str[j]='0'+stack[j];
    }
    ret_str[j]='\0';

    //printf(" \n return string = %s \n",ret_str);
    return ret_str;
}



int main( ) {

    char* str[3]={"1432219","10200","10"} ;
    char* str1 ="10200";
    int num_to_remove[3] = {3,1,2};

    for(int i=0;i<3;i++) {
        printf("\n Remove %d from %s -> %s \n", num_to_remove[i],str[i],
               removeKdigits(str[i],num_to_remove[i]));
    }

    return 0;
}
