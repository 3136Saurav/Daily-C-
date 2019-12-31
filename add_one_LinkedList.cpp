#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* reverseLinkedList(Node** head)
{
  Node* prev = NULL;
  Node* current = *head;
  Node* upNext = NULL;
  while(current)
  {
    upNext = current->next;
    current->next = prev;
    prev = current;
    current = upNext;
  }
  *head = prev;
  return prev;
}

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData)
{
  Node* temp = *head;
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  while (temp->next!=NULL)
    temp = temp->next;
  temp->next = newNode;
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

void addOne(Node** head)
{
  Node* revHead = reverseLinkedList(head);
  //cout<<revHead->data<<" ** "<<endl;
  revHead->data = revHead->data + 1;
  int carry = 0;
  Node* temp = NULL;
  if(revHead->data>9)
  {
    revHead->data = (revHead->data) % 10;
    carry = 1;
  }
  temp = revHead->next;
  while (temp) {
    temp->data = temp->data + carry;
    if(temp->data>9)
    {
      carry = 1;
      temp->data = (temp->data) % 10;
    }
    else
    {
      carry = 0;
    }
    temp = temp->next;
  }

  if(carry)
  {
    pushAtTail(&revHead, carry);
  }
  Node* resHead = reverseLinkedList(&revHead);
  printLinkedList(resHead);
}

int main()
{
  Node* head = NULL;
  push(&head, 9);
  push(&head, 9);
  push(&head, 9);
  printLinkedList(head);
  //reverseLinkedList(&head);
  addOne(&head);
  //addOne(&head);
  return 0;
}
