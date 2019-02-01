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

int Partition(int a[], int start, int end)
{
  int pIndex = start;
  int pivot = a[end];
  for(int i=start; i<end; i++)
  {
    if(a[i]<pivot)
    {
      int temp = a[pIndex];
      a[pIndex] = a[i];
      a[i] = temp;
      pIndex++;
    }
  }
  int temp = a[end];
  a[end] = a[pIndex];
  a[pIndex] = temp;
  return pIndex;
}

void quickSort(int a[], int start, int end)
{
  if(start<end)
  {
  int pIndex = Partition(a, start, end);
  quickSort(a, start, pIndex-1);
  quickSort(a, pIndex+1, end);
  }
}


int main()
{
  int a[] = {25, -1, 0, 45, 22, 49};
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  quickSort(a,0,n-1);
  Print(a,n);
}
