#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

int getNthFromEnd(Node* head, int n)
{
  Node* mainPtr = head;
  Node* refPtr = head;
  int c = 0;
  while(c != n)
  {
    if(refPtr==NULL)
    {
      return -1;
    }
    refPtr = refPtr->next;
    c++;
  }

  while(refPtr!=NULL)
  {
    mainPtr = mainPtr->next;
    refPtr = refPtr->next;
  }
  return mainPtr->data;
}

void push(Node** head, int data)
{
  Node* newNode = new Node();
  newNode->data = data;
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
   push(&head, 15);
   push(&head, 12);
   push(&head, 9);
   printLinkedList(head);
   cout<<getNthFromEnd(head, 5)<<endl;
}
