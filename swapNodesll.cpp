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

void mergenSort(Node* head1, Node* head2, Node** newhead)
{
  if(head1==NULL)
  {
    *newhead = head2;
    return;
  }
  if(head2==NULL)
  {
    *newhead = head1;
    return;
  }
  if(head1 && head2)
  {

    if((head1->data)<(head2->data))
    {
      *newhead = head1;
      head1=head1->next;
    }
    else
    {
      *newhead = head2;
      head2=head2->next;
    }
    //*newhead = tmphead;
    Node* tmphead = *newhead;
    while((head1!=NULL) && (head2!=NULL))
    {
      if((head1->data)<=(head2->data))
      {
        tmphead->next = head1;
        tmphead = head1;
        head1 = head1->next;
      }
      else
      {
        tmphead->next = head2;
        tmphead = head2;
        head2=head2->next;
      }
    }
    if(head1==NULL) tmphead->next = head2;
    if(head2==NULL) tmphead->next = head1;
  }
}



Node* mergeRec(Node* head1, Node* head2)
{
  Node* result = NULL;
  if(head1==NULL)
    return head2;
  if(head2==NULL)
    return head1;
  if(head1->data < head2->data)
  {
    result = head1;
    result->next = mergeRec(head1->next, head2);
  }
  else
  {
    result = head2;
    result->next = mergeRec(head1, head2->next);
  }
  return result;
}



void frontbacksplit(Node* ref, Node** first, Node** second)
{
  Node* slow = ref;
  Node* fast = ref->next;
  while(fast!=NULL)
  {
    fast=fast->next;
    if(fast!=NULL)
    {
      fast=fast->next;
      slow=slow->next;
    }
  }
  *first = ref;
  *second = slow->next;
  slow->next = NULL;
}

void MergeSort(Node** headRef)
{
  Node* head = *headRef;
  Node* a;
  Node* b;
  if((head==NULL)||(head->next==NULL))
    return;
  frontbacksplit(head, &a, &b);
  MergeSort(&a);
  MergeSort(&b);
  *headRef = mergeRec(a, b);
}

void swapNodes(Node** headRef, int x, int y)
{
  if(x==y)
    return;
  Node* prevX = NULL; Node* curX = *headRef;
  while(curX && curX->data!=x)
  {
    prevX = curX;
    curX = curX->next;
  }
  if(curX==NULL) return;
  Node* curY=*headRef; Node* prevY=NULL;
  while(curY && curY->data!=y)
  {
    prevY = curY;
    curY=curY->next;
  }
  if(curY==NULL) return;
  if(prevX!=NULL) prevX->next=curY;
  else *headRef = curY;
  if(prevY!=NULL) prevY->next=curX;
  else *headRef = curX;
  Node* temp = curX->next;
  curX->next = curY->next;
  curY->next = temp;
}

int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;
  Node* head3 = NULL;
  Node* head4 = NULL;
  insertAtTail(&head1,5);
  insertAtTail(&head1, 10);
  insertAtTail(&head1, 15);
  insertAtTail(&head2, 2);
  insertAtTail(&head2, 3);
  insertAtTail(&head2, 20);
  insertAtTail(&head2, 200);
  printFwd(head1);
  printFwd(head2);
  head4 = mergeRec(head1, head2);
  printFwd(head4);
  Node* a; Node* b;
  frontbacksplit(head4, &a, &b);
  printFwd(a);
  printFwd(b);
  cout<<"Making an unsorted list"<<endl;
  Node* nHead = NULL;
  insertAtTail(&nHead, 98);
  insertAtTail(&nHead, 198);
  insertAtTail(&nHead, 908);
  insertAtTail(&nHead, 8);
  insertAtTail(&nHead, 68);
  printFwd(nHead);
  MergeSort(&nHead);
  cout<<"Sorted List"<<endl;
  printFwd(nHead);
  swapNodes(&nHead, 68, 98);
  printFwd(nHead);

  return 0;
}
