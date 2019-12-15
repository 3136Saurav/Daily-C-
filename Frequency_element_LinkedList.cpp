#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

/*
int frequencyOfElement(Node* head, int key)
{
  int count = 0;
  Node* current = head;
  while(current!=NULL)
  {
    if(current->data == key)
      count++;
    current = current->next;
  }
  return count;
}
*/

int frequency = 0;

int frequencyOfElementRecursively(Node* head, int key)
{
  if(head == NULL)
    return frequency;
  if(head->data == key)
    frequency++;
  return frequencyOfElementRecursively(head->next, key);
}

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
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
  push(&head, 3);
  push(&head, 7);
  push(&head, 2);
  push(&head, 4);
  push(&head, 2);
  push(&head, 4);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  printLinkedList(head);
  cout<<frequencyOfElementRecursively(head, 2)<<endl;
  return 0;
}
