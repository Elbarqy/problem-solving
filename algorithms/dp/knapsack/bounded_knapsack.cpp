#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> ks(int c, vi &W, vi &V)
{
    int n = W.size();
    vector<vi> dp = vector<vi>(n + 1, vi(c + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int sz = 1; sz <= c; ++sz)
        {
            dp[i][sz] = dp[i - 1][sz];
            if (W[i - 1] <= sz)
            {
                dp[i][sz] = max(dp[i][sz], dp[i - 1][sz - W[i - 1]] + V[i - 1]);
            }
        }
    }
    return dp;
}
void printDpMap(vector<vi> dp)
{
    for (auto row : dp)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void solutionTraversal(vector<vi> &dp)
{
    int row = dp.size();
    int col = dp[0].size() - 1;
    vi items_idx;

    while (row)
    {
        --row;
        while (--col)
        {
            if (dp[row][col] != dp[row][col - 1])
            {
                items_idx.push_back(row - 1);
                break;
            }
        }
    }

    for(auto idx: items_idx){
        cout<<idx<<" ";
    }
    cout<<'\n';
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    int i = n;
    vi w;
    vi v;
    while (i--)
    {
        int weight;
        scanf("%d", &weight);
        w.push_back(weight);
    }
    i = n;
    while (i--)
    {
        int value;
        scanf("%d", &value);
        v.push_back(value);
    }
    vector<vi> dp = ks(c, w, v);
    printDpMap(dp);
    solutionTraversal(dp);
}