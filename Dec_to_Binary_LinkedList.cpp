#include<iostream>
using namespace std;

struct Node
{
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
  Node* temp = *head;
  while(temp->next!=NULL)
    temp = temp->next;
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
    return;
  Node* newNode = new Node();
  newNode->data = newData;
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

void convertToBinary(int decNum)
{
  Node* binHead = NULL;
  int rem = 0;
  while(decNum!=0)
  {
    rem = decNum%2;
    pushAtHead(&binHead, rem);
    decNum = decNum/2;
  }
  printLinkedList(binHead);
}

int main()
{
  Node* head = NULL;
  int decNum = 0;
  cout<<"Enter Decimal Number: ";
  cin>>decNum;
  convertToBinary(decNum);
  return 0;
}
