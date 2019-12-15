#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void push(Node** head, int new_data)
{
  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->next = NULL;
  new_node->next = *head;
  *head = new_node;
}

void deleteKey(Node** head, int key)
{
  Node* temp = *head, *prev;
  if(temp!=NULL && temp->data==key)
  {
    *head = temp->next;
    free(temp);
    return;
  }
  while(temp!=NULL && temp->data!=key)
  {
    prev = temp;
    temp = temp->next;
  }
  if(temp == NULL)
    return;

  prev->next = temp->next;
  free(temp);
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
  Node* head = NULL;
  push(&head,5);
  push(&head,7);
  push(&head,9);
  printList(head);
  deleteKey(&head,7);
  printList(head);
  deleteKey(&head,5);
  printList(head);
  return 0;
}
