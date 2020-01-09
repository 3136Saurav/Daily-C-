/*#include<bits/stdc++.h>
using namespace std;

struct Node{
  string data;
  Node* next;
};

bool isPalindrome(Node* head)
{
  Node* curr = head;
  string newStr = "";
  while(curr)
  {
    newStr.append(curr->data);
    curr = curr->next;
  }
  int length = newStr.length();
  for(int i=0; i<length/2; i++)
  {
    if(newStr[i] != newStr[length-i-1])
      {
        cout<<newStr[i]<<" & "<<endl;
        return false;
      }
  }
  return true;
}

void pushAtHead(Node** head, string newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, string newData)
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
  pushAtTail(&head, "m");
  pushAtTail(&head, "ala");
  pushAtTail(&head, "ya");
  pushAtTail(&head, "l");
  pushAtTail(&head, "a");
  pushAtTail(&head, "m");
  printLinkedList(head);
  cout<<isPalindrome(head)<<endl;
  return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
  string data;
  Node* next;
};

void pushAtHead(Node** head, string newData){
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void pushAtTail(Node** head, string newData){
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

void pushAfter(Node* prev, string newData){
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

bool checkPalindrome(Node* head){
  string newStr = "";
  Node* curr = head;
  while(curr){
    newStr.append(curr->data);
    curr = curr->next;
  }
  int length =  newStr.length();
  for(int i=0; i<length/2; i++){
    if(newStr[i] != newStr[length-i-1]){
      return false;
    }
  }
  return true;
}

int main(){
  Node* head = NULL;
  pushAtTail(&head, "m");
  pushAtTail(&head, "al");
  pushAtTail(&head, "aya");
  pushAtTail(&head, "la");
  pushAtTail(&head, "m");
  printLinkedList(head);
  cout<<checkPalindrome(head)<<endl;
  return 0;
}
