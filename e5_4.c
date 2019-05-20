#include <stdio.h>

int strend(char *s, char *t);

main()
{
  char s[100] = "hello world";
  char t[] = "world";

  int rel;
  rel = strend(s,t);

  printf("%d \n",rel);
}

int strend(char *s, char *t)
{
  char * si = s;
  char * ti = t;
  while( (*s)!= '\0')
    s++;

  while( (*t) != '\0')
    t++;

  for( ; *s == *t ; s--, t--)
  {

    if(t==ti)
      return 1;
  }

  return 0;

}
