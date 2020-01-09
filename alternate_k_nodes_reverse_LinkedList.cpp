///Review!!
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
  Node* curr = *head;
  while(curr->next)
    curr = curr->next;
  curr->next = newNode;
}

void printLinkedList(Node* head){
  Node* curr = head;
  while(curr){
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

Node* alternateReverseInGroups(Node* head, int k)
{
  int count = 0;
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;
  while(curr && count<k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  head->next = next;

  count = 0;
  while(count<k-1 && curr){
    curr = curr->next;
    count++;
  }
  if(curr)
    curr->next = alternateReverseInGroups(curr->next, k);

  return prev;
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 1);
  pushAtTail(&head, 2);
  /*pushAtTail(&head, 3);
  pushAtTail(&head, 4);
  pushAtTail(&head, 5);
  pushAtTail(&head, 6);
  pushAtTail(&head, 7);
  pushAtTail(&head, 8);
  pushAtTail(&head, 9);
  pushAtTail(&head, 10);*/

  printLinkedList(head);
  Node* res = alternateReverseInGroups(head, 3);
  printLinkedList(res);
  return 0;
}



/*#include<iostream>
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
  while(curr->next != NULL)
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

Node* alternateReverseInGroups(Node* head, int k)
{
  Node* curr = head;
  Node* next = NULL;
  Node* prev = NULL;
  int count = 0;
  while(curr && count<k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if(head!=NULL)
  {
    head->next = curr;
  }

  count = 0;
  while(count<k-1 && curr)
  {
    curr = curr->next;
    count++;
  }

  if(curr!=NULL)
    curr->next = alternateReverseInGroups(curr->next, k);

  return prev;
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 1);
  pushAtTail(&head, 2);
  pushAtTail(&head, 3);
  pushAtTail(&head, 4);
  pushAtTail(&head, 5);
  pushAtTail(&head, 6);
  pushAtTail(&head, 7);
  pushAtTail(&head, 8);

  printLinkedList(head);
  head = alternateReverseInGroups(head, 3);
  printLinkedList(head);
}
*/
