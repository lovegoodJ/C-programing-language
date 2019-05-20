#include<stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);

int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
  char line[MAXLINE];
  int found = 0;
  char c;

  int lim = 0;
  int index ;
  while(  mygetline(line, MAXLINE))
  {
    if( (index = strindex(line, pattern))>0){
      printf("%d\n", index);
      found++;
    }
  }
  return found;
}


int mygetline(char *line, int max)
{

 int lim = 0;
 int c;

 while( (lim<max) && (c=getchar()) != EOF && c != '\n')
 {
   *line++ = c;
   lim++;
 }
 if(c == '\n')
  *line++ = c;

 *line = '\0';
  return lim;
}

int strindex(char *source, char *searchfor)
{

 char * s1 =source;
 char *s2 = searchfor;

 for(; *source !='\0'; source++)
 {
   for(; *searchfor!= '\0' && *searchfor == *(source + (searchfor - s2)); searchfor++)
   ;
   if(*searchfor == '\0')
    return source - s1;
 }

return -1;



}
