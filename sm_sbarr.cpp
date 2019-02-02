#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


void Print(int a[], int n)
{
  cout<<"Start of array"<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<a[i]<<endl;
  }
  cout<<"End of the array"<<endl;
}

int simpleSbar(int a[], int n, int sum)
{
  int min_len = n+1;
  for(int i =0; i<n; i++)
  {
    int csum = a[i];
    if(csum>sum)
      return 1;
    for(int j=i+1; j<n; j++)
    {
      csum = csum + a[j];
      if(csum>sum && (j-i+1)<min_len)
        min_len = j-i+1;
    }
  }
  return min_len;
}


int subarSum(int a[], int n, int sum)
{
  int min_len = n+1, csum =0;
  int start = 0, end = 0;
  while(end<n)
  {
    while(csum<=sum && end<n)
    {
      csum = csum+a[end];
      end++;
    }
    while(csum>sum && start < n)
    {
      if(end-start<min_len)
        min_len = end-start;
      csum = csum - a[start];
      start++;
    }
  }
  return min_len;
}

int main()
{
  int a[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
  int n = sizeof(a)/sizeof(a[0]);
  //Print(a, n);
  int sSum = subarSum(a, n, 99);
  cout<<sSum<<endl;
  //Print(a,n);
}
