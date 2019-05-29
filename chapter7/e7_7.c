#include <stdio.h>
#include <string.h>


#define MAXLINELEN 100

char *myfgets(char *s, int n, FILE *iop);

int myfputs(char *s, FILE *iop);

int mygetline(char *line, FILE *ifp, int max);

int find(char *s, char *file);


int main(int argc, char * argv[])
{
  char pattern[] ="include";

  if (argc ==1)
    {
        printf("Error \n");
    } else{
      while(--argc > 0 )
      {
        find(pattern, *++argv);
      }
    }


  return 0;
}

int find(char * s, char *file)
{
  char line[MAXLINELEN];
  int l1;
  FILE *ifp = fopen(file, "r");

  if(ifp == NULL)
  {n
    printf(" Error opne %s ", file);
    return -1;
  }

  while((l1 = mygetline(line, ifp, MAXLINELEN)) != 0)
  {

    if(strstr(line, s)!= NULL){
      printf("File %s\n", file);
      printf(" line %s \n", line);
    }
  }

  fclose(ifp);
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
