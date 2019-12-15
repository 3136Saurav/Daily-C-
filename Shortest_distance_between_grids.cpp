#include<bits/stdc++.h>
#define M 4
#define N 4
using namespace std;

class QItem
{
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int d): row(x), col(y), dist(d)
    {

    }
};

int minDistance(char grid[M][N])
{
  QItem source(0,0,0);
  bool visited[M][N];
  for(int i=0; i<M; i++)
  {
    for(int j=0; j<N; j++)
    {
      if(grid[i][j]=='0')
        visited[i][j] = true;
      else
        visited[i][j] = false;

      if(grid[i][j]=='s')
        {
          source.row = i;
          source.col = j;
       }
    }
  }

  queue<QItem> q;
  q.push (source);
  visited[source.row][source.col] = true;

  while(!q.empty())
  {
    QItem p = q.front();
    q.pop();

    if(grid[p.row][p.col] == 'd')
      return p.dist;

    if(p.row-1>=0 && visited[p.row-1][p.col] == false)
      {
        q.push(QItem(p.row-1,p.col,p.dist+1));
        visited[p.row-1][p.col] = true;
      }

    if(p.row+1<M && visited[p.row+1][p.col] == false)
      {
        q.push(QItem(p.row+1,p.col,p.dist+1));
        visited[p.row+1][p.col] = true;
      }

    if(p.col-1>=0 && visited[p.row][p.col-1] == false)
      {
        q.push(QItem(p.row,p.col-1,p.dist+1));
        visited[p.row][p.col-1] = true;
      }

    if(p.col+1<N && visited[p.row][p.col+1] == false)
      {
        q.push(QItem(p.row,p.col+1,p.dist+1));
        visited[p.row][p.col+1] = true;
      }
  }

  return -1;
}

int main()
{
  char grid[M][N] = { {'0', '*', '0', 's'},
                      {'*', '0', '*', '*'},
                      {'0', '*', '*', '*'},
                      {'d', '*', '*', '*'} };
  for(int i=0; i<M; i++)
  {
    for(int j=0; j<N; j++)
    {
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"--> \n"<<minDistance(grid)<<endl;
  return 0;
}
