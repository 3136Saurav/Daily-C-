///Incomplete????

#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

struct Node* newNode(int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  return node;
}

void push(Node** head, int newData)
{
  Node* new_Node = newNode(newData);
  new_Node->next = *head;
  *head = new_Node;
}

void printLinkedList(Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<"X"<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 23);
  push(&head, 28);
  push(&head, 28);
  push(&head, 35);
  push(&head, 49);
  push(&head, 49);
  push(&head, 53);

  printLinkedList(head);
  return 0;
}
