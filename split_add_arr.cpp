#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

void SplitAddArray(int a[], int n, int j)
{
  int tmp[j+1] = {0};
  for(int i=0; i<=j; i++)
  {
    tmp[i] = a[i];
  }
  for(int i=0; i<n-j-1; i++)
  {
    a[i] = a[i+j+1];
  }
  int idx = 0;
  for(int i=n-j-1; i<n; i++)
  {
    a[i] = tmp[idx];
    idx++;
  }
}

void reverseArr(int a[], int low, int high)
{
  while(low<high)
  {
    int tmp = a[low];
    a[low] = a[high];
    a[high] = tmp;
    low++;
    high--;
  }
}

void splitN(int a[], int n, int pos)
{
  reverseArr(a, 0, n-1);
  reverseArr(a, 0, n-pos-1);
  reverseArr(a, n-pos, n-1);
}

void SplitArraynk(int a[], int n, int pos)
{
  for(int i = 0; i<pos; i++)
  {
    int tmp = a[0];
    for(int j=0; j<n; j++)
    {
      a[j] = a[j+1];
    }
    a[n-1] = tmp;
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
  int a[7] = {1,2,3,4,5,6,7};
  Print(a, 7);
  splitN(a,7,2);
  Print(a, 7);
  return 0;
}
