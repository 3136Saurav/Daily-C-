/// Incomplete???
////Review
#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

/*deleteSmallerNode(Node** head)
{

}*/

void reverseLinkedList(Node** head)
{
  Node* next = NULL;
  Node* curr = *head;
  Node* prev = NULL;
  while(curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
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

  Node* curr = *head;
  while(curr->next)
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

int main()
{
  Node* head = NULL;
  pushAtHead(&head, 2);
  pushAtTail(&head, 4);
  pushAtHead(&head, 7);
  pushAtTail(&head, 9);
  printLinkedList(head);
  reverseLinkedList(&head);
  printLinkedList(head);
  return 0;
}
