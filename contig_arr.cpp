#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stdio.h>

using namespace std;


int contArr(int a[], int n)
{
  int max_so_far = 0;
  int cont_sum = 0;
  for(int i=0; i<n; i++)
  {
    cont_sum = cont_sum + a[i];
    if(cont_sum<=0)
      cont_sum = 0;
    if(max_so_far<cont_sum)
      max_so_far = cont_sum;
  }
  return max_so_far;
}

int contArrSize(int a[], int n)
{
  int max_so_far = 0;
  int cont_sum = 0;
  int start=0, s=0, end=0;
  for(int i=0; i<n; i++)
  {
    cont_sum = cont_sum + a[i];
    if(cont_sum<=0)
    {
      cont_sum = 0;
      s = i+1;
    }
    if(max_so_far<cont_sum)
    {
      max_so_far = cont_sum;
      end = i;
      start = s;
    }
  }
  return (end-start+1);
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = contArr(a, n);
    cout << "Maximum contiguous sum is " << max_sum<<endl;
    int size = contArrSize(a, n);
    cout<<"Max array size is "<<size<<endl;
    return 0;
}
