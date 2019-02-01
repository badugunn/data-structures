#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int existPair(int a[], int low, int high, int sum)
{
  int l, r;
  for(int i = 0; i<high; i++)
  {
    if(a[i]>a[i+1])
    {
      l = i;
      r = (i+1)%(high+1);
      break;
    }
  }
  while(l!=r)
  {
    if(a[l]+a[r] == sum)
      return 1;
    if(a[l]+a[r]>sum)
      r=(r+1)%(high+1);
    else
      l=(l-1+(high+1))%(high+1);
  }
  return -1;
}

int findPivot(int a[], int low, int high)
{
  if(low>high)
    return -1;
  if(low==high)
    return low;
  int mid = (low+high)/2;
  if(mid > low && a[mid]>a[mid+1])
    return mid;
  if(mid > low && a[mid]<a[mid-1])
    return (mid-1);
  if(a[low]<a[mid])
    return findPivot(a, mid+1, high);
  else
    return findPivot(a, low, mid);
}

int existPairPivot(int a[], int low, int high, int sum)
{
  int r;
  int l = findPivot(a, low, high);
  r = (l + 1)%(high+1);
  while(l!=r)
  {
    if(a[l]+a[r] == sum)
      return 1;
    if(a[l]+a[r]>sum)
      r=(r+1)%(high+1);
    else
      l=(l-1+(high+1))%(high+1);
  }
  return -1;
}


int main()
{
  int a[5] = {20, 24, 29, 1, 2};
  int opt = existPairPivot(a, 0, 4, 30);
  cout<<opt<<endl;
  return 0;
}
