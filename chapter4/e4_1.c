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


int mygetline(char line[], int max)
{

 int lim = 0;
 int c;

 while( (lim<max) && (c=getchar()) != EOF && c != '\n')
 {
   line[lim++] = c;
 }
 if(c == '\n')
  line[lim++] = c;

 line[lim] = '\0';
  return lim;
}

int strindex(char source[], char searchfor[])
{

 int i,j;

 for(i =0; source[i]!='\0'; i++)
 {
   for(j=0; searchfor[j]!= '\0' && searchfor[j] == source[j+i]; j++)
   ;
   if(searchfor[j] == '\0')
    return i;
 }

return -1;



}
