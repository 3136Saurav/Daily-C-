#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

bool isSumSorted(Node* headA, Node* headB, Node* headC, int key)
{
  Node* currA = headA;

  while(currA)
  {
    Node* currB = headB;
    Node* currC = headC;

    while(currB && currC)
    {
      int val = currA->data + currB->data + currC->data;
      if(val == key)
      {
        cout<<" Triplet Found: "<<currA->data<<" "<<currB->data<<" "<<currC->data<<endl;
        return true;
      }

      if(val < key)
        currB = currB->next;
      else
        currC = currC->next;
    }
    currA = currA->next;
  }
  cout<<"No Such Triplet found"<<endl;
  return false;
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
  if(prev == NULL)
    return;
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;
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
  Node* headC = NULL;

  pushAtTail(&headA, 10);
  pushAtTail(&headA, 15);
  pushAtTail(&headA, 5);
  pushAtTail(&headA, 20);

  pushAtTail(&headB, 2);
  pushAtTail(&headB, 4);
  pushAtTail(&headB, 9);
  pushAtTail(&headB, 20);

  pushAtTail(&headC, 8);
  pushAtTail(&headC, 4);
  pushAtTail(&headC, 2);
  pushAtTail(&headC, 1);

  printLinkedList(headA);
  printLinkedList(headB);
  printLinkedList(headC);

  isSumSorted(headA, headB, headC, 25);
  return 0;
}
