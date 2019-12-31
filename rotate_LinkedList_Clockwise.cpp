#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

int lengthOfLinkedList(Node* node)
{
  int length=0;
  while(node!=NULL)
  {
    length++;
    node = node->next;
  }
  return length;
}

void rotateClockwise(Node** head, int k)
{
  Node* kthNodeComplement = NULL;
  Node* current = *head;
  int kk = lengthOfLinkedList(*head) - k - 1;
  int count = 0;

  while(count<kk && current)
  {
    current = current->next;
    ++count;
  }
  kthNodeComplement = current;
  while(current->next!=NULL)
  {
    current = current->next;
  }
  current->next = *head;
  *head = kthNodeComplement->next;
  kthNodeComplement->next = NULL;
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
    temp = temp->next;
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  if(prev==NULL)
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
  pushAtHead(&head, 3);
  pushAtTail(&head, 7);
  pushAfter(head->next, 4);
  pushAtHead(&head, 5);
  pushAfter(head->next->next, 8);
  printLinkedList(head);
  rotateClockwise(&head, 1);
  printLinkedList(head);
  return 0;
}
