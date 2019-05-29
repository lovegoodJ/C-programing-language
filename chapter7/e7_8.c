#include <stdio.h>
#include <string.h>


#define MAXLINELEN 100

char *myfgets(char *s, int n, FILE *iop);

int myfputs(char *s, FILE *iop);

int mygetline(char *line, FILE *ifp, int max);

int printfile( char *file);


int main(int argc, char * argv[])
{
  char pattern[] ="include";
  int page = 1;
  if (argc ==1)
    {
        printf("Error \n");
    } else{
      while(--argc > 0 )
      {

        printf("Page %d Title %s \n", page, *++argv);
        printfile(*argv);
        page++;
      }
    }


  return 0;
}

int printfile(char *file)
{
  char line[MAXLINELEN];
  int l1;
  FILE *ifp = fopen(file, "r");

  if(ifp == NULL)
  {
    printf(" Error opne %s ", file);
    return -1;
  }

  while((l1 = mygetline(line, ifp, MAXLINELEN)) != 0)
  {

      printf("%s", line);

  }

  fclose(ifp);
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

int mygetline(char *line, FILE *inp, int max)
{
  if( fgets(line, max, inp) == NULL)
    return 0;
  else
    return strlen(line);
}
