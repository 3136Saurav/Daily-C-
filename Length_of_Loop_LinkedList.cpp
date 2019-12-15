#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  Node* temp = *head;
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }

  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}

int countNodes(Node* n)
{
  int res = 1;
  Node* temp = n;
  while (temp->next!=n) {
    res++;
    temp = temp->next;
  }
  return res;
}

int detectLengthLoop(Node* head)
{
  Node* fastPtr = head;
  Node* slowPtr = head;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if(slowPtr == fastPtr)
      return countNodes(slowPtr);
  }
  return 0;
}

void makeLoop(Node** head, int k)
{
  int count = 1;
  Node* temp = *head;
  while(count<k)
  {
    count++;
    temp = temp->next;
  }
  Node* jointNode = temp;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = jointNode;
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
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
  push(&head, 7);
  push(&head, 8);
  printLinkedList(head);
  makeLoop(&head, 3);
  cout<<detectLengthLoop(head)<<endl;
  return 0;
}
