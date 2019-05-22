#include <stdio.h>

void mystrncpy(char *s, char *t, int n);

 void mystrncat(char *s, char *t, int n);

int mystrncmp(char *s, char *t, int n );

main(){
  char s[100] = "hello world";
  char t[] = "hello my world";

  int rel;
  rel = mystrncmp(s,t,3);

  printf("%d \n",rel);
}


void mystrncpy(char *s, char *t, int n)
{
  char *ti = t;
  for( ; *t != '\0' && (t - ti) < n; t++, s++ )
  {
    *s = *t;
  }
  *s = '\0';
}

void mystrncat(char *s, char *t, int n)
{
  char *ti = t;

  while( (*s) != '\0')
    s++;

  for(; *t != '\0' && (t - ti) < n; s++, t++)
  {
    *s = *t;
  }
  *s = '\0';
}



int mystrncmp(char *s, char *t, int n)
{
  char *ti = t;

  for (; *s == *t && (t - ti)<n; t++, s++)
    if(*ti == '0' || (t - ti) == (n -1))
      return 0;

  return *s - *ti;
}
