#include <bits/stdc++.h>

using namespace std;

void printMemonics(vector<int> &v,int current, int size,vector<char> res)
{
    if (res.size() == size)
    {
        for(char a : res)
            cout<<a;
        cout<<endl;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            vector<char> newRes = res;
            char added =(char)(65+v[current]*3 + i);
            newRes.push_back(added);
            printMemonics(v,current +1 , size ,newRes);
        }
    }
}

void sol(int a)
{
    vector<int> parts;
    while (true)
    {
        if (a == 0)
            break;
        parts.insert(parts.begin(), a % 10);
        a = (int)a / 10;
    }
    printMemonics(parts, 0, parts.size() , {});
}

int main()
{
    sol(25);
    return 0;
}