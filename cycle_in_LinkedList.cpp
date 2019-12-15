#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void detectLoop(Node* head)
{
  Node* slowPtr = head;
  Node* fastPtr = head;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if(slowPtr == fastPtr)
    {
      cout<<"LOOP Exists"<<endl;
      return;
    }
  }
  cout<<"No LOOP found!!"<<endl;
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
  while (node!=NULL) {
    cout<<node->data<<" ";
    node = node->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
  push(&head, 9);
  push(&head, 8);
  push(&head, 7);
  
  printLinkedList(head);
  head->next->next = head->next->next->next->next->next;
  detectLoop(head);
  return 0;
}
