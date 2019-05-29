#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char * argv[])
{
  int c;

  while( (c=getchar()) !=EOF){
    if(isgraph(c)!=0)
      putchar(c);
    else{
      printf("%o",c);
    }
  }



return 0;

}
