#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

Node* newTreeNode(int data)
{
  Node* newNode = new Node(data);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void InOrderTraversal(Node* root, int n)
{
  static int count = 0;
  if(root == NULL)
    return;

  if(count<n)
  {
    InOrderTraversal(root->left, n);
    count++;

    if(count == n)
      cout<<root->data<<endl;

    InOrderTraversal(root->right, n);
  }
}


int main()
{
  Node* root = newTreeNode(1);
  root->left = newTreeNode(2);
  root->right = newTreeNode(3);
  root->left->left = newTreeNode(4);
  root->left->right = newTreeNode(5);

  InOrderTraversal(root, 1);

  return 0;
}
