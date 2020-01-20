/*#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

int getNthFromEnd(Node* head, int n)
{
  Node* mainPtr = head;
  Node* refPtr = head;
  int c = 0;
  while(c != n)
  {
    if(refPtr==NULL)
    {
      return -1;
    }
    refPtr = refPtr->next;
    c++;
  }

  while(refPtr!=NULL)
  {
    mainPtr = mainPtr->next;
    refPtr = refPtr->next;
  }
  return mainPtr->data;
}

void push(Node** head, int data)
{
  Node* newNode = new Node();
  newNode->data = data;
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
   push(&head, 15);
   push(&head, 12);
   push(&head, 19);
   push(&head, 29);
   push(&head, 39);
   push(&head, 49);
   push(&head, 59);
   push(&head, 69);
   push(&head, 79);
   push(&head, 89);
   printLinkedList(head);
   cout<<getNthFromEnd(head, 5)<<endl;
}*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

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
  Node* temp = *head;
  while(temp->next)
    temp = temp->next;
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData){
  if(prev == NULL)
    return;
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;
}

void printLinkedList(Node* head){
  Node* curr = head;
  while (curr) {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int getNthFromEnd(Node* head, int n){
  Node* refPtr = head;
  int count = 0;
  while(refPtr && count<n){
    count++;
    refPtr = refPtr->next;
  }
  Node* NthPtr = head;
  while(refPtr)
  {
    refPtr = refPtr->next;
    NthPtr = NthPtr->next;
  }
  return (NthPtr->data);
}

int main(){
  Node* head = NULL;
  pushAtHead(&head, 1);
  pushAtTail(&head, 3);
  pushAfter(head, 2);
  pushAtTail(&head, 4);
  pushAtTail(&head, 5);
  printLinkedList(head);
  cout<<"-> "<<getNthFromEnd(head, 4)<<endl;
  return 0;
}
