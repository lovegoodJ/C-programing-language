#include <stdio.h>
#define IN 1
#define OUT 0

main()
{

int length[10];

int state=OUT;
char c;
int count= 0;

for(int i =0;i<10;i++)
  length[i] = 0;


while((c = getchar()) != EOF){
  if(c == ' '|| c == '\n'|| c== '\t')
  {
   if(state == IN)
   {
    length[count]++;
    count = 0;
     state = OUT;
   }
 }
  else
  {
    count++;
    state = IN;
  }
}
for(int i = 0; i<10; i++){
  printf("%d:",i);
  int len = length[i];
  while(len>0)
  {
    len--;
    printf("*");
  }
 printf("\n");
}


}
