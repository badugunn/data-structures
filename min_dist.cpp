#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stdio.h>

using namespace std;

int minDist(int a[], int n, int x, int y)
{
  int xidx, yidx;
  int min = INT8_MAX;
  for(int i=0; i<n; i++)
  {
    for(int j = i+1; j<n; j++)
    {
      if(((x==a[i] && y==a[j]) || (x==a[j] && y==a[i])) && min > abs(i-j))
        min = abs(i-j);
    }
  }
  return min;
}


int minTricky(int a[], int n, int x, int y)
{
  int prev, xidx, yidx;
  int min = INT8_MAX;
  for(int i=0; i<n; i++)
  {
    if(a[i]==x || a[i]==y)
    {
      prev=i;
      break;
    }
  }
  for(int i=prev+1; i<n; i++)
  {
    if(a[i]==x||a[i]==y)
    {
      if(a[prev]!=a[i] && min > (i-prev))
      {
        min = i - prev;
        prev = i;
      }
      else
        prev = i;
    }
  }
  return min;
}

int main()
{
  int a[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
  int n = sizeof(a)/sizeof(a[0]);
  int x = 3;
  int y = 6;
  int Mdist = minTricky(a, n, x, y);
  cout<<Mdist<<endl;
}
