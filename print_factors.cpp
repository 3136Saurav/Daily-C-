/*Problem: Intersection of two matrices*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int print_factors(int a, int b)
{
  vector<int> vect1;
  vector<int> vect2;
  int i;
  for(int i=1; i<=a/2; i++)
  {
    if(a%i == 0)
    {
      vect1.push_back(i);
    }
  }
  for(int i=1; i<=b/2; i++)
  {
    if(b%i == 0)
    {
      vect2.push_back(i);
    }
  }
  int n = (vect1.size()>vect2.size())?vect2.size():vect1.size();
  int count=0;
  for(int i=0; i<n; i++)
  {
    if(vect1[i] == vect2[i])
    {
        count++;
    }
  }
  return count;
}

int main()
{
  int a, b;
  a = 20;
  b = 35;
  cout<<print_factors(b, a);

  return 0;
}
