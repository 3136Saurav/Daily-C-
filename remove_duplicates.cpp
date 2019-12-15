#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 26

char *removeDups(char str[])
{
  bool hash[NO_OF_CHARS] = {0};
  int ip_index = 0, res_index = 0;
  char temp;
  while(*(str + ip_index))
  {
    temp = *(str + ip_index);
    if(hash[temp] == 0)
    {
      hash[temp] = 1;
      *(str + res_index) = *(str + ip_index);
      res_index++;
    }
    ip_index = ip_index + 1;
  }
  *(str + res_index) = '\0';

  return str;
}

int main()
{
  char str[] = "geeksforgeeks";
  cout<<removeDups(str);

  return 0;
}
