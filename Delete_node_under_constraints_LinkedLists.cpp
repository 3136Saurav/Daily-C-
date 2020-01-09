#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void deleteUnderConstraints(Node* head, Node* n)
{
  if(head == n)
  {
    if(head == NULL)
    {
      cout<<"Cannot be deleted according to the conditions...."<<endl;
      return;
    }
    head->data = head->next->data;

    n = head->next;

    head->next = head->next->next;
    free(n);
    return;
  }

  Node* prev = head;
  while(prev->next!=NULL && prev->next!=n)
     prev = prev->next;

  if(prev->next == NULL)
  {
    cout<<"Cannot Delete: Node not found!!!";
    return;
  }

  prev->next = prev->next->next;
  free(n);
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
  Node* curr = *head;
  while(curr->next)
    curr = curr->next;
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
  while(curr)
  {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 4);
  pushAtTail(&head, 6);
  pushAtHead(&head, 2);
  pushAfter(head->next, 3);
  pushAtHead(&head, 1);
  printLinkedList(head);
  deleteUnderConstraints(head, head->next);
  printLinkedList(head);
  return 0;
}
