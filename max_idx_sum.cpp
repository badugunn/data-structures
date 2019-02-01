#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int maxArsum(int a[], int n)
{
  int arrSum = 0;
  int jSum = 0;
  for(int i=0; i<n; i++)
  {
    arrSum = arrSum + a[i];
    jSum = jSum + (i*a[i]);
  }
  int maxSum = jSum;
  for(int j=1; j<n; j++)
  {
    jSum = jSum + arrSum - (n*a[n-j]);
    if(jSum>maxSum)
      maxSum = jSum;
  }
  return maxSum;
}

int main()
{
  int a[] = {10,1, 2, 3,4,5,6,7,8,9};
  int n = sizeof(a)/sizeof(a[0]);
  int maxarsum = maxArsum(a, n);
  cout<<"Max array sum is "<<maxarsum<<endl;
  return 0;
}
