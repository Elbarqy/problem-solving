#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi adjList[201];
int colors[201];
int N;

int main()
{
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        int l;
        cin >> l;
        while (l--)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            colors[a] = colors[b] = -1;
        }
        vi queue;
        queue.insert(queue.begin(), 0);
        bool biColor = true;

        while (biColor && !queue.empty())
        {
            int current = queue.front();
            queue.erase(queue.begin());
            if (colors[current] != -1)
                continue;
            if (adjList[current].size() > 4)
                biColor = false;
            int picker[4] = {1, 2, 3, 4};
            colors[current] = picker[0];
            for (int node : adjList[current])
            {
                if (colors[node] > 0)
                {
                    if (picker[colors[node] - 1] == colors[node])
                        picker[colors[node] - 1] = picker[((colors[node] - 1) + 3) % 4];
                    else
                        biColor = false;
                }
                else
                    queue.insert(queue.begin(), node);
            }
            colors[current] = picker[0];
        }
        if (biColor)
            std::cout << "4 COLORED." << '\n';
        else
            std::cout << "NOT 4 COLORED." << '\n';
    }
}