#include <stdio.h>
int main()
{
  char str[1000], rev[1000];
  int i, j, count = 0;
  scanf("%s", str);
  printf("\nString Before Reverse: %s", str);
  //finding the length of the string
  while (str[count] != '\0')
  {
    count++;
  }
  j = count - 1;
  //reversing the string by swapping
  for (i = 0; i < count; i++)
  {
    rev[i] = str[j];
    j--;
  }

  printf("\nString After Reverse: %s", rev);
}

/*
OR

void reverseStr(char str[])
{
  int n = strlen(str);

  for (int i = 0; i < n / 2; i++)
  {
    char ch = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = ch;
  }
}

int main()
{
  char str[1000];
  scanf("%s", str);
  printf("\nString Before Reverse: %s", str);
  reverseStr(str);
  printf("\nString After Reverse: %s", str);
  return 0;
}

*/
