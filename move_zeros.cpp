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

//25 32 0 35 0 45

void move_zeros_st(int a[], int n)
{
  int cnt = 0;
  for(int i=0; i<n; i++)
  {
    if(a[i]!=0)
    {
      int tmp = a[cnt];
      a[cnt] = a[i];
      a[i] = tmp;
      cnt++;
    }
  }
}
void move_zeros(int a[], int n)
{
  int zcnt = 0;
  int idx = 0;
  for(int i=0; i<n; i++)
  {
    if(a[i]==0)
      zcnt=zcnt+1;
    else
    {
      a[idx] = a[i];
      idx++;
    }
  }
  for(int i=idx+1; i<n; i++)
    a[i] = 0;
}

int main()
{
  int a[] = {25, 32, 0, 45, 0, 45};
  int n = sizeof(a)/sizeof(a[0]);
  Print(a, n);
  move_zeros_st(a,n);
  Print(a,n);
}
