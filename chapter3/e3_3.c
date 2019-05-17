#include<stdio.h>

void expand(char s1[], char s2[]);

main()
{
  char s2[200];
  char s1[]= "-a-b-c1-9-";
  printf("%s\n",s1);
  expand(s1,s2);
  printf("%s\n",s2);

}



void expand(char s1[], char s2[])
{
  char c1,c2,c3;

  int i;
  int j=1;

  s2[0]=s1[0];
  c1 = s1[0];

  for(i =1; s1[i] != '\0'; i++)
  {
    c2 =s1[i];
    if(c2 == '-')
    {
      i++;
      c3 = s1[i];
      if(c3 =='\0')
      {
        s2[j]=c2;
        j++;

      }
      else
      {
        for(c1++;c1<=c3;c1++)
        {
          s2[j]=c1;
          j++;
        }
      }

      c1 = c3;
    }
    else
    {
      c1 = c2;
      s2[j] = c2;
      j++;
    }

  }


}
