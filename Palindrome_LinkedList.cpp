/*#include<bits/stdc++.h>
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
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
  string data;
  Node* next;
};

bool isPalindrome(Node* head){
  Node* temp = head;
  stack<string> s;
  while(head){
    s.push(head->data);
    head = head->next;
  }
  while(temp){
    string t = s.top();
    s.pop();
    if(t != temp->data){
      return false;
    }
    temp = temp->next;
  }
  return true;
}

void pushAtHead(Node** head, string newData){
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, string newData){
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL){
    *head = newNode;
    return;
  }
  Node* temp = *head;
  while(temp->next)
    temp = temp->next;
  temp->next = newNode;
}

void pushAfter(Node* prev, string newData) {
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;
}

void printLinkedList(Node* head){
  Node* curr = head;
  while(curr){
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int main(){
  Node* head = NULL;
  pushAtTail(&head, "r");
  pushAtTail(&head, "a");
  pushAtTail(&head, "d");
  pushAtTail(&head, "a");
  pushAtTail(&head, "r");
  printLinkedList(head);
  cout<<isPalindrome(head)<<" * "<<endl;

  return 0;
}
