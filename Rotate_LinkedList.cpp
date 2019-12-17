#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void rotateLinkedList(Node** head, int k)
{
  if(k == 0)
    return;

  Node* current = *head;
  int count = 1;
  while(current && count<k)
  {
    current = current->next;
    count++;
  }

  if(current == NULL)
    return;

  Node* kthNode = current;

  while(current->next!=NULL)
  {
    current = current->next;
  }
  current->next = *head;
  *head = kthNode->next;
  kthNode->next = NULL;
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

int main()
{
  Node* head = NULL;
  pushAtTail(&head, 10);
  pushAtTail(&head, 20);
  pushAtTail(&head, 30);
  pushAtTail(&head, 40);
  pushAtTail(&head, 50);
  pushAtTail(&head, 60);
  printLinkedList(head);
  rotateLinkedList(&head, 4);
  printLinkedList(head);
  return 0;
}
