#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void moveLast(Node** head)
{
  Node* curr = *head;
  Node* prev = NULL;
  while(curr->next!=NULL)
  {
    prev = curr;
    curr = curr->next;
  }

  prev->next = NULL;
  curr->next = *head;
  *head = curr;

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
  Node* temp = *head;
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  while(temp->next!=NULL)
    temp = temp->next;
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  if(prev == NULL)
  {
    return;
  }
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
  pushAtHead(&head, 1);
  pushAtTail(&head, 3);
  pushAtHead(&head, 4);
  pushAfter(head->next, 5);
  pushAtHead(&head, 2);
  pushAtTail(&head, 6);
  pushAfter(head->next->next->next, 7);
  printLinkedList(head);
  moveLast(&head);
  printLinkedList(head);
  return 0;
}
