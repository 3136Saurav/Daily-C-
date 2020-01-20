/*#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void push(Node** head, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void printLinkedList(Node* head)
{
  Node* curr = head;
  while(curr!=NULL)
  {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

void segregateList(Node** head)
{
  Node* evenHead = NULL;
  Node* oddHead = NULL;
  Node* evenEnd = NULL;
  Node* oddEnd = NULL;
  Node* curr = *head;

  while(curr!=NULL)
  {
    int val = curr->data;

    if (val%2==0)
    {
      if(evenHead==NULL)
      {
        evenHead = curr;
        evenEnd = evenHead;
      }
      else
      {
        evenEnd->next = curr;
        evenEnd = evenEnd->next;
      }
    }

    else
    {
      if(oddHead==NULL)
      {
        oddHead = curr;
        oddEnd = oddHead;
      }
      else{
        oddEnd->next = curr;
        oddEnd = oddEnd->next;
      }
    }
    curr = curr->next;
  }

  if(evenHead == NULL || oddHead == NULL)
    return;

  evenEnd->next = oddHead;
  oddEnd->next = NULL;
  *head = evenHead;
}

int main()
{
  Node* head = NULL;
  push(&head, 11);
  //push(&head, 10);
  push(&head, 0);
  push(&head, 9);
  //push(&head, 6);
  //push(&head, 4);
  push(&head, 1);
  printLinkedList(head);
  segregateList(&head);
  cout<<"Segregated List"<<endl;
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
  if(prev == NULL){
    return;
  }
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

void segregateList(Node* head){
  Node* evenList = NULL;
  Node* oddList = NULL;

  while(head){
    if((head->data)%2!=0){
      pushAtTail(&oddList, head->data);
    }
    else{
      pushAtTail(&evenList, head->data);
    }
    head = head->next;
  }

  Node* currEven = evenList;
  if(!evenList){
    printLinkedList(oddList);
    return;
  }
  while(currEven->next){
    currEven = currEven->next;
  }
  currEven->next = oddList;

  ///printLinkedList(oddList);
  printLinkedList(evenList);

}

int main(){
  Node* head = NULL;
  pushAtHead(&head, 1);
  pushAtTail(&head, 3);
  pushAfter(head, 2);
  pushAtTail(&head, 4);
  pushAtTail(&head, 5);
  pushAtTail(&head, 6);
  pushAtTail(&head, 7);

  printLinkedList(head);
  segregateList(head);
  return 0;
}
