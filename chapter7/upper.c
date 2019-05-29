#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char * argv[])
{
  int c;
  printf("%s\n",argv[0]);
  if(strstr(argv[0], "lower")!=NULL)
  {
    while( (c=getchar()) !=EOF){
      putchar(tolower(c));
    }
  } else if( strstr(argv[0], "upper")!=NULL){
    while( (c=getchar()) !=EOF){
      putchar(toupper(c));
  }
}else {
    while( (c=getchar()) !=EOF){
      putchar(c);
  }
}
return 0;

}
