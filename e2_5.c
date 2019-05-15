#include<stdio.h>


int any(char s1[], char s2[]);

main()
{
  int pos;
 char s1[] = "hello";
 char s2[] = "el";

 pos = any(s1, s2);
 printf("%d\n",pos);

}

int any(char s1[], char s2[])
{
  int i,  k;

  for (i =0; s1[i] != '\0';i++)
  {
    for(k =0; s2[k] != '\0'; k++)
    {
      if(s1[i] == s2[k])
      {
        return i +1 ;
      }
    }

  }
  return -1;
}
