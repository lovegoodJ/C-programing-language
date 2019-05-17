#include<stdio.h>
#include<string.h>

void reverse(char s[]);

void itoa(int n, char s[]);

main()
{
  int n = -((unsigned int)~0 >>1) -1 ;
  char s[100];
  itoa(n,s);
  printf("%d\n",n);
  printf("%s\n",s);
}


void itoa(int n, char s[])
{
  int i=0, sign;
  unsigned int ui;
  if((sign=n)<0){
    ui = -n;
  }
  else{
    ui = n;
  }

  do{
    s[i] = ui%10 + '0';
    i++;
  }while((ui= ui/10)>0);

  if(sign<0)
  {
    s[i]='-';
    i++;
  }
  s[i]='\0';
  printf("itoa %s \n", s);
  reverse(s);

}


void reverse(char s[])
{
    static int i = 0;
    printf("%d\n",i);
    int j = strlen(s)-1;
    char c;
    c = s[j-i];
    s[j-i] = s[i];
    s[i++] = c;
    
    if(i< j-i)
    {
      reverse(s);
      printf("%d\n",i);
    }


}
