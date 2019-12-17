#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void setMiddleHead(Node** head)
{
  if(*head == NULL)
    return;
  Node* slowPtr = *head;
  Node* fastPtr = *head;
  Node* prevPtr = NULL;
  while(fastPtr && fastPtr->next!=NULL)
  {
    prevPtr = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  prevPtr->next = slowPtr->next;
  slowPtr->next = *head;
  *head = slowPtr;
}

void pushAtHead(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  Node* temp = *head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  if(prev == NULL)
    return;
  newNode->next = prev->next;
  prev->next = newNode;
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
  pushAtHead(&head, 3);
  //pushAfter(head, 2);
  pushAtHead(&head, 4);
  pushAtTail(&head, 9);
  pushAfter(head->next->next, 7);
  pushAtHead(&head, 8);
  printLinkedList(head);
  setMiddleHead(&head);
  printLinkedList(head);
  return 0;
}
