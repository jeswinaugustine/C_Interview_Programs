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
    char ip[15]="10.20.30.40";
    long ip_int;
    printf("Enter any IP Address to be converted :: ");
    //scanf("%s",ip);


    ip_int = conv(ip);
    long output = 169090600;

    printf("\nEquivalent 32-bit long int is :: %ld %ld\n",ip_int,output);
}

int to_digit(char *num){
    int i=0;

    int digit =0;
    //printf("\n Strlen %d for %s\n",i,num);
    while(i < strlen(num)) {
        digit = (10*digit) + ( num[i]-'0');
        i++;
    }
    return digit;
}



long conv(char ipadr[])
{
    long num=0;
    char octect[4];
    int i=0,count =0,o_count=0,digit=0;
    for(i=0;ipadr[i] != '\0';i++) {
        if(ipadr[i] == '.') {
            octect[o_count]='\0';
            digit = to_digit(octect);
            printf(" Num [%d] : %d >> num is %ld\n\n",count,digit,num);
            o_count=0;
            memset(octect,0,4);
            num = num | (digit<<((3-count)*8));
            count++;
            if(count >=4) {
                printf("Invalid IP!");
                return 0;
            }
        } else {
        octect[o_count]=ipadr[i];
        o_count++;
        }

    }
        octect[o_count]='\0';
        digit = to_digit(octect);
        printf(" Num [%d] : %d >> num is %ld\n\n",count,digit,num);
        num = num | (digit<<((3-count)*8));

    return(num);
}
