#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 101
using namespace std;

class Stack {
private:
  int A[MAX_SIZE];
  int top;
public:
  Stack()
  {
    top = -1;
  }
  void Push(int x)
  {
    if(top == MAX_SIZE-1)
    {
      cout<<"Error stack overflow "<<endl;
      return;
    }
        top = top+1;
    A[top]=x;

  }
  int isEmpty()
  {
    if(top==-1) return 1;
    else return 0;
  }
  void Pop()
  {
    if(top = -1)
    {
      cout<<"Empty stack"<<endl;
      return;
    }
    top = top-1;
  }
  int Top()
  {
    return A[top];
  }
  void Print() {
  int i;
  printf("Stack: ");
  for(i = 0;i<=top;i++)
    printf("%d ",A[i]);
  printf("\n");
}
};





int main()
{
    // Code to test the implementation.
    // calling Print() after each push or pop to see the state of stack.
	Stack S;
	S.Push(2);S.Print();
	S.Push(5);S.Print();
	S.Push(10);S.Print();
	S.Pop();S.Print();
	S.Push(12);S.Print();
}
