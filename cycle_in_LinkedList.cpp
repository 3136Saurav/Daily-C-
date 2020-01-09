/*#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void detectLoop(Node* head)
{
  Node* slowPtr = head;
  Node* fastPtr = head;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if(slowPtr == fastPtr)
    {
      cout<<"LOOP Exists"<<endl;
      return;
    }
  }
  cout<<"No LOOP found!!"<<endl;
}

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void printLinkedList(Node* node)
{
  while (node!=NULL) {
    cout<<node->data<<" ";
    node = node->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
  push(&head, 9);
  push(&head, 8);
  push(&head, 7);

  printLinkedList(head);
  head->next->next = head->next->next->next->next->next;
  detectLoop(head);
  return 0;
}
*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void detectLoop(Node* head){
  Node* fastPtr = head;
  Node* slowPtr = head;

  while(fastPtr && slowPtr && fastPtr->next){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if(slowPtr == fastPtr)
      {
        cout<<"LOOP Exists!!";
        return;
      }
  }
  cout<<"NO LOOP Exists";
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
  while(curr){
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int main(){
  Node* head = NULL;
  pushAtHead(&head, 4);
  pushAfter(head, 6);
  pushAtTail(&head, 8);
  pushAtHead(&head, 9);
  pushAtTail(&head, 2);
  pushAtHead(&head, 1);
  printLinkedList(head);

  head->next->next = head->next->next->next->next;

  detectLoop(head);
  return 0;
}
