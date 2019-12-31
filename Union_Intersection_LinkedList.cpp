#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
  }
};

void pushAtHead(Node** head, int newData)
{
  Node* newNode = new Node(newData);
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData)
{
  Node* newNode = new Node(newData);
  newNode->next = NULL;
  if(*head==NULL)
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

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
  {
    return;
  }
  Node* newNode = new Node(newData);
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

int lengthOfLinkedList(Node* head)
{
  int count = 0;
  while(head!=NULL)
  {
    count++;
    head = head->next;
  }
  return count;
}

bool isPresent(Node* head, int key)
{
  Node* t = head;
  while(t!=NULL)
  {
    if(t->data == key)
      return true;
    t = t->next;
  }
  return false;
}

void unionOfLinkedList(Node* head1, Node* head2)
{
  Node* t1 = head1;
  Node* t2 = head2;
  Node* unionHead = NULL;
  while(t1)
  {
    pushAtTail(&unionHead, t1->data);
    t1 = t1->next;
  }
  while(t2)
  {
    if(!isPresent(head1, t2->data))
      pushAtTail(&unionHead, t2->data);
    t2 = t2->next;
  }
  cout<<"Union: "<<endl;
  printLinkedList(unionHead);
}

void intersectionOfLinkedList(Node* head1, Node* head2)
{
  Node* intersectionHead = NULL;
  Node* t1 = head1;
  Node* t2 = head2;
  while(t1)
  {
    if(isPresent(head2, t1->data))
      pushAtTail(&intersectionHead, t1->data);
    t1 = t1->next;
  }
  cout<<"Intersection: "<<endl;
  printLinkedList(intersectionHead);
}

int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;

  pushAtTail(&head1, 10);
  pushAtTail(&head1, 15);
  pushAtTail(&head1, 4);
  pushAtTail(&head1, 20);

  pushAtTail(&head2, 8);
  pushAtTail(&head2, 4);
  pushAtTail(&head2, 2);
  pushAtTail(&head2, 10);

  printLinkedList(head1);
  printLinkedList(head2);

  unionOfLinkedList(head1, head2);
  intersectionOfLinkedList(head1, head2);

}
