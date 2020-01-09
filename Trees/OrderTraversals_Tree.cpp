#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* right;
  Node* left;
  Node(int data)
  {
    this->data = data;
    right = NULL;
    left = NULL;
  }
};

void PreOrderTraversal(Node* node)
{
  if(node == NULL)
    return;

  cout<<node->data<<" ";

  PreOrderTraversal(node->left);

  PreOrderTraversal(node->right);
}

void InOrderTraversal(Node* node)
{
  if(node == NULL)
    return;

  InOrderTraversal(node->left);

  cout<<node->data<<" ";

  InOrderTraversal(node->right);
}

void PostOrderTraversal(Node* node)
{
  if(node == NULL)
    return;

  PostOrderTraversal(node->left);

  PostOrderTraversal(node->right);

  cout<<node->data<<" ";
}

int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout<<"\nINORDER TRAVERSAL: (Left, Root, Right)"<<endl;
  InOrderTraversal(root);
  cout<<"\nPREORDER TRAVERSAL: (Root, Left, Right)"<<endl;
  PreOrderTraversal(root);
  cout<<"\nPOSTORDER TRAVERSAL: (Left, Right, Root)"<<endl;
  PostOrderTraversal(root);

  return 0;
}
