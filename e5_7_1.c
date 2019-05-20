#include <stdio.h>
#include <string.h>

#define MAXLINE 5000

  char *lineptr[MAXLINE];

int readlines(char *lineptr[], int maxline, char buff[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main()
{
  int nlines;
  char buff[10000];

  if( (nlines = readlines(lineptr, MAXLINE, buff) ) >0 )
  {
    printf("11111\n");

        // writelines(lineptr, nlines);
    qsort(lineptr, 0, nlines-1);

    printf("11111\n");
    writelines(lineptr, nlines);
    return 0;

  }
  else
  {
   printf(" Error \n");
   return -1;
  }

}





#define MAXLEN 1000

int mygetline(char *line, int);

char *alloc(int n);

int readlines(char *lineptr[], int maxlines, char *buff)
{
  int len;
  char line[MAXLEN];
  int nlines =0;

  while( (len = mygetline(line, MAXLEN))> 0)
  {
    // printf("%d\n", len);
    if(nlines >= maxlines )
    {
      printf("too large line \n");
      return -1;
    }


    strcpy(buff, line);

    //#####
     // printf("%s\n", line);
    lineptr[nlines] = buff;
    buff += len +1;
    nlines++;
  }

  return nlines;
}

void writelines(char * lineptr[], int nlines)
{
  int i;
  for(i =0; i<nlines; i++)
    printf("%d %s \n", i, lineptr[i]);
}


void qsort(char *v[], int left, int right)
{
  int i, last;

  void swap(char *v[], int i, int j);


  if (left >= right)
    return;

  swap(v, left, (left + right)/2);

  last = left;

  for(i=left + 1; i<=right; i++)
  {
    if(strcmp(v[i], v[left]) <0)
    {
      last++;
      swap(v, last, i);
    }
  }

  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last +1, right);

}

void swap(char *v[], int i, int j)
{
  char *tmp;

  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
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
