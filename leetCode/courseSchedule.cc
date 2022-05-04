#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<int> &visited, vector<int> &dfsq, vector<int> graph[])
    {
        visited[node] = 1;
        dfsq[node] = 1;
        for (auto it : graph[node])
        {
            if (visited[it] != 1)
            {
                if (dfs(it, visited, dfsq, graph))
                    return true;
            }
            else if (dfsq[it] == 1)
                return true;
        }
        dfsq[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> graph[numCourses];
        for (auto i : prerequisites)
            graph[i[1]].push_back(i[0]);
        vector<int> visited(numCourses + 1, -1);
        vector<int> dfsq(numCourses + 1, -1);
        for (int i = 0; i < numCourses; i++)
            if (visited[i] == -1)
                if (dfs(i, visited, dfsq, graph))
                    return false;
        return true;
    }
};

// iterative sol
class Solution_2
{
public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<int> adj[n];
        for (auto course : pre)
        {

            int u = course[0];
            int v = course[1];
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
            for (auto course : adj[i])
                indegree[course]++;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (auto course : adj[node])
            {
                indegree[course]--;
                if (indegree[course] == 0)
                    q.push(course);
            }
        }
        if (count == n)
            return 1;
        return 0;
    }
};