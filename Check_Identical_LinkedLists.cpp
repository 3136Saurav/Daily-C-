/*#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
  }
};

int lengthOfLinkedList(Node* head)
{
  int length = 0;
  Node* curr = head;
  while(curr)
  {
    curr = curr->next;
    length++;
  }
  return length;
}

bool checkIdentical(Node* head1, Node* head2)
{
  Node* a = head1;
  Node* b = head2;

  int len1 = lengthOfLinkedList(a);
  int len2 = lengthOfLinkedList(b);


  if(len1 != len2)
    return false;

  while(a && b)
  {
    if(a->data != b->data)
      return false;

    a = a->next;
    b = b->next;
  }

  if(a==NULL && b==NULL)
    return true;

  return false;
}


bool checkIdentical(Node* head1, Node* head2)
{
  if(head1==NULL && head2==NULL)
    return true;

  if(head1->data != head2->data)
    return false;

  else
    return checkIdentical(head1->next, head2->next);
}



void pushAtHead(Node** head, int newData)
{
  Node* newNode = new Node(newData);
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, int newData)
{
  Node* newNode = new Node(newData);
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

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
    return;

  Node* newNode = new Node(newData);
  newNode->next = prev->next;
  prev->next = newNode;
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

int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;

  pushAtHead(&head1, 2);
  //pushAtTail(&head1, 1);
  //pushAtHead(&head1, 4);
  //pushAfter(head1->next, 3);
  printLinkedList(head1);

  pushAtHead(&head2, 2);
  //pushAtTail(&head2, 1);
  //pushAtHead(&head2, 4);
  //pushAfter(head2->next, 3);
  printLinkedList(head2);

  if(checkIdentical(head1, head2))
    cout<<"\nIDENTICAL"<<endl;

  else
    cout<<"\nNOT IDENTICAL"<<endl;

  return 0;
}
*/




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
  while(curr->next){
    curr = curr->next;
  }
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

bool checkIdentical(Node* head1, Node* head2)
{
  if(head1 == NULL && head2 == NULL)
    return true;

  if(head1->data != head2->data)
    return false;

  else{
    return checkIdentical(head1->next, head2->next);
  }
}

int main(){
  Node* head1 = NULL;
  Node* head2 = NULL;

  pushAtHead(&head1, 1);
  pushAtHead(&head1, 1);
  pushAtHead(&head1, 1);

  printLinkedList(head1);

  pushAtHead(&head2, 1);
  pushAtHead(&head2, 1);
  pushAtHead(&head2, 1);

  printLinkedList(head2);

  cout<<checkIdentical(head1, head2);
  return 0;
}
