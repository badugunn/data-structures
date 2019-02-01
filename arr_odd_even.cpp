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

void bubbleSort(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
    for(int j = 0; j<n-i-1; j++)
    {
      if(a[j]>a[j+1])
      {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}

void arr_even(int a[], int n)
{
  int b[n] = {0};
  for(int i=0; i<n; i++)
  {
    b[i] = a[i];
  }
  bubbleSort(b, n);
  //Print(b,n);
  int ePos = n/2;
  int oPos = n-ePos;
  int j = oPos - 1;
  for(int i=0; i<n; i=i+2)
  {
    a[i] = b[j];
    j--;
  }
  j = oPos;
  for(int i=1; i<n; i=i+2)
  {
    a[i] = b[j];
    j++;
  }

}

int main()
{
  int a[] = {25, 32, 65, 45, 84, 45};
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  arr_even(a,n);
  Print(a,n);
}
