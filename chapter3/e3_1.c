#include<stdio.h>

int binsearch(int x, int v[], int n);


main()
{
  int n = 7;
  int v[7] ={1,2,3,4,5,6,7};

  int x = 8;
  int pos;
  pos = binsearch(x, v, n);
  printf("%d\n", pos);
}

int binsearch(int x, int v[], int n)
{
  int low = 0;
  int high = n-1;
  int mid;

  while(low <= high){
    mid  = (low + high)/2;
    if(x>v[mid]){
      low = mid +1;
    }
    else if(x<v[mid])
    {
      high = mid -1;
    }
    else
    {
      return mid;
    }
  }

  return -1;

}
