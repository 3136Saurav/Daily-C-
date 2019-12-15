#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    string str;

    cin>>str;

    map<char, int> make_balance;

    for(int i=0; i<str.length(); i++)
    {
        make_balance.insert(pair<char,int>(str[i],make_balance[str[i]]++));
    }

    int max = 0;

    for(auto& x : make_balance)
    {
        if (max < x.second)
        {
            max = x.second;
        }
    }

    int total = 0;

    for(auto& x : make_balance)
    {
        total += (max - x.second);
    }

    cout<<total;

    return 0;
}
