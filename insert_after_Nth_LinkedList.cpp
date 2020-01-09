#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;
    Node(int data)
    {
      this->data = data;
    }
};

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
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void pushAtHead(Node** head, int newData)
{
  Node* newNode = new Node(newData);
  newNode->next = *head;
  *head = newNode;
}

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
    return;
  Node* newNode = new Node(newData);
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

void insertNthfromEnd(Node** head, int newData, int k)
{
  Node* temp = *head;
  int count = 0;
  while(temp->next && count<k)
  {
    count++;
    temp = temp->next;
  }
  Node* NthfromEnd = *head;
  Node* curr = temp;
  while(curr!=NULL)
  {
    NthfromEnd = NthfromEnd->next;
    curr = curr->next;
  }
  cout<<temp->data<<endl;
  cout<<NthfromEnd->data<<endl;

  //Node* newNode = new Node(newData);
  pushAfter(NthfromEnd, newData);

}

int main()
{
  Node* head = NULL;

  pushAtHead(&head, 3);
  pushAtTail(&head, 5);
  pushAtHead(&head, 7);
  pushAfter(head->next, 8);
  pushAtHead(&head, 9);
  pushAfter(head->next->next, 2);
  printLinkedList(head);
  insertNthfromEnd(&head, 11, 2);
  printLinkedList(head);

  return 0;
}
