#include <stdio.h>

int main(int argc, char * argv[])
{

  FILE *fp;

  void filecopy(FILE *, FILE *);
  char *prog = argv[0];

  if (argc ==1)
    {
      filecopy(stdin, stdout);
    } else{
      while(--argc > 0 )
      if ( (fp = fopen(*++argv, "r"))==NULL){
        fprintf(stderr, "Error open %s \n", *argv);
        exit(1);
      } else{
        filecopy(fp, stdout);
        fclose(fp);
      }
    }


  return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
  int c;
  while( (c= getc(ifp))!=EOF)
    putc(c, ofp);
}