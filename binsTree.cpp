#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct BstNode {
  int data;
  BstNode* left;
  BstNode* right;
};

BstNode* GetNewNode(int data)
{
  BstNode* newNode = new BstNode;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
  if(root==NULL)
  {
    root = GetNewNode(data);
  }
  else if(data>=root->data)
  {
    root->right = Insert(root->right, data);
  }
  else
  {
    root->left = Insert(root->left, data);
  }
  return root;
}

bool Search(BstNode* root, int data)
{
  if(root==NULL) return false;
  else if(root->data==data) return true;
  else if(data >= root->data) return Search(root->right, data);
  else return Search(root->left, data);
}

int main()
{
  BstNode* root = GetNewNode(25);
  root = Insert(root, 15);
  root = Insert(root, 35);
  root = Insert(root, 30);
  root = Insert(root, 100);
  bool tof = Search(root, 100);
  bool tof2 = Search(root, 102);
  cout<<tof<<"  "<<tof2<<endl;
}
