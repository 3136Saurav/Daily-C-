// TOP DOWN APPRORACH

#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int minimum_coins(int coins[], int n, int val)
{
  int sub_res = 0;
  int res = INT_MAX;

  if(val == 0)
  {
    return 0;
  }

  for(int i=0; i<n; i++)
  {
    if(coins[i]<=val)
    {
      sub_res = minimum_coins(coins, n, val-coins[i]);

      if(sub_res!=INT_MAX && sub_res + 1 < res )
      {
        res = sub_res + 1;
      }
    }
  }
  return res;
}

int main()
{
  int denominations[] = {10, 25, 5};
  int n = sizeof(denominations)/sizeof(denominations[0]);
  int k;
  cout<<"Enter Amount: ";
  cin>>k;

  cout<<"Minimum Coins Needed: "<<minimum_coins(denominations, n, k);
  cout<<endl;
  printArray(denominations, n);
  return 0;
}
