#include <stdio.h>

void mystrcat(char *s, char *t);

main()
{
  char s[100] = "hello";
  char t[] = "world";

  mystrcat(s,t);

  printf("%s \n",s);
}

void mystrcat(char *s, char *t)
{
  for( ; *s != '\0'; s++)
    ;

  for(; (*s = *t); t++, s++)
  {

  }

  *s = '\0';

}
