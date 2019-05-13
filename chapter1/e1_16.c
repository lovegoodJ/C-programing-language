#include<stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);

void copy(char to[], char from[]);

main()
{

  int len;
  char line[MAXLINE];

  while((len = mygetline(line, MAXLINE))>0 )
  {
    printf("%d %s\n",len, line);
  }
}

int mygetline(char line[], int maxline)
{
  int i = 0;

  char c;
  for( i =0; (c = getchar())!=EOF && c != '\n' && i <maxline - 1; i++ )
  {
    line[i]=c;
  }
  if (c=='\n')
  {
    line[i] = c;
    i++;
  }
  line[i]='\0';
return i;
}

void copy(char to[], char from[])
{

  int i =0;
  while((to[i]=from[i]) !='\0')
  {
    i++;
  }
}
