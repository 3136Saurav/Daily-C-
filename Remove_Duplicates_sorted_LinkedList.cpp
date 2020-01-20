/*#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void removeDuplicates(Node** head)
{
  Node* current = *head;
  Node* next_to_next = NULL;
  while(current->next!=NULL)
  {
    if(current->data == current->next->data)
    {
      next_to_next = current->next->next;
      free(current->next);
      current->next = next_to_next;
    }
    else
    {
      current = current->next;
    }
  }
}

void push(Node** head, int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  if(*head==NULL)
  {
    *head = newNode;
    return;
  }
  Node* temp = *head;
  while(temp->next!=NULL)
    temp = temp->next;

  temp->next = newNode;
}

void printLinkedList(Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" ";
    node = node->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = NULL;
  push(&head, 2);
  push(&head, 2);
  push(&head, 2);
  push(&head, 2);
  push(&head, 3);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 5);
  push(&head, 5);
  printLinkedList(head);
  removeDuplicates(&head);
  printLinkedList(head);
}*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

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

void removeDuplicates(Node** head){
  Node* curr = *head;
  Node* next_to_next = NULL;
  while(curr->next){
    if(curr->data == curr->next->data){
      next_to_next = curr->next->next;
      free(curr->next);
      curr->next = next_to_next;
    }
    else{
      curr = curr->next;
    }
  }
}

int main(){
  Node* head = NULL;
  push(&head, 2);
  push(&head, 2);
  push(&head, 2);
  push(&head, 2);
  push(&head, 3);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 5);
  push(&head, 5);
  printLinkedList(head);
  removeDuplicates(&head);
  printLinkedList(head);
  return 0;
}
