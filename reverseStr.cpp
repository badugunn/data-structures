#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;


void reverseStr(string& s)
{
  int n = s.length();
  int start = 0; int end = n-1;
  while(start<end)
  {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }
}

void reverseStr2(string& s)
{
  int n = s.length();
  for(int i=0; i<n/2; i++)
  {
    char temp = s[i];
    s[i] = s[n-i-1];
    s[n-i-1] = temp;
  }
}

int main()
{
  stack <char> s;
  string nam;
  nam = "Hari";
  int naml = 0;
  while(nam[naml]!='\0')
  {
    naml++;
  }
  cout<<nam<<endl;
  string namc;
  namc = nam;
  reverseStr(namc);
  cout<<namc<<endl;
  int len = namc.length();
  char op[len];
  int j=0;
  for(int i=len-1; i>=0; i--)
  {
    //cout<<namc[i]<<endl;
    op[j] = namc[i];
    j++;
  }
  op[j] = '\0';
  cout<<op<<endl;
  reverseStr2(namc);
  cout<<namc<<endl;

  for(int i=0; i<namc.length(); i++)
  {
    s.push(namc[i]);
  }
  for(int i=0; i<namc.length(); i++)
  {
    namc[i]=s.top();
    s.pop();
  }
  cout<<namc<<endl;


}
