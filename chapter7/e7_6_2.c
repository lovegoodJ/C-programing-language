#include <stdio.h>
#include <string.h>

char *myfgets(char *s, int n, FILE *iop);

int myfputs(char *s, FILE *iop);

int mygetline(char *line, int max);

int main()
{

  char tmp[100];
  mygetline(tmp, 100);
  printf(" %s\n", tmp);
  return 0;
}

char *myfgets(char *s, int n, FILE *iop)
{
  int c;
  char *cs =s;

  while(--n>0 && (c=getc(iop))!=EOF)
  {
    if (c =='\n')
      break;
    else
      *(s++) = c;
  }
  *s = '\n';
  return (c == EOF && cs ==s) ? NULL : cs;

}

char mfputs(char *s, FILE *iop)
{
  int c;
  while( (c= *s++)!='\0')
    putc(c, iop);
}

int mygetline(char *line, int max)
{
  if( fgets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}
