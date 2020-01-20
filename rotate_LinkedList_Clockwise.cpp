/*#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

int lengthOfLinkedList(Node* node)
{
  int length=0;
  while(node!=NULL)
  {
    length++;
    node = node->next;
  }
  return length;
}

void rotateClockwise(Node** head, int k)
{
  Node* kthNodeComplement = NULL;
  Node* current = *head;
  int kk = lengthOfLinkedList(*head) - k - 1;
  int count = 0;

  while(count<kk && current)
  {
    current = current->next;
    ++count;
  }
  kthNodeComplement = current;
  while(current->next!=NULL)
  {
    current = current->next;
  }
  current->next = *head;
  *head = kthNodeComplement->next;
  kthNodeComplement->next = NULL;
}

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
  Node* newNode = new Node();
  newNode->data = newData;
  if(prev==NULL)
  {
    return;
  }
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

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 3);
  pushAtTail(&head, 7);
  pushAfter(head->next, 4);
  pushAtHead(&head, 5);
  pushAfter(head->next->next, 8);
  printLinkedList(head);
  rotateClockwise(&head, 2);
  printLinkedList(head);
  return 0;
}
*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void rotateClockwise(Node** head, int k) {
  Node* refPtr = *head;
  Node* NthfromEnd = *head;
  Node* prev = NULL;
  int count = 0;
  while(refPtr && count<k){
    count++;
    refPtr = refPtr->next;
  }
  while(refPtr){
    prev = NthfromEnd;
    NthfromEnd = NthfromEnd->next;
    refPtr = refPtr->next;
  }
  Node* temp = prev;
  while(prev->next){
    prev = prev->next;
  }

  temp->next = NULL;
  prev->next = *head;
  *head = NthfromEnd;
}

void push(Node** head, int newData){
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
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
  push(&head, 8);
  push(&head, 7);
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  printLinkedList(head);
  rotateClockwise(&head, 7);
  printLinkedList(head);
  return 0;
}
