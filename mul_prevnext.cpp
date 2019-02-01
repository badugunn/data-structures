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

void mul_prevnxt(int a[], int n)
{
  int prev = a[0];
  a[0] = a[0]*a[1];
  for(int i=1; i<n-1; i++)
  {
    int curr = prev*a[i+1];
    prev = a[i];
    a[i] = curr;
  }
  a[n-1] = prev*a[n-1];
}

int main()
{
  int a[] = {2, 3, 4, 5, 6};
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  mul_prevnxt(a,n);
  Print(a,n);
}
