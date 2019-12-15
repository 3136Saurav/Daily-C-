#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;  
};

void deleteAllNodes(Node** head)
{
  Node* current = *head; Node* next;
  while(current!=NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *head= NULL;
}

void push(Node** head, int key)
{
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void printList(Node* node)
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
  Node* head = new Node();
  push(&head, 6);
  push(&head, 9);
  push(&head, 13);
  printList(head);
  return 0;
}
