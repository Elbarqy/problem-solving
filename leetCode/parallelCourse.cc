#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int *inDeg;
    vector<int> *adjList;

public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        int size = n + 1;
        inDeg = new int[size];
        memset(inDeg, 0, sizeof(int) * size);
        adjList = new vector<int>[size];
        for (auto relation : relations)
        {
            adjList[relation[1]].push_back(relation[0]);
            ++inDeg[relation[0]];
        }
        vector<int> qu;
        for (int i = 1; i < size; ++i)
            if (inDeg[i] == 0)
                qu.push_back(i);
        int itemCounter = qu.size();
        vector<vector<int>> levelItems;
        levelItems.push_back(qu);
        while (!qu.empty())
        {
            int current = qu.front();
            qu.erase(qu.begin());
            for (auto adj : adjList[current])
            {
                --inDeg[adj];
                if (inDeg[adj] == 0)
                    qu.push_back(adj);
            }
            --itemCounter;
            if (itemCounter == 0)
            {
                itemCounter = qu.size();
                if (itemCounter > 0)
                    levelItems.push_back(qu);
            }
        }
        int totalTime = 0;
        for (vector<int> level : levelItems)
        {
            int max = time[level[0] - 1];
            for (int item : level)
                if (max < time[item-1])
                    max = time[item-1];
            totalTime += max;
        }
        return totalTime;
    }
};

int main()
{
    //EXpected VALUE is 32 got 38
    Solution *sol = new Solution();
    vector<int> time = {9, 5, 9, 5, 8, 7, 7, 8, 4};
    vector<vector<int>> cc = {{2, 7}, {2, 6}, {3, 6}, {4, 6}, {7, 6}, {2, 1}, {3, 1}, {4, 1}, {6, 1}, {7, 1}, {3, 8}, {5, 8}, {7, 8}, {1, 9}, {2, 9}, {6, 9}, {7, 9}};
    cout<<sol->minimumTime(9, cc, time);
}