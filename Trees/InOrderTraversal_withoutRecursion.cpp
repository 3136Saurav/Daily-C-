#include<bits/stdc++.h>
#include<iostream>
#include <typeinfo>
using namespace std;

struct Node {
  int data;
  Node* right;
  Node* left;
  Node(int data)
  {
    this->data = data;
    right = left = NULL;
  }
};

Node* getNode(int data)
{
  Node* newNode = new Node(data);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void InOrderTraversalWithoutRecursion(Node* root)
{
  Node* curr = root;
  stack<Node*> InOrderStack;

  while(curr!=NULL || InOrderStack.empty()==false)
  {
    while(curr!=NULL)
    {
      InOrderStack.push(curr);
      curr = curr->left;
    }

    curr = InOrderStack.top();
    InOrderStack.pop();

    cout<<curr->data<<" ";
    curr = curr->right;
  }
}

int main()
{
  Node* root = getNode(1);
  root->left = getNode(2);
  root->right = getNode(3);
  root->left->left = getNode(4);
  root->left->right = getNode(5);
  InOrderTraversalWithoutRecursion(root);
  cout <<"\n"<< typeid(root).name() << endl;
  return 0;
}
