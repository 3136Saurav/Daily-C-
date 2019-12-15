#include<bits/stdc++.h>
using namespace std;

int minimum_steps(int arr[], int n)
{
  int count = 0;
  int i = 0;
  int k = n;
  if(n==1)
    return 0;
  else
  {
    while(i<n-1)
    {
      k = arr[i];
      i = i+k;
      count++;
      //cout<<i;
    }
  }
  return count;
}

int main()
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  {
    int result;
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
    {
      cin>>arr[i];
    }
    result = minimum_steps(arr, size);
    cout<<result<<endl;
  }
  return 0;
}
