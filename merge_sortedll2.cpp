#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

//Node* head = NULL;

void insertAtHead(Node** head, int data)
{
  Node* tmp = new Node;
  tmp->data = data;
  tmp->next = *head;
  *head = tmp;
}

void insertAtTail(Node** head, int data)
{
  Node*  newNode = new Node;
  if(*head!=NULL)
  {
    Node* tmp = *head;
    while (tmp->next!=NULL)
    {
      tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
  }
  else
  {
    newNode->data = data;
    newNode->next = NULL;
    *head = newNode;
  }
}

void insertatN(Node** head, int data, int pos)
{
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  Node* tmp = *head;
  if(pos==1)
  {
    newNode->next = *head;
    *head = newNode;
  }
  else
  {
    for(int i=1; i<pos-1; i=i+1)
    {
      tmp = tmp->next;
    }
    Node* tmpn = tmp->next;
    tmp->next = newNode;
    newNode->next = tmpn;
  }
}

void deleteatN(Node** head, int pos)
{
  if(pos==1)
  {
    Node* tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }
  else
  {
    Node* tmp = *head;
    for(int i=1; i<pos-1; i=i+1)
    {
      tmp = tmp->next;
    }
    Node* tmpd = tmp->next;
    tmp->next = tmpd->next;
    free(tmpd);
  }
}

void revList(Node** head)
{
  Node* prev = NULL;
  Node* curr = *head;
  Node* next;
  while(curr!=NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

void recRev(Node** head, Node* p)
{
  if(p->next==NULL)
  {
    *head = p;
    return;
  }
  else
  {
    recRev(head, p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
  }
}

void delKey(Node** head, int key)
{
  if((*head)->data==key)
  {
    Node* tmpd = *head;
    *head = (*head)->next;
    free(tmpd);
  }
  else
  {
    Node* tmp = *head;
    while(tmp->next->data!=key)
    {
      tmp = tmp->next;
    }
    Node* tmpd = tmp->next;
    tmp->next = tmpd->next;
    free(tmpd);
  }
}

void printFwd(Node* head)
{
  cout<<"Forward print"<<endl;
  Node* tmp = head;
  while(tmp!=NULL)
  {
    cout<<tmp->data<<endl;
    tmp=tmp->next;
  }
}

void printRevRec(Node* head)
{
  if(head==NULL)
    return;
  else printRevRec(head->next);
  cout<<head->data<<endl;
}


int main()
{
  Node* head = NULL;
  insertAtTail(&head,1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);
  insertatN(&head, 4,2);
  printFwd(head);
  deleteatN(&head, 4);
  printFwd(head);
  recRev(&head, head);
  cout<<"Print reverse recursion"<<endl;
  printRevRec(head);
  delKey(&head, 2);
  cout<<"O/p after deleting"<<endl;
  printFwd(head);
  return 0;
}
