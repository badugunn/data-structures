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
  int pivot = 0;
  int pIndex = start;
  for(int i=start; i<end; i++)
  {
    if(a[i]<pivot)
    {
      int temp = a[i];
      a[i] = a[pIndex];
      a[pIndex] = temp;
      pIndex++;
    }
  }
  return pIndex;
}


void alt_pos_neg(int a[], int start, int end)
{
  int pIndex = Partition(a, start, end);
  for(int i=0; i<pIndex; i=i+2)
  {
    int temp = a[pIndex];
    a[pIndex] = a[i];
    a[i] = temp;
    pIndex++;
  }
//  cout<<pIndex<<endl;
}


int main()
{
  int a[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  alt_pos_neg(a,0,n-1);
  Print(a,n);
}
