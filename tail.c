#include<stdio.h>
#include <string.h>
#define LASTN 10

int mygetline(char *line, int);

char *alloc(int n);


#define MAXLINE 5000


#define MAXLEN  1000

char *lineptr[MAXLINE];

int main(int argc, char *argv[])
{
  char c;

int n = 0;
char *s;

while(--argc>0)
{
  int i =0;
  s = *++argv;


      if(s[0] == '-')
        for(i=1;s[i]!='\0';i++)
          n =n*10 + s[i] -'0';
}

if(n ==0)
  n = LASTN;

  char line[MAXLEN];
  int len;
  int nlines =0;
  char *p;

  while( (len = mygetline(line, MAXLEN))> 0)
  {
    // printf("%d\n", len);
    if(nlines >= MAXLINE || (p = alloc(len+1)) == NULL)
    {
      printf("too large line \n");
      return -1;
    }

    strcpy(p, line);

    //#####
     // printf("%s\n", line);
    lineptr[nlines] = p;
    nlines++;
  }

  int i;
  for(i = 0; i<n; i++ )
  {
    printf("%s", lineptr[nlines - i - 1]);
  }



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


#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
  if( (allocp + n - allocbuf) < ALLOCSIZE)
  {
    allocp += n;
    return allocp - n;
  } else
  {
    printf("alloc error\n");
    return 0;
  }
}


void afree(char *p)
{
  if( p< allocbuf + ALLOCSIZE && p >= allocbuf)
  {
    allocp = p;
  }
}
