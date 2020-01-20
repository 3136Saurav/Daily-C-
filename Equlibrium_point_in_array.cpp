/*#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int equilibrium_index(int arr[], int n)
{
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    sum = sum + arr[i];
  }

  int left_sum = 0;
  for(int i=0; i<n; i++)
  {
    sum = sum - arr[i];
    if(left_sum == sum)
    {
      cout<<"*"<<i<<endl;
    }
    left_sum = left_sum + arr[i];
  }

  return -1;
}

int main()
{
  int arr[] = {1, -1 , 1, 9, -9};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<equilibrium_index(arr, n);
  return 0;
}*/

#include<iostream>
using namespace std;

void equilibrium_index(int arr[], int n){
  int left_sum = 0;
  int sum = 0;
  for(int i=0; i<n; i++)
    sum = sum + arr[i];

  for(int i=0; i<n; i++){
    sum = sum - arr[i];
    if(sum == left_sum){
      cout<<" * "<<i;
    }
    left_sum = left_sum + arr[i];
  }
}

void printArray(int arr[], int n){
  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

  cout<<endl;
}

int main(){
  int arr[] = {8, -3, 1, 0, 4, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  equilibrium_index(arr, n);
}
