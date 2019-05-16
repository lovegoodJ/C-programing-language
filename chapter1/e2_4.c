#include<stdio.h>


void squeeze(char s1[], char s2[]);

main()
{
 char s1[] = "hello";
 char s2[] = "ho";

 squeeze(s1, s2);
 printf("%s\n",s1);

}

void squeeze(char s1[], char s2[])
{
  int i, j, k;
  j =0;
  int match;

  for (i =0; s1[i] != '\0';i++)
  {
    match = 0;
    for(k =0; s2[k] != '\0'; k++)
    {
      if(s1[i] == s2[k])
      {
        match = 1;
      }
    }
    if(match == 0)
    {
      s1[j++] = s1[i];
    }

  }
  s1[j] = '\0';
}
