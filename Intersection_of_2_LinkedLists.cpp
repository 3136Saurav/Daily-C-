#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node(int d)
    {
      data = d;
    }
    Node* next;
};

void pushAtHead(Node** head, int newData)
{
  Node* newNode = new Node(newData);
  newNode->next = NULL;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData)
{
  Node* newNode = new Node(newData);
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
  Node* newNode = new Node(newData);
  newNode->next = NULL;
  if(prev == NULL)
  {
    return;
  }
  newNode->next = prev->next;
  prev->next = newNode;
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

void intersectionOf2Lists(Node* head1, Node* head2)
{
  Node* ptr1 = head1;
  Node* ptr2 = head2;
  Node* newHead = NULL;
  while(ptr1!=NULL && ptr2!=NULL)
  {
    if(ptr1->data == ptr2->data)
    {
      pushAtTail(&newHead, ptr1->data);
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    else if(ptr1->data > ptr2->data)
    {
      ptr2 = ptr2->next;
    }
    else
    {
      ptr1 = ptr1->next;
    }
  }
  printLinkedList(newHead);
}

int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;
  pushAtHead(&head1, 1);
  pushAtTail(&head1, 2);
  pushAfter(head1->next, 3);
  pushAtTail(&head1, 4);
  pushAtTail(&head1, 6);
  printLinkedList(head1);
  pushAtHead(&head2, 2);
  pushAtTail(&head2, 4);
  pushAfter(head2->next, 6);
  pushAtTail(&head2, 8);
  printLinkedList(head2);
  intersectionOf2Lists(head1, head2);
}
