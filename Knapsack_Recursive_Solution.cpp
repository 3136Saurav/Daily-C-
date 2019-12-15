#include<bits/stdc++.h>
using namespace std;


int max(int a, int b)
{
  return (a>b)?a:b;
}

int Knapsack_recursive(int W, int wt[], int v[], int n)
{
  //static int arr[n+1][W+1];

  if (n==0||W==0)
    return 0;

  else if(wt[n-1]>W)
    return Knapsack_recursive(W, wt, v, n-1);

  else
      return max(Knapsack_recursive(W,wt,v,n-1), Knapsack_recursive(W-wt[n-1], wt, v, n-1) + v[n-1]);
}

int main()
{
  int W = 10;
  int result = 0;
  int weight[] = {1, 2, 4, 2, 5};
  int value[] = {5, 3, 5, 3, 2};
  int n = sizeof(weight)/sizeof(weight[0]);
  result = Knapsack_recursive(W, weight, value, n);
  cout<<result;
}
