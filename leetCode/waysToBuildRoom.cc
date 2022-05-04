#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> *adjList;
    vector<int> res;
    bool *visited;
    int *inDeg;
    int size;
    int ways;
    bool flag = false;
    void findAllOrderings()
    {
        flag = false;
        for (int i = 0; i < size; ++i)
        {
            if (!visited[i] && inDeg[i] == 0)
            {
                visited[i] = true;
                for (int adj : adjList[i])
                    --inDeg[adj];
                res.push_back(i);
                findAllOrderings();
                res.pop_back();
                flag = true;
                visited[i] = false;
                for (int adj : adjList[i])
                    ++inDeg[adj];
            }
        }
        if (!flag)
        {
            for (int a : res)
                cout << a;
            cout << '\n';
        }
    }

public:
    int waysToBuildRooms(vector<int> &prevRoom)
    {
        size = prevRoom.size();
        inDeg = new int[size];
        adjList = new vector<int>[size];
        visited = new bool[size];
        for (int i = 0; i < size; ++i)
        {
            int temp = prevRoom[i];
            if (temp < 0)
                inDeg[i] = 0;
            else
            {
                ++inDeg[i];
                adjList[temp].push_back(i);
            }
            visited[i] = false;
        }
        ways = 0;
        findAllOrderings();

        delete[] inDeg;
        delete[] visited;
        delete[] adjList;
        return ways;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> s = {-1, 0, 0, 1, 2};
    cout << sol->waysToBuildRooms(s);
}

// MATH
class Solution_2
{
public:
    int waysToBuildRooms(vector<int> &prevRoom)
    {
        int n = prevRoom.size();
        nodeCount = vector<int>(n);
        graph = vector<vector<int>>(n, vector<int>(0));
        for (int i = 0; i < n; ++i)
            if (prevRoom[i] >= 0)
                graph[prevRoom[i]].push_back(i);
        dfs(0);
        unsigned long long fac = 1, prod = 1;
        int mod = (int)1e9 + 7;
        for (int i = n; i > 1; --i)
            fac = (fac * i) % mod;
        for (int i = 0; i < n; ++i)
            prod = (prod * nodeCount[i]) % mod;
        return (fac * modInverse(prod, mod)) % mod;
    }

private:
    vector<vector<int>> graph;
    vector<int> nodeCount;
    int dfs(int node)
    {
        int out = 0;
        for (int child : graph[node])
            out += dfs(child);
        nodeCount[node] = out + 1;
        return nodeCount[node];
    }

    int modInverse(int a, int m)
    {
        return power(a, m - 2, m);
    }

    int power(int x, int y, int m)
    {
        if (y == 0)
            return 1;
        int p = power(x, y / 2, m) % m;
        p = (int)((p * (long)p) % m);
        if (y % 2 == 0)
            return p;
        else
            return (int)((x * (long)p) % m);
    }
};