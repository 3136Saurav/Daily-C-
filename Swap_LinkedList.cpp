#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void swapNodes(Node** head, int x, int y)
{
  if(x == y)
    return;

  Node* currX = *head;
  Node* prevX = NULL;
  while(currX && currX->data!=x)
  {
    prevX = currX;
    currX = currX->next;
  }

  Node* currY = *head;
  Node* prevY = NULL;
  while(currY && currY->data!=y)
  {
    prevY = currY;
    currY = currY->next;
  }

  if(currX==NULL || currY==NULL)
  {
    return;
  }

  if(prevX!=NULL)
  {
    prevX->next = currY;
  }
  else
  {
    *head = currY;
  }

  if(prevY!=NULL)
  {
    prevY->next = currX;
  }
  else
  {
    *head = currX;
  }

  Node* temp = currX->next;
  currX->next = currY->next;
  currY->next = temp;

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
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void printLinkedList(Node* node)
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
  pushAtHead(&head, 1);
  pushAtHead(&head, 2);
  pushAtHead(&head, 3);
  pushAtTail(&head, 5);
  pushAtHead(&head, 6);
  pushAtTail(&head, 11);
  pushAtTail(&head, 8);
  pushAtTail(&head, 12);
  printLinkedList(head);
  swapNodes(&head, 6, 12);
  printLinkedList(head);
  return 0;
}
