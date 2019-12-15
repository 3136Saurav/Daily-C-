/*
Print the elements of an array in the decreasing frequency
if 2 numbers have same frequency then print the one which came first.

Examples:

Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}
*/
#include<bits/stdc++.h>
using namespace std;

struct ele
{
  int value, count, index;
};

void PrintElements(ele Elements[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<"Element:  "<<Elements[i].value<<" "<<Elements[i].index<<" "<<Elements[i].count<<" "<<endl;
  }
}

void PrintArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool mycomp1(ele element1, ele element2) //Sort by Value
{
    return (element1.value < element2.value);
}

bool mycomp2(ele element1, ele element2) // Sort by Index
{
  if (element1.count!=element2.count)
    return (element1.count < element2.count);
  else
    return (element1.index > element2.index);
}

void sortByFrequency(int arr[], int n)
{
  struct ele element[n];
  for(int i=0; i<n; i++)
  {
    element[i].index = i;
    element[i].count = 0;
    element[i].value = arr[i];
  }
  stable_sort(element,element+n, mycomp1);
  PrintElements(element, n);
  element[0].count = 1;
  for(int i=1; i<n; i++)
  {
    if(element[i].value == element[i-1].value)
    {
      element[i].count += element[i-1].count + 1;
      element[i-1].count = -1;
      element[i].index = element[i-1].index;
    }
    else
    {
      element[i].count = 1;
    }
  }
  PrintElements(element, n);
  stable_sort(element, element+n, mycomp2);
  cout<<endl;
  //PrintElements(element, n);
  for(int i=n-1, index=0; i>=0; i--)
  {
    if(element[i].count!=-1)
    {
      for(int j=0; j<element[i].count; j++)
      {
        arr[index] = element[i].value;
        index++;
      }
    }
  }

}

int main()
{
  int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
  int n = sizeof(arr)/sizeof(arr[0]);
  PrintArray(arr, n);
  sortByFrequency(arr,n);
  PrintArray(arr, n);
  return 0;
}
