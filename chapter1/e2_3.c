#include<stdio.h>

int htoi(char s[]);

main()
{

  char s[] = "0x1A";

  int rel = htoi(s);
  printf("%s is %d\n",s,rel);

}


int htoi(char s[])
{

  int i, n;

  n = 0;
  if(s[0]!='0')
  {
    putchar(s[0]);
    return -1;
  }

  if(s[1] != 'x'&&s[1] != 'X')
  {
    return -2;
  }

  for (i =2; s[i] != '\0'; i++)
  {
    printf("n %d \n", n);
    if(s[i] >= '0'|| s[i] <= '9' )
    {
      n = 16*n + (s[i] - '0');
    }
    else if(s[i] >= 'a'|| s[i] <= 'f' )
    {
      n = 16*n + (s[i] - 'a' + 10);
    }
    else  if(s[i] >= 'A'|| s[i] <= 'F' )
    {
      n = 16*n + (s[i] - 'A' + 10);
    }
    else
    {
      return -3;
    }


  }

return n;
}
