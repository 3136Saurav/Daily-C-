// PRINT THE DENOMINATIONS TOO??

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int minimum_coins(int coins[], int n, int val)
{
  int table[val+1];
  table[0] = 0;

  for(int i=1; i<n; i++)
    table[i] = INT_MAX;

  for(int i=1; i<val+1; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(coins[j]<=i)
      {
        int sub_res = table[i-coins[j]];
        if(sub_res!=INT_MAX && sub_res+1 < table[i])
          table[i] = sub_res + 1;
      }
    }
  }
  return table[val];
}

int main()
{
  int coins[] = {1, 2, 5};
  int n = sizeof(coins)/sizeof(coins[0]);
  int amount;
  cout<<"Enter Amount: ";
  cin>>amount;
  cout<<minimum_coins(coins, n, amount);
}
