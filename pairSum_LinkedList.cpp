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

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
    return;
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

int countSumPairs(Node* head1, Node* head2, int sum)
{
  unordered_set<int> complementSet;
  int numberOfPairs = 0;
  while(head1)
  {
    complementSet.insert(head1->data);
    head1 = head1->next;
  }
  while(head2)
  {
    if(complementSet.find(sum-head2->data)!=complementSet.end())
    {
      numberOfPairs++;
    }
    head2 = head2->next;
  }
  return numberOfPairs;
}

int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;

  pushAtTail(&head1, 4);
  pushAtTail(&head1, 3);
  pushAtTail(&head1, 5);
  pushAtTail(&head1, 7);
  pushAtTail(&head1, 11);
  pushAtTail(&head1, 2);
  pushAtTail(&head1, 1);

  pushAtTail(&head2, 2);
  //pushAtTail(&head2, 3);
  //pushAtTail(&head2, 4);
  //pushAtTail(&head2, 5);
  //pushAtTail(&head2, 6);
  pushAtTail(&head2, 8);
  pushAtTail(&head2, 12);

  printLinkedList(head1);
  printLinkedList(head2);
  cout<<countSumPairs(head1, head2, 7)<<endl;
  return 0;
}
