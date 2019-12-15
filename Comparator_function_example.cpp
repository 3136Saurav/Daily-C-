#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Interval
{
  int start, end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start > i2.start);
}

int main()
{
  Interval arr[] = {{1, 2},{5, 4},{6, 1}};
  int n = sizeof(arr)/sizeof(arr[0]);
  sort(arr, arr+n, compareInterval);
  for(int i=0; i<n; i++)
  {
    cout<<"["<<arr[i].start<<","<<arr[i].end<<"]"<<" ";
  }
  return 0;
}
