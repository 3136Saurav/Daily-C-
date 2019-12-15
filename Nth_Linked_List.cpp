#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

int getNthNode(Node* head, int index)
{
  Node* current = head;
  int count = 0;
  while(current!=NULL)
  {
    count = count+1;
    if(count == index)
      return current->data;
    current = current->next;
  }
  assert(0);
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
  push(&head, 3);
  push(&head, 7);
  push(&head, 11);
  push(&head, 13);
  printLinkedList(head);
  cout<<getNthNode(head, 4)<<endl;
  return 0;
}
