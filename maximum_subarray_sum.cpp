#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int maximum_sum_subarray(int arr[], int n)
{
  int sum = 0;
  int max = INT_MIN;
  for(int s=0; s<n; s++)
  {
    for(int e=0; e<n; e++)
    {
      sum=0;
      for(int i=s; i<=e; i++)
      {
        sum = sum + arr[i];
      }
      if(sum>max)
      {
        max = sum;
      }
    }
  }
  return max;
}

int main()
{
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<maximum_sum_subarray(arr,n);
  return 0;
}
