#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void arrange_index(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
    if(a[i]!=-1 && a[i]!=i)
    {
      int x = a[i];
      while(a[x]!=-1 && a[x]!=x)
      {
        int y = a[x];
        a[x] = x;
        x = y;
      }
      a[x] = x;
      if(a[i]!=i)
        a[i]=-1;
    }
  }
}


void Print(int a[], int n)
{
  cout<<"Start of array"<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<a[i]<<endl;
  }
  cout<<"End of the array"<<endl;
}

int main()
{
  int a[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  arrange_index(a, n);
  Print(a, n);
  return 0;
}
