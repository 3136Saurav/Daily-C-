#include<iostream>
using namespace std;
#define defMethod(i) (i*i)

void show()
{
  int i = 0;
  register int j = 0;
  static int k = 0;
  i++;
  j++;
  k++;
  cout<<i<<" "<<j<<" "<<k;
}

int main()
{
  show();
  show();
  return 0;

}
