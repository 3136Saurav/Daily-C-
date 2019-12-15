#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node* next;
};

void pushAtHead(Node** head_ref, int new_data)
{
  Node* new_node = new Node();
  new_node->next = NULL;
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
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

void insertAfter(Node* prev_node, int new_data)
{
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = NULL;
  if(prev_node == NULL)
  {
    cout<<"Cannot insert after NULL";
    return;
  }
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void appendAtLast(Node** head_ref, int new_data)
{
  Node* last = *head_ref;
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = NULL;
  if(*head_ref == NULL)
  {
    *head_ref = new_node;
  }
  while (last->next!=NULL) {
    last = last->next;
  }
  last->next = new_node;
  return;
}

void experimentTraversal(Node* node)
{
  Node* last = node;
  cout<<last->data<<" * "<<endl;
  while(last->next!=NULL)
  {
    cout<<" "<<last->data<<" ";
    last = last->next;
  }
  return;
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 4);
  pushAtHead(&head, 8);
  pushAtHead(&head, 12);
  insertAfter(head->next, 16);
  appendAtLast(&head, 20);
  appendAtLast(&head, 24);
  printList(head);
  experimentTraversal(head);
  return 0;
}
