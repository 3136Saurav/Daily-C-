/*#include<iostream>
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
}*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void pushAfter(Node* prev, int newData){
  if(prev == NULL)
    return;
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;
}

void pushAtHead(Node** head, int newData){
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData){
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = NULL;
  if(*head == NULL){
    *head = newNode;
    return;
  }
  Node* curr = *head;
  while(curr->next)
      curr = curr->next;
  curr->next = newNode;
}

void insertNthfromEnd(Node** head, int newData, int n){
  Node* start = *head;
  int count = 0;
  while(start && count<n){
    count++;
    start = start->next;
  }
  Node* NthfromEnd = *head;
  while (start) {
    NthfromEnd = NthfromEnd->next;
    start = start->next;
  }
  pushAfter(NthfromEnd, newData);
}

void printLinkedList(Node* head){
  Node* curr = head;
  while (curr) {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int main(){
  Node* head = NULL;
  pushAtHead(&head, 2);
  pushAtHead(&head, 1);
  pushAfter(head->next, 4);
  pushAtTail(&head, 6);
  pushAtTail(&head, 8);
  printLinkedList(head);
  insertNthfromEnd(&head, 11, 1);
  printLinkedList(head);
  return 0;
}
