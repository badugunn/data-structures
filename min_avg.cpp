#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stdio.h>

using namespace std;

int minAvg(int a[], int n, int k)
{
  if(n<k)
    return -1;
  int minSum = 0;
  int stIdx = 0;
  for(int i=0; i<k; i=i+1)
    minSum = minSum + a[i];
  int arSum = minSum;
  for(int i=k; i<n; i=i+1)
  {
    arSum = arSum + a[i] - a[i-k];
    if(arSum<minSum)
      minSum = arSum;
      stIdx = i-k+1;
  }
  return stIdx;
}


int main()
{
  int arr[] = { 3, 7, 90, 20, 10, 50, 40 };
  int k = 3; // Subarray size
  int n = sizeof arr / sizeof arr[0];
  int opt = minAvg(arr, n, k);
  cout<<opt<<endl;
  return 0;
}
