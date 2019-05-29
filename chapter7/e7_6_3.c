#include <stdio.h>
#include <string.h>


#define MAXLINELEN 100

char *myfgets(char *s, int n, FILE *iop);

int myfputs(char *s, FILE *iop);

int mygetline(char *line, FILE *ifp, int max);

void filecompare(FILE *ifp1, FILE *ifp2);


int main(int argc, char * argv[])
{
  FILE *ftp1, *ftp2;

  char file1[]= "./e7_6.c";
  char file2[]="./e7_6_1.c";

  ftp1 = fopen(file1, "r");
  ftp2 = fopen(file2, "r");

  if(ftp1 == NULL)
  {
    printf("Error file 1\n");
  }

  if(ftp2 == NULL)
  {
    printf(" Error file 2\n");
  }

  filecompare(ftp1, ftp2);


  return 0;
}

void filecompare(FILE *ifp1, FILE *ifp2)
{
  char line1[MAXLINELEN];
  char line2[MAXLINELEN];

  int l1, l2;

  while( (l1 = mygetline(line1, ifp1, MAXLINELEN))!= 0 && (l2 = mygetline(line2, ifp2, MAXLINELEN))!=0)
    if(strcmp(line1,line2)!=0)
    {
      printf("file1 %s \n ", line1);
      printf(" File2 %s \n", line2);
      break;
    }
    else {
        // printf(" %s\n", line1);
    }

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
