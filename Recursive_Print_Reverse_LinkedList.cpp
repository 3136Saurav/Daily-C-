#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void printReverseRecursively(Node* head)
{
  if(head == NULL)
  {
    return;
  }
  printReverseRecursively(head->next);
  cout<<head->data<<" -> ";
}

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void printLinkedListt(Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<"X"<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 8);
  push(&head, 7);
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  printLinkedListt(head);
  printReverseRecursively(head);
  return 0;
}
