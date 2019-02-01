#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int binarySearch(int a[], int low, int high, int val)
{
  if(low > high)
    return -1;
  int mid = (low + high) / 2;
  if(a[mid]==val)
    return mid;
  if(val>a[mid])
    binarySearch(a, mid+1, high, val);
  else
    binarySearch(a, low, mid-1, val);
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


int pivotedBinarySearch(int a[], int low, int high, int val)
{
  int piv = findPivot(a, low, high);
  if(piv == -1)
    return binarySearch(a, low, high, val);
  if(val>a[0])
    return binarySearch(a, low, piv, val);
  else if(val<a[0])
    return binarySearch(a, piv+1, high, val);
  else if(val==a[0])
    return binarySearch(a, low, high, val);
}

int main()
{
  int A[7] = {6,7,1,2,3,4,5};
  int idx = pivotedBinarySearch(A,0,6,7);
  cout<<idx<<endl;
  return 0;
}
