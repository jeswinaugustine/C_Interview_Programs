

#include <stdio.h>
#include <string.h>


int my_strstr(char *in, char* sub) {

	int i,j,k,count=0;

	for (i=0; i<(strlen(in) - strlen(sub))-1; i++) {
		k=i;
		for(j=0;j<strlen(sub);j++) {
			if(in[k] != sub[j]){
				break;
			}
			k++;
		}
		if(j == strlen(sub)) {
			count++;
		}
	}
	return count;
}



int main(void) {
	// your code goes here

	char in[] ="intermediate in india in organization";
	char sub[] ="in";
	int result =0;
	result = my_strstr(in,sub);
	printf("Len = %d %d",strlen(in),strlen(sub));
	printf("Count = %d",result);


	return 0;
}
