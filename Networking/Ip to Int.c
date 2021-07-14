/* C Program to convert Binary IP address to 32-bit long int  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

union iptolint
{
    char ip[16];
    long  n;
};

long  conv(char []);

int main()
{
    union iptolint ipl;
    printf("Enter any IP Address to be converted :: ");
    scanf("%s",ipl.ip);

    ipl.n=conv(ipl.ip);

    printf("\nEquivalent 32-bit long int is :: %lu \n",ipl.n);
}

long conv(char ipadr[])
{
    long num=0,val;
    int p=24;
    char *tok,*ptr;
    tok=strtok(ipadr,".");
    while( tok != NULL)
    {
        val=strtol(tok,&ptr,10);
        num+=  val * (long)pow(2,p);
        p=p-8;
        tok=strtok(NULL,".");
    }
    return(num);
}
