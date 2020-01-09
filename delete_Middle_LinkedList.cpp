#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void deleteMiddleLinkedList(Node** head)
{
  Node* slowPtr = *head;
  Node* fastPtr = *head;
  Node* prevPtr = NULL;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    prevPtr = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  cout<<slowPtr->data<<" * "<<endl;
  prevPtr->next = slowPtr->next;
  delete slowPtr;
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
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
  {
    return;
  }
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 2);
  pushAtTail(&head, 4);
  pushAtHead(&head, 5);
  pushAtHead(&head, 9);
  pushAfter(head->next->next, 3);
  pushAtTail(&head, 8);
  pushAtHead(&head, 1);
  printLinkedList(head);
  deleteMiddleLinkedList(&head);

  return 0;
}
