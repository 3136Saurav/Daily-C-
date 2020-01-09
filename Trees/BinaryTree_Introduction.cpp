#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left = NULL;
  Node* right = NULL;
};

Node* newTreeNode(int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

int main()
{
  Node* root = newTreeNode(1);
  root->left = newTreeNode(2);
  root->right = newTreeNode(3);
  root->left->left = newTreeNode(4);
  root->left->right = newTreeNode(5);
  return 0;
}
