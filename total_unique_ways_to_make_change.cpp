// NEEDS SOME CHANGES

#include<iostream>
using namespace std;
#define length 7

void total_ways_of_change(int coins[], int n, int amt)
{
  int coin_chart[n+1][amt];

  for(int row=0; row<n+1; row++)
  {
    for(int col=0; col<amt+1; col++)
    {
      if(row==0)
        coin_chart[row][col] = 0;

      else if(col==0)
        coin_chart[row][col] = 1;

      else
      {
        coin_chart[row][col] = coin_chart[row-1][col] + coin_chart[row][col-coins[row-1]];
      }
    }
  }
  for(int i=0; i<n+1; i++)
  {
    for(int j=0; j<amt+1; j++)
    {
      cout<<coin_chart[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<coin_chart[n][amt];
}



int main()
{
  int amount = 6;
  int coins[] = {1, 2, 5};
  int n = sizeof(coins)/int(sizeof(coins[0]));
  total_ways_of_change(coins, n, amount);
  return 0;
}
