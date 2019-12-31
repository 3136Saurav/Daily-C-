// Incomplete???

#include<iostream>
using namespace std;

struct PolynomialNode
{
  int coefficient;
  int degree;
  PolynomialNode* next;
};

void addElement(PolynomialNode** head, int coefficient, int degree)
{
  PolynomialNode* newNode = new PolynomialNode();
  newNode->coefficient = coefficient;
  newNode->degree = degree;
  newNode->next = NULL;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  PolynomialNode* temp = *head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void printPolynomial(PolynomialNode* node)
{
  while(node!=NULL)
  {
    cout<<node->coefficient<<" *x^"<<node->degree<<" + ";
    node = node->next;
  }
  cout<<" 0 "<<endl;
}

int lengthOfPolynomialList(PolynomialNode* polyHead)
{
  int count = 0;
  while(polyHead!=NULL)
  {
    count++;
    polyHead = polyHead->next;
  }
  return count;
}

void addPolynomials(Node* polyHead1, Node* polyHead2)
{
  Node* t1 = polyHead1;
  Node* t2 = polyHead2;
  Node* resultPolynomial = NULL;
  int sum = 0;
  int len1 = lengthOfPolynomialList(polyHead1);
  int len2 = lengthOfPolynomialList(polyHead2);

  int maxLength = 0;
  if(len1 >= len2)
    maxLength = len1;
  else
    maxLength = len2;

  int i = 0;
  while(i < maxLength)
  {

    i++;
  }

}

int main()
{
  PolynomialNode* polyHead1 = NULL;
  PolynomialNode* polyHead2 = NULL;

  addElement(&polyHead1, 5, 2);
  addElement(&polyHead1, 4, 1);
  addElement(&polyHead1, 2, 0);

  printPolynomial(polyHead1);

  addElement(&polyHead2, 4, 1);
  addElement(&polyHead2, 2, 0);

  printPolynomial(polyHead2);


  return 0;
}
