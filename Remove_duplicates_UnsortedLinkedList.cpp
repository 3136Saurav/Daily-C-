#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void removeDuplicatesUnordered(Node* head)
{
  map<int, bool> seen;
  Node* current = head;
  Node* prev = NULL;
  while(current!=NULL)
  {
    if(seen.find(current->data)==seen.end())
    {
      seen.insert(pair<int,bool>(current->data, true));
      prev = current;
    }
    else
    {
      prev->next = current->next;
      delete(current);
    }

    current = prev->next;
  }
}

void push(Node** head, int newData)
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
  {
    temp = temp->next;
  }
  temp->next = newNode;
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
  push(&head, 12);
  push(&head, 5);
  push(&head, 3);
  push(&head, 5);
  push(&head, 5);
  push(&head, 9);
  push(&head, 12);
  push(&head, 3);
  push(&head, 3);
  push(&head, 5);
  printLinkedList(head);
  removeDuplicatesUnordered(head);
  printLinkedList(head);
  return 0;
}
