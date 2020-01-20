/*#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void delete_M_after_N(Node** head, int M, int N)
{
  int count = 0;
  Node* curr = *head;
  Node* temp;
  //while (curr)

    while(count<M && curr)
    {
      curr = curr->next;
      count++;
    }

    if(curr == NULL)
      return;

    temp = curr->next;
    int c = 1;
    while(c<=N && temp)
    {
      Node* t = temp;
      temp = temp->next;
      free(t);
      c++;
    }
    curr->next = temp;
    curr = temp;
  //}
}

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
  while(curr)
  {
    cout<<curr->data<<" -> ";
    curr = curr->next;
  }
  cout<<"X"<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 9);
  push(&head, 8);
  //push(&head, 7);
  //push(&head, 6);
  //push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  printLinkedList(head);
  delete_M_after_N(&head, 2, 2);
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

void delete_M_after_N(Node** head, int m, int n){
  Node* curr = *head;
  int count = 1;
  while(curr && count<m){
    curr = curr->next;
    count++;
  }

  count = 0;

  if(curr == NULL)
    return;

  Node* temp = curr->next;
  while(count<n && temp){
    Node* t = temp;
    temp = temp->next;
    free(t);
    count++;
  }
  curr->next = temp;
  //curr = temp;
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
  pushAtHead(&head, 9);
  pushAtTail(&head, 8);
  //push(&head, 7);
  //push(&head, 6);
  //push(&head, 5);
  pushAtHead(&head, 4);
  pushAtHead(&head, 3);
  pushAtTail(&head, 2);
  pushAtHead(&head, 1);

  printLinkedList(head);
  delete_M_after_N(&head, 2, 2);
  printLinkedList(head);

  return 0;
}
