#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node
{
public:
  string data;
  Node* next;
};

bool isPalindrome(Node** head)
{
  Node* temp = *head;
  stack<string> s;
  while(temp!=NULL)
  {
    s.push(temp->data);
    temp = temp->next;
  }
  string t;
  while(*head!=NULL)
  {
    t = s.top();
    s.pop();
    if(t != (*head)->data)
      return false;
    *head = (*head)->next;
  }
  return true;
}

void push(Node** head, string s)
{
  Node* newNode = new Node();
  Node* temp = *head;
  newNode->data = s;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
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
    cout<<node->data;
    node = node->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, "r");
  push(&head, "a");
  push(&head, "d");
  push(&head, "e");
  push(&head, "r");
  printLinkedList(head);
  cout<<isPalindrome(&head)<<endl;
  return 0;
}
