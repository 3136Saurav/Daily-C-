#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData)
{
  Node* newNode = new Node();
  Node* temp = *head;
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  while(temp->next!=NULL)
    temp = temp->next;
  temp->next = newNode;
}

void printLinkedList(Node* node)
{
  cout<<"X";
  while(node!=NULL)
  {
    cout<<" <- "<<node->data;
    node = node->next;
  }
  cout<<endl;
}

void add2LinkedLists(Node* first, Node* second)
{
  Node* res = NULL;
  Node* temp = NULL;
  int carry = 0;
  int sum = 0;
  while(first!=NULL || second!=NULL)
  {
    sum = sum + (first?(first->data):0) + (second?(second->data):0) + carry;
    if(sum>=10)
      carry = 1;
    else
      carry = 0;

    sum = sum%10;

    pushAtTail(&res, sum);

    if(first)
      first = first->next;
    if(second)
      second = second->next;
    sum = 0;
  }
  if(carry>0)
  {
    pushAtTail(&res, carry);
  }
  printLinkedList(res);
}

int main()
{
  Node* head1 = NULL;
  push(&head1, 9);
  push(&head1, 9);
  push(&head1, 9);
  printLinkedList(head1);
  Node* head2 = NULL;
  push(&head2, 1);
  //push(&head2, 4);
  //push(&head2, 8);
  printLinkedList(head2);
  add2LinkedLists(head1, head2);
  return 0;
}
