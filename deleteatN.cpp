#include <iostream>
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
void insertatEnd(int data);
void Print();
void Delete(int n);
void insertatStart(int data);
void insertatN(int data, int n);
struct Node* head;

using namespace std;

int main()
{
   head = NULL;
   insertatEnd(2);
   insertatStart(3);
   insertatN(5,1);
   insertatN(6,2);
   Print();
   Delete(2);
   Print();
   Delete(1);
   Print();
    //cout << "Hello world!" << endl;
    return 0;
}
void insertatEnd(int data)
{
   Node* ntemp = new Node();
   ntemp->data=data;
   ntemp->next = NULL;
   if(head == NULL)
   {
   head = ntemp;
   return;
   }
   Node* temp = head;
   while (temp->next!= NULL)
   {
      temp = temp->next;
   }

   temp->next=ntemp;

return;
}

void Delete(int n)
{
   Node* temp =head;
   if(n==1)
   {
   head = temp->next;
   delete temp;
   }
   else{
   for(int i =1; i< n-1; i++)
   {
   temp = temp->next;
   }
   Node* temp2 = temp->next;
   temp->next = temp2->next;
   delete temp2;

   }
return;
}


void Print()
{
   Node* temp = head;
   cout << "List is "<<endl;
   while(temp!=NULL)
   {
      cout<<temp->data<<endl;
      temp = temp->next;
   }
return;
}
void insertatStart(int data)
{
   Node* temp = new Node();
   temp->data = data;
   temp->next=head;
   head = temp;
return;
}
void insertatN(int data, int n)
{
   Node* temp = new Node();
   temp->data = data;
   if(n==1)
   {
      temp->next = head;
      head = temp;
      return;
   }
   else {
      Node* temp2 = head;
      for(int i=1; i<n-1; i++)
      {
         temp2 = temp2->next;
      }
      temp->next = temp2->next;
      temp2->next= temp;
      return;
   }
return;
}