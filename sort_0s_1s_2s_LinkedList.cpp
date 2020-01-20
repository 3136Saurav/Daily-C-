//Incomplete???

#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

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
  if(prev==NULL)
    return;
  newNode->data = newData;
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

void sortZerosOnesTwos(Node* head)
{
  Node* zeroD = NULL;
  Node* oneD = NULL;
  Node* twoD = NULL;

  Node* temp = head;
  while(temp!=NULL)
  {
    if(temp->data == 0)
    {
      pushAtTail(&zeroD, 0);
    }
    if(temp->data == 1)
    {
      pushAtTail(&oneD, 1);
    }
    if(temp->data == 2)
    {
      pushAtTail(&twoD, 2);
    }
    temp = temp->next;
  }

  if(zeroD){
    Node* zeroCurr = zeroD;
    Node* twoCurr = twoD;

    while(zeroCurr->next){
      zeroCurr = zeroCurr->next;
    }

    if(twoD){
      zeroCurr->next = twoD;
      while(twoCurr->next){
        twoCurr = twoCurr->next;
      }
      twoCurr->next = oneD;
    }

    else{
      zeroCurr->next = oneD;
    }
  }

  else if(twoD){
    zeroD = twoD;
    Node* twoCurr = twoD;
    while(twoCurr->next){
      twoCurr = twoCurr->next;
    }
    if(oneD){
      twoCurr->next = oneD;
    }
    else{
      twoCurr->next = oneD;
    }
  }

  else{
    zeroD = oneD;
  }

  printLinkedList(zeroD);
  //printLinkedList(twoD);
}

int main()
{
  Node *head = NULL;
  //pushAtTail(&head, 0);
  pushAtTail(&head, 2);
  pushAtTail(&head, 1);
  //pushAfter(head->next, 2);
  pushAtTail(&head, 1);
  //pushAtTail(&head, 0);
  pushAfter(head->next->next, 1);
  //pushAtTail(&head, 0);
  printLinkedList(head);
  sortZerosOnesTwos(head);
  return 0;
}
