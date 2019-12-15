#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
  return (a>b?a:b);
}

int knapsack_solve(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
  int result;

  int T;
  //cout<<"Enter Number of Test cases: ";
  cin>>T;
  for(int i=0; i<T; i++)
  {
    int n, W, result ;
    //cout <<"Enter Number of items: ";
    cin>>n;
    //cout<<"Enter Maximum Capacity: ";
    cin>>W;
    int wt[n], v[n];
    //cout<<"Enter Weights: ";
    for(int i=0; i<n; i++)
    {
      cin>>wt[i];
    }
    //cout<<"Enter Values: ";
    for(int i=0; i<n; i++)
    {
      cin>>v[i];
    }

    result = knapsack_solve(W, wt, v ,n);
    cout<<result<<endl;
    //cout<<"OPTIMUM VALUE: "<<result<<" "<<endl;
  }

return 0;
}
