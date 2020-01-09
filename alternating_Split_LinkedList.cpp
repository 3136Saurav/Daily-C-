//Incomplete????
#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

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
  Node* curr = *head;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  while(curr->next!=NULL)
    curr = curr->next;
  curr->next = newNode;
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

void alternateLinkedList(Node* head)
{
  Node* aHead = NULL;
  Node* bHead = NULL;
  Node* curr = head;
  Node* altCurr = head->next;

  //cout<<curr->data<<" /// "<<altCurr->data<<endl;

  while(curr!=NULL)
  {
    cout<< curr->data << " / ";
    pushAtTail(&aHead, curr->data);
    curr = curr->next->next;
  }


  cout<<endl;

  while (altCurr)
  {
    cout<<altCurr->data<<" | ";
    pushAtTail(&bHead, altCurr->data);
    altCurr = altCurr->next->next;
  }
  cout<<endl;
  printLinkedList(aHead);
  printLinkedList(bHead);
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 3);
  pushAtTail(&head, 5);
  pushAtHead(&head, 7);
  pushAtHead(&head, 8);
  pushAtTail(&head, 9);
  pushAtHead(&head, 6);
  pushAtTail(&head, 1);
  printLinkedList(head);
  alternateLinkedList(head);
  return 0;
}
