#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

int middleOfLinkedList(Node* head)
{
  Node* fastPtr = head;
  Node* slowPtr = head;
  while(fastPtr!=NULL && fastPtr->next!=NULL)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  return slowPtr->data;
}

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
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
  push(&head, 4);
  push(&head, 7);
  push(&head, 22);
  push(&head, 43);
  push(&head, 62);
  push(&head, 75);
  push(&head, 98);
  printLinkedList(head);
  cout<<middleOfLinkedList(head)<<endl;
  return 0;
}
