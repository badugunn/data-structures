#include <iostream>
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
struct Node* prev;
};
void insertatHead(int data);
void Print();
void insertatTail(int data);
void ReversePrint();
Node* GetnewNode(int data);
struct Node* head;

using namespace std;

int main()
{
    head = NULL;
    insertatHead(5);
    insertatTail(6);
    insertatHead(8);
    insertatTail(10);
    Print();
    ReversePrint();
    return 0;
}

Node* GetnewNode(int data)
{
   Node* temp = new Node();
   temp->data = data;
   temp->next = NULL;
   temp->prev = NULL;

   return temp;
}
void insertatHead(int data)
{
Node* temp = GetnewNode(data);
if(head == NULL)
{
head =temp;
return;
}
head->prev = temp;
temp->next=head;
head = temp;
return;

}
void insertatTail(int data)
{
Node* temp = GetnewNode(data);
if(head == NULL)
{
head = temp;
return;
}
Node* temp1 = head;
while(temp1->next != NULL)
{
   temp1 = temp1->next;
}
temp1->next = temp;
temp->prev = temp1;
return;

}


void Print()
{
Node* temp = head;
cout<<"Forward print is"<<endl;
while (temp!=NULL)
{
cout<<temp->data<<endl;
temp=temp->next;
}

return;
}

void ReversePrint()
{
Node* temp = head;
cout<<"Reverse Print is"<<endl;
while(temp->next != NULL)
{
temp = temp->next;
}
while(temp!=NULL)
{
cout<<temp->data<<endl;
temp = temp->prev;
}
return;
}


