#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
    next = NULL;
  }
};

struct LinkedList
{
  Node* head;
  LinkedList()
  {
    head = NULL;
  }

  Node* reverseRecursively(Node* node)
  {
    if(node==NULL)
      return NULL;
    if(node->next==NULL)
    {
      head = node;
      return node;
    }
    Node* node1 = reverseRecursively(node->next);
    node1->next = node;
    node->next = NULL;
    return node;
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

  void push(int data)
  {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
  }
};

int main()
{
  LinkedList l1;
  l1.push(10);
  l1.push(20);
  l1.push(30);
  l1.printLinkedList(l1.head);
  l1.reverseRecursively(l1.head);
  l1.printLinkedList(l1.head);
}
