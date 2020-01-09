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

int countRotations(Node* head)
{
  int count = 0;
  int min = head->data;
  while(head!=NULL)
  {
    if(min>head->data)
    {
      break;
    }
    count++;
    head = head->next;
 }
 return count;
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
  Node* temp = *head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void pushAfter(Node* prev, int newData)
{
  if(prev == NULL)
  {
    return;
  }
  Node* newNode = new Node(newData);
  newNode->next = prev->next;
  prev->next = newNode;
}

void printLinkedList(Node* node)
{
  while (node!=NULL) {
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<"X"<<endl;
}

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 12);
  pushAtHead(&head, 11);
  pushAtHead(&head, 8);
  pushAtHead(&head, 5);
  pushAtHead(&head, 18);
  pushAtHead(&head, 15);
  pushAtHead(&head, 13);
  printLinkedList(head);
  cout<<countRotations(head)<<endl;
}
*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

int countRotations(Node* head){
  int count = 0;
  int start = head->data;
  while(start){
    if(start > head->data)
      break;
    count++;
    head = head->next;
  }
  return count;
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
  pushAtHead(&head, 12);
  pushAtHead(&head, 11);
  pushAtHead(&head, 8);
  pushAtHead(&head, 5);
  pushAtHead(&head, 18);
  pushAtHead(&head, 15);
  pushAtHead(&head, 13);
  printLinkedList(head);
  cout<<countRotations(head)<<endl;
  return 0;
}
