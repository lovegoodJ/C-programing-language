#include<stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);

void reverse(char to[], char from[],int len);

main()
{

  int len;
  char line[MAXLINE];
  char re[MAXLINE];

  while((len = mygetline(line, MAXLINE))>0 )
  {
    reverse(re,line,len);
    printf("%d %s\n",len, re);
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

void reverse(char to[], char from[],int len)
{

  int i =0,lim = len;
  for(i =0; i<lim-1;i++,len--){
    to[i]=from[len-2];
  }
  to[i]='\0';
}
