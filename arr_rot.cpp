#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void met1_rot(int arr[], int d, int n)
{
  for(int i=0; i<d; i++)
  {
    int tmp = arr[0];
    for(int j=0; j<n-1; j++)
    {
      arr[j] = arr[j+1];
    }
    arr[n-1]=tmp;
  }
}

void met2_rot(int arr[], int d, int n)
{
  int tmp[d];
  for(int i=0; i<d; i++)
  {
    tmp[i] = arr[i];
  }
  for(int i=0; i<n-d; i++)
  {
    arr[i] = arr[i+d];
  }
  int j=0;
  for(int i=n-d; i<n; i++)
  {
    arr[i] = tmp[j];
    j++;
  }
}

void printArr(int arr[], int n)
{
  cout<<"Array print start"<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<endl;
  }
  cout<<"Array print end"<<endl;
}

int main()
{
  int arrayV[7] = {1, 2, 3, 4, 5, 6, 7};
  printArr(arrayV, 7);
  met1_rot(arrayV, 2, 7);
  printArr(arrayV, 7);
}
