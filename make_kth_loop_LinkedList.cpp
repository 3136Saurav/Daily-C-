#include<iostream>
using namespace std;

struct Node
{
  Node* next;
  int data;
};

void makeLoop(Node* head, int k)
{
  Node* temp = head;
  int count = 1;
  while(count<k)
  {
    count++;
    temp = temp->next;
  }
  Node* jointPoint = temp;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }

  temp->next = jointPoint;
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
  push(&head, 2);
  push(&head, 5);
  push(&head, 7);
  push(&head, 0);
  push(&head, 23);
  printLinkedList(head);
  makeLoop(head, 2);
  return 0;
}
