#include<bits/stdc++.h>
using namespace std;

void addOne(vector<int> vect)
{
  int n = vect.size();
  int carry = 0;
  vect[n-1] = vect[n-1] + 1;
  if(vect[n-1]>9)
  {
    vect[n-1] = vect[n-1]%10;
    carry = 1;
  }

  for(int i = n-2; i>=0; i--)
  {
    vect[i] = vect[i] + carry;
    if(vect[i]>=10)
    {
      carry = 1;
    }
    else{
      carry = 0;
    }
    vect[i] = vect[i] % 10;
  }

  if(carry>0)
  {
    vect.insert(vect.begin(), carry);
  }

  for(int i=0; i<vect.size(); i++)
  {
    cout<<vect[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  vector<int> vect{9, 9, 9};

  for(int i=0; i<vect.size(); i++)
  {
    cout<<vect[i]<<" ";
  }
  cout<<endl;

  addOne(vect);
  return 0;

}



























/*#include<bits/stdc++.h>

using namespace std;

void addOne(vector<int>& a)
{
  int n = a.size();
  a[n-1] = a[n-1]+1;
  int carry = a[n-1]/10;
  a[n-1] = a[n-1]%10;

  for(int i=n-2; i>=0; i--)
  {
    if (carry == 1)
    {
      a[i] = a[i] + 1;
      carry = a[i]/10;
      a[i] = a[i]%10;
    }
  }
  if (carry == 1)
  {
    a.insert(a.begin(),1);
  }
}

int main()
{
  vector<int> vect{9, 9, 9};
  addOne(vect);

  for (int i=0; i<vect.size(); i++)
  {
    cout<<vect[i]<<" ";
  }
  return 0;
}
*/
