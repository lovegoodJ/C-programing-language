#include<stdio.h>

main()
{
  printf("Max number of unsigned char %d\n", (unsigned char) ~0);
  printf("Max number of signed char %d \n", (char) ((unsigned char)~0 >>1));
  printf("Min number of signed char %d \n", (char)-((unsigned char) ~0 >>1) -1);

  printf("Max number of unsigned short %d\n", (unsigned short) ~0);
  printf("Max number of signed short %d \n", ((unsigned short)~0 >>1));
  printf("Min number of signed short %d \n", -((unsigned short) ~0 >>1) -1);


  printf("Max number of unsigned int %u \n",  (unsigned int) ~0);
  printf("Max number of signed int %d \n", (int) ((unsigned int) ~0 >>1));
  printf("Min number of signed int %d \n", (int) -((unsigned int) ~0 >>1) -1);

  printf("Max number of unsigned long %lu \n", (unsigned long) ~0);
  printf("Max number of signed long %ld \n", (long) ((unsigned long) ~0 >>1));
  printf("Min number of signed long %ld \n", (long) -((unsigned long)~0 >>1) -1);
}
