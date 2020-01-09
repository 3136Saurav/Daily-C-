#include<iostream>
using namespace std;

struct Node {
  char data;
  Node* next;
};

int compare2Strings(Node* headA, Node* headB)
{
  while(headA && headB && headA->data == headB->data)
  {
    headA = headA->next;
    headB = headB->next;
  }

  if(headA && headB)
    return (headA->data > headB->data)? 1: -1;

  if(headA && !headB) return 1;
  if(!headA && headB) return -1;

  return 0;
}

void pushAtHead(Node** head, char c)
{
  Node* newNode = new Node();
  newNode->data = c;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, char c) {
  Node* newNode = new Node();
  newNode->data = c;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  Node* temp = *head;
  while(temp->next)
    temp = temp->next;

  temp->next = newNode;
}

void printLinkedList(Node* head)
{
  Node* curr = head;
  while(curr)
  {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int main()
{
  Node* headA = NULL;
  Node* headB = NULL;

  pushAtTail(&headA, 'g');
  pushAtTail(&headA, 'e');
  pushAtTail(&headA, 'e');
  pushAtTail(&headA, 'k');

  pushAtTail(&headB, 'g');
  pushAtTail(&headB, 'e');
  pushAtTail(&headB, 'e');
  pushAtTail(&headB, 'k');
  pushAtTail(&headB, 's');

  printLinkedList(headA);
  printLinkedList(headB);

  cout<<compare2Strings(headA, headB)<<endl;
  return 0;
}
