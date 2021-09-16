/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.



Constraints:

    1 <= k <= num.length <= 105
    num consists of only digits.
    num does not have any leading zeros except for the zero itself.

*/

#define MAX_DIGIT 10000

#define STACK_SZ 100000

char * removeKdigits1(char * num, int k)
{
    int n = strlen(num);
    char stack[STACK_SZ];
    int head = -1;  /* pointer to the head of the stack */

    for (int i = 0; i < n; i++) {
        while (head != -1 && k && stack[head] > num[i]) {
            --head;
            --k;
        }
        /* To avoid any trailing zeroes */
        if (head != -1 || num[i] != '0')
            stack[++head] = num[i];
    }

	/* If the digits of a given number are in ascending order */
    while (k-- && head != -1)
        --head;

    /* If stack is empty */
    if (head == -1)
        return "0";

    /* Popping out the remaining digits from the stack */
    while (head != -1)
        num[--n] = stack[head--];

    return num + n;
}

char * removeKdigits(char * num, int k){


    int stack[MAX_DIGIT] = {0};
    int top=-1,removecount=0,digit=0;

    stack[0]=num[0]-'0';
    top=0;

    for( int i=1;i<strlen(num);i++){
        digit=num[i]-'0';

        if( digit > stack[top-1]) {
            // push
            stack[top++]=digit;
            printf("stack insert - %d \n",stack[top]);
        } else {
            //pop
            while( digit < stack[top-1] && top > 0){
                stack[top--]=0;
                removecount++;
                printf("stack removed - %d \n",stack[top]);
            }

            stack[top++]=digit;
        }
        if(removecount == k) {
            break;
        }

    }
    char *return_str = (char*)malloc(sizeof(char)* (top+1));

    for(int i=0;i<top;i++){
        return_str[i]=stack[i]+'0';
    }
    return_str[top]='\0';
    return return_str;

}


int main() {



    char a[]="1432219";
    char b[]="10200";
    char c[]="10";

    //#if 0
    printf(" %s \n",removeKdigits(a,3));
    //printf(" %s \n",removeKdigits(b,1));
    //printf(" %s \n",removeKdigits(c,2));
    //#endif 0

    //printf(" %s \n",removeKdigits1(a,3));
    //printf(" %s \n",removeKdigits1(b,1));
    //printf(" %s \n",removeKdigits1(c,2));


}

