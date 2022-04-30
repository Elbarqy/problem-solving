#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
typedef std::vector<int> vi;

// we have N nodes that are connected
// Objective: we want to count the number of nodes
// that holds the network exchanges together

// I think this is a problem addressing articulation point
// We are gonna check for articulation points and then counts them

// Methodology
// dfs
//  Keep track of the num of traversal
//  keep track of the lowest id reachable from the current node
//  Check for articulation point
//  articulatoin points are usually
//  a connection point between nodes x -- currentNode -- y dfs_num[u] < dfs_low[v]
//  an entry point to a cycle  dfs_num[u] == dfs_low[v] (where v is the child)

// input
// 5
// 5 1 2 3 4
// 0
// 6
// 2 1 3
// 5 4 6 2
// 0
// 0
vi nodes[101];
int dfs_num[101], dfs_low[101], dfs_parent[101];
bool art_points[101];
int rootChildren = 0, dfsCounter = 0, dfsRoot, dfsChildren = 0;
void init_parameters()
{
    dfsCounter = 1;
    rootChildren = 0;
    memset(nodes, {}, sizeof nodes);
    memset(dfs_num, -1, sizeof dfs_num);
    memset(dfs_low, -1, sizeof dfs_low);
    memset(dfs_parent, -1, sizeof dfs_parent);
    memset(art_points, false, sizeof art_points);
}
void articulationPoints(int u)
{
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    for (int neighbour : nodes[u])
    {
        if (dfs_num[neighbour] == -1)
        {
            dfs_parent[neighbour] = u;
            if (dfs_num[u] == dfsRoot)
                ++dfsChildren;
            articulationPoints(neighbour);
            if (dfs_low[neighbour] >= dfs_num[u])
                art_points[u] = true;
            dfs_low[u] = std::min(dfs_low[neighbour], dfs_low[u]);
        }
        else if (dfs_parent[neighbour] != u)
            dfs_low[u] = std::min(dfs_num[neighbour], dfs_low[u]);
    }
}
int main()
{
    std::string N;
    int n;
    while (std::getline(std::cin, N))
    {
        n = std::stoi(N);
        if (n == 0)
            break;
        // reading edges;
        std::string line;
        while (true)
        {
            std::getline(std::cin, line);
            std::stringstream myStream(line);
            int currentPlace;
            myStream >> currentPlace;
            if (currentPlace == 0)
                break;
            int b;
            init_parameters();
            while (myStream)
            {
                if (myStream)
                {
                    myStream >> b;
                    nodes[currentPlace].push_back(b);
                    nodes[b].push_back(currentPlace);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            if (dfs_num[i] == -1)
            {
                dfsChildren = 0;
                dfsRoot = i;
                articulationPoints(i);
                art_points[i] = dfsChildren > 1;
            }
        int counter = 0;
        for (bool articulated : art_points)
            if (articulated)
                ++counter;
        std::cout << counter << '\n';
    }
}