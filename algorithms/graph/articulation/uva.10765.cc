#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
class Solution
{
private:
    int UNVISITED = -1;
    int n, m, dfsRoot, rootChildren;
    int dfs_num[10003], dfs_low[10003], dfsCounter = 0, dfs_parent[10003], artCounter[10003];
    vi adjList[10003];
    void init_variables(int N)
    {
        dfsCounter = 0;
        dfsRoot = 0;
        memset(dfs_num, UNVISITED, N * 4);
        memset(dfs_low, UNVISITED, N * 4);
        memset(dfs_parent, UNVISITED, N * 4);
        memset(artCounter, 0, N * 4);
    }

public:
    void dfs(int u)
    {
        dfs_num[u] = dfs_low[u] = ++dfsCounter;
        for (int neighbour : adjList[u])
        {
            if (dfs_num[neighbour] == UNVISITED)
            {
                dfs_parent[neighbour] = u;
                if (u == dfsRoot)
                    ++rootChildren;
                dfs(neighbour);
                if (dfs_low[neighbour] >= dfs_num[u])
                    ++artCounter[u];

                dfs_low[u] = min(dfs_num[neighbour], dfs_low[u]);
            }
            else if (dfs_parent[u] != neighbour)
                dfs_low[u] = min(dfs_low[u], dfs_num[neighbour]);
        }
    }
    void populate()
    {
        int a, b;
        init_variables(n + 1);
        while (cin >> a >> b, a + b > 0)
        {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
    }
    static int compare(const void *a, const void *b)
    {
        return (*(int *)b - *(int *)a);
    }
    void solver()
    {
        while (cin >> n >> m, n + m)
        {
            populate();
            for (int i = 0; i < n; ++i)
            {
                rootChildren = 0;
                dfsRoot = i;
                dfs(i);
                if (rootChildren >= 1)
                    artCounter[i] = rootChildren - 1;
            }
            qsort(artCounter, n, sizeof(int), Solution::compare);
            for (int i = 0; i < m; ++i)
                cout << artCounter[i] + 1 << endl;
        }
    }
};

int main()
{
    Solution *sol = new Solution();
    sol->solver();
}