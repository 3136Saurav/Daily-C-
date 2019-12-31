#include<iostream>
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
