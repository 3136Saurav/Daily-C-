#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
}

bool isPossible(int arr[], int n)
{
  int flag = 0;
  if(n<=2)
    return true;

  for(int i=0; i<n-2; i++)
  {
    if(!(arr[i+1]>arr[i] && arr[i+1]<arr[i+2]))
    {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
  {
    return true;
  }

  flag = 0;
  for(int i=0; i<n-2; i++)
  {
    if(!(arr[i+1]<arr[i] && arr[i+1]>arr[i+2]))
    {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
  {
    return true;
  }

  int val1 = INT_MIN;
  int val2 = INT_MAX;

  int min_i = -1 , max_i = -1;

  for(int i=0; i<n; i++)
  {
    if (arr[i]<val2)
    {
      val2 = arr[i];
      min_i = i;
    }
  }
  cout<<"MIN: "<<val2<<" "<<min_i<<endl;
  for(int i=0; i<n; i++)
  {
    if (arr[i]>val1)
    {
      val1 = arr[i];
      max_i = i;
    }
  }
  cout<<"MAX: "<<val1<<" "<<max_i<<endl;

  flag = 1;
  for(int i=0; i<max_i; i++)
  {
      if(arr[i]>arr[i+1])
      {
        flag = 0;
        break;
      }
  }

  if(min_i == max_i + 1 && flag == 1)
  {
      for(int i=min_i; i<n-1; i++)
      {
        if(arr[i]>arr[i+1])
        {
          flag = 0;
          break;
        }
      }
  }

  if (flag==1)
  {
    return true;
  }

  for(int i=0; i<min_i; i++)
  {
    if(arr[i]<arr[i+1])
    {
      flag = 0;
      break;
    }
  }

  if(max_i == min_i + 1 && flag == 1)
  {
    for(int i=max_i; i<n-1; i++)
    {
      if(arr[i]<arr[i+1])
      {
        flag = 0;
        break;
      }
    }
  }

  if(flag == 1)
  {
    return true;
  }

  return false;
}

int main()
{
  int arr[] = {1, 2, 4, 3, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, n);
  cout<<endl;
  if(isPossible(arr,n))
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }
  cout<<endl;
}
