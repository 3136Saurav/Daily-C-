#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

bool searchRecursively(Node* head, int key)
{
  if (head == NULL)
    return false;
  if (head->data == key)
    return true;
  else
    return searchRecursively(head->next, key);
}
/*
bool searchIteratively(Node* head, int key)
{
  Node* ptr = head;
  while(ptr!=NULL)
  {
    if(ptr->data == key)
      return true;
    ptr = ptr->next;
  }
  return false;
}
*/

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->next = *head;
  newNode->data = newData;
  *head = newNode;
}

void printLinkedList(Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" ";
    node = node->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 5);
  push(&head, 10);
  push(&head, 15);
  printLinkedList(head);
  cout<<searchRecursively(head, 11)<<endl;
}
