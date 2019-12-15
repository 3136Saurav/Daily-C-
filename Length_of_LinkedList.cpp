#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

/*
int lengthOfLinkedList(Node* head)
{
  int count = 0;
  Node* ptr = head;
  while(ptr!=NULL)
  {
    count = count+1;
    ptr = ptr->next;
  }
  return count;
}
*/

int lengthOfLinkedListRecursively(Node* head)
{
  if(head == NULL)
    return 0;
  else
    return 1 + lengthOfLinkedListRecursively(head->next);
}

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  newNode->next = *head;
  *head = newNode;
}

void printLinkedList(Node* node)
{
  Node* ptr = node;
  while(ptr!=NULL)
  {
    cout<<ptr->data<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 4);
  push(&head, 8);
  push(&head, 12);
  push(&head, 21);
  push(&head, 29);
  push(&head, 35);
  push(&head, 41);
  push(&head, 57);
  printLinkedList(head);
  cout<<lengthOfLinkedListRecursively(head)<<endl;
  return 0;
}
