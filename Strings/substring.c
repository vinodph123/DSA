#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
  const char *p=string;
  const char *p1=ending;
  int s=strlen(string);
  int s1=strlen(ending);
  int size=s-s1,i,j;
  for(i=size,j=0;i<s,j<s1;i++,j++)
    {
    if(p[i] == p1[j])
      continue;
    else
      return false;
    }
    return true;
}

int main()
{
    char p[]="ails";
    char p1[]="fails";

    printf("Solution = %d\n",solution(p,p1));

    return 0;
}