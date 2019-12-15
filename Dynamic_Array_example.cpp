#include<iostream>

using namespace std;

class myArray
{
  int **p;
  int r, c;

public:
  void setSize();
  void readData();
  void printData();
  void destroyData();
};

void myArray :: setSize()
{
  cout<<"Enter Rows and Columns: ";
  cin>>r>>c;
  p = new int*[r];
  for(int i=0; i<r; i++)
  {
    p[i] = new int[c];
  }
}

void myArray :: readData()
{
  for(int i=0; i<r; i++)
    {
      for (int j=0; j<c; j++)
      {
      cin>>p[i][j];
      }
    }
}

void myArray :: printData()
{
  for(int i=0; i<r; i++)
    {
      for (int j=0; j<c; j++)
      {
      cout<<p[i][j]<<" ";
      }
      cout<<endl;
    }
}

void myArray :: destroyData()
{
  for(int i=0; i<r; i++)
      delete p[i];

  delete p;
}

int main()
{
  myArray m;
  cout<<"Enter Size: "<<endl;
  m.setSize();
  cout<<"Enter Values: "<<endl;
  m.readData();
  cout<<"You have Entered: "<<endl;
  m.printData();
  m.destroyData();
  return 0;

}
