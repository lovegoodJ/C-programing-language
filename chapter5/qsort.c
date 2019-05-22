#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 5000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int maxline);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);

int main(int argc, char *argv[])
{
  int nlines;

  int numeric=0;

  if(argc>1 && strcmp(*++argv , "-n") == 0){
    numeric = 1;
  }

  if( (nlines = readlines(lineptr, MAXLINE) ) >0 )
  {
    printf("11111\n");

        // writelines(lineptr, nlines);
     myqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ==1 ? numcmp : strcmp) );

    //  qsort(lineptr, 0, nlines-1, (numeric ==1 ? numeric : strcmp) );

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




// #########################################################


  #define MAXLEN 1000

  int mygetline(char *line, int);

  char *alloc(int n);

  int readlines(char *lineptr[], int maxlines)
  {
    int len;
    char line[MAXLEN];
    int nlines =0;
    char *p;

    while( (len = mygetline(line, MAXLEN))> 0)
    {
      // printf("%d\n", len);
      if(nlines >= maxlines || (p = alloc(len+1)) == NULL)
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

    return nlines;
  }

  void writelines(char * lineptr[], int nlines)
  {
    int i;
    for(i =0; i<nlines; i++)
      printf("%d %s \n", i, lineptr[i]);
  }


// #########################################################################

  void myqsort(void *v[], int left, int right, int (*comp)(void *, void *))
  {
    int i, last;

    void swap(void *v[], int i, int j);


    if (left >= right)
      return;

    swap(v, left, (left + right)/2);


    last = left;

    for(i=left + 1; i<=right; i++)
    {

      if((*comp)(v[i], v[left]) <0)
      {
                  // printf(" qqqq\n");
        last++;
        swap(v, last, i);
      }
    }

    swap(v, left, last);

    myqsort(v, left, last-1, comp);
    myqsort(v, last +1, right, comp);

  }

  void swap(void *v[], int i, int j)
  {
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
  }



int numcmp(char *s, char *t)
{
  double v1, v2;
  v1 = atof(s);
  v2  = atof(t);
  // printf("s %s, t %s \n", s,t);
  if(v1>v2)
    return 1;
  if (v1== v2)
    return 0;
  if( v1<v2)
    return -1;
}

// ?##########################################################################


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
