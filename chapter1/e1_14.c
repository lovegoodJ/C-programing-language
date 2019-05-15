#include <stdio.h>
#define IN 1
#define OUT 0

main()
{

int num = 256;
int length[num];

int c;
int count= 0;

for(int i =0;i<num;i++)
  length[i] = 0;


while((c = getchar()) != EOF){

    length[c]++;

}
for(int i = 0; i<num; i++){
  printf("%c",i);
  int len = length[i];
  while(len>0)
  {
    len--;
    printf("*");
  }
 printf("\n");
}


}
