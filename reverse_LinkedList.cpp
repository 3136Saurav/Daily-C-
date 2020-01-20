#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void printLinkedList(Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<"X"<<endl;
}
/*
void reverseLinkedList(Node** head)
{
  Node* current = *head;
  Node* prev = NULL;
  Node* nextPtr = NULL;
  while(current!=NULL)
  {
    nextPtr = current->next;
    current->next = prev;
    prev = current;
    current = nextPtr;
  }
  *head = prev;
}*/

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
    temp = temp->next;
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  if(prev == NULL)
  {
    return;
  }
  newNode->next = prev->next;
  prev->next = newNode;
}

void reverseLinkedList(Node** head){
  Node* curr = *head;
  Node* prev = NULL;
  Node* next = NULL;
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

int main()
{
  Node* head = NULL;
  pushAtTail(&head, 3);
  pushAtHead(&head, 2);
  pushAtTail(&head, 9);
  pushAtHead(&head, 4);
  pushAfter(head->next->next, 5);
  pushAtTail(&head, 8);
  printLinkedList(head);
  reverseLinkedList(&head);
  printLinkedList(head);
}
