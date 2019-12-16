#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void pairwiseSwap(Node* head)
{
  Node* temp = head;
  while(temp!=NULL && temp->next!=NULL)
  {
    swap(&(temp->data), &(temp->next->data));
    temp = temp->next->next;
  }
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
  pushAtTail(&head, 1);
  pushAtHead(&head, 2);
  pushAtTail(&head, 3);
  pushAtHead(&head, 4);
  pushAtTail(&head, 5);
  pushAtHead(&head, 8);
  printLinkedList(head);
  //cout<<"\n"<<lengthOfLinkedList(head)<<endl;
  pairwiseSwap(head);
  printLinkedList(head);
}
