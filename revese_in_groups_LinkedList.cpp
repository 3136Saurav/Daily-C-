#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

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
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  Node* curr = *head;
  while(curr->next!=NULL)
  {
    curr = curr->next;
  }
  curr->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
    return;
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;
}

void printLinkedList(Node* head)
{
  Node* curr = head;
  while (curr) {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

Node* reverseInGroups(Node* head, int k)
{
  int count = 0;
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;
  while(curr!=NULL && count<k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if(next!=NULL)
    head->next = reverseInGroups(next, k);

  return prev;
}

int main()
{
  Node* head = NULL;
  pushAtTail(&head, 1);
  pushAtTail(&head, 2);
  pushAtTail(&head, 3);
  pushAtTail(&head, 4);
  pushAtTail(&head, 5);
  pushAtTail(&head, 6);
  pushAtTail(&head, 7);
  pushAtTail(&head, 8);

  printLinkedList(head);
  head = reverseInGroups(head, 3);
  printLinkedList(head);
  return 0;
}
