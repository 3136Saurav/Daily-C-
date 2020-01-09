/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

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
  Node* curr = *head;
  while(curr->next)
    curr = curr->next;
  curr->next = newNode;
}

void printLinkedList(Node* head)
{
  Node* curr = head;
  while(curr)
  {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int lengthOfLinkedList(Node* head)
{
  int length = 0;
  Node* curr = head;
  while(curr)
  {
    length++;
    curr = curr->next;
  }
  return length;
}

void add2LinkedLists(Node* head1, Node* head2)
{
  Node* a = head1;
  Node* b = head2;
  Node* res = NULL;
  int sum = 0;
  int carry = 0;

  while(a!=NULL || b!=NULL)
  {
    //sum = sum + (a?(a->data):0) + (b?(b->data):0) + carry;
    if(a)
      sum += a->data;
    else
      sum += 0;

    if(b)
      sum += b->data;
    else
      sum += 0;

    sum = sum + carry;

    if(sum>9)
      carry = 1;

    else
      carry = 0;

    sum = sum%10;
    cout<<"Sum: "<<sum<<endl;

    pushAtTail(&res, sum);

    if(a)
      a = a->next;

    if(b)
      b = b->next;

    sum = 0;
  }

  printLinkedList(res);

}

int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;

  pushAtTail(&head1, 2);
  pushAtTail(&head1, 4);
  pushAtTail(&head1, 3);
  printLinkedList(head1);

  pushAtTail(&head2, 5);
  pushAtTail(&head2, 6);
  pushAtTail(&head2, 4);
  printLinkedList(head2);


  add2LinkedLists(head1, head2);


  return 0;
}
