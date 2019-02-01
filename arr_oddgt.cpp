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


void arr_oddgt(int a[], int n)
{
  for(int i=0; i<n-1; i++)
  {
    if(i%2==0 && a[i]>a[i+1])
    {
      int tmp = a[i];
      a[i] = a[i+1];
      a[i+1] = tmp;
    }
    else if(i%2==1 && a[i]<a[i+1])
    {
      int tmp = a[i];
      a[i] = a[i+1];
      a[i+1] = tmp;
    }
  }
}

int main()
{
  int a[] = {6, 4, 2, 1, 8, 3};
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  arr_oddgt(a,n);
  Print(a,n);
}
