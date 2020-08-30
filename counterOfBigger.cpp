#include <bits/stdc++.h>

using namespace std;

int sol(vector<int> &A)
{
    sort(A.begin(), A.end());
    int size = A.size();
    map<int, int> counter;
    for (int i = 0; i < size; ++i)
    {
        auto it = counter.find(A[i]);
        if (it == counter.end())
        {
            counter.insert(make_pair(A[i], size - i - 1));
        }
        else
        {
            --it->second;
        }
    }
    for (auto it : counter)
    {
        if(it.first == it.second)
            return it.first;
    }
    return -1;
}
int main()
{
    vector<int> A = {3,4,4,4,3,5,8,9};
    sol(A);
    return 0;
}