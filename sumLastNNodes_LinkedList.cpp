#include <iostream>
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

void printLinkedList(Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<"X"<<endl;
}

int sumFromEnd(Node* head, int n)
{
  Node* NthNode = head;
  int count=1;
  int total = 0;
  while(count<=n && NthNode)
  {
    total = total + NthNode->data;
    NthNode = NthNode->next;
    count++;
  }
  Node* NthFromLast = head;
  int sum = 0;

  while(NthNode!=NULL)
  {
    sum = sum + NthFromLast->data;
    total = total + NthNode->data;
    NthFromLast = NthFromLast->next;
    NthNode = NthNode->next;
  }
  cout<<total<<" | "<<sum<<endl;
  return total - sum;
}


int main()
{
  Node* head = NULL;
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
  push(&head, 7);
  push(&head, 8);
  push(&head, 9);
  push(&head, 10);
  push(&head, 11);
  printLinkedList(head);
  cout<<sumFromEnd(head, 3)<<endl;
  return 0;
}
