#include <bits/stdc++.h>

using namespace std;
int componentCount = 0;
int N, M;
void dfs(char *grid, int pos)
{
    if (pos >= M * N || pos < 0)
        return;
    if (grid[pos] != 'l')
        return;
    grid[pos] = 'v';
    for (int row = -1; row <= 1; ++row)
        for (int col = -1; col <= 1; ++col)
            if (row != 0 || col != 0)
                dfs(grid, pos + col + row * M);
}

int main()
{
    cin >> M >> N;
    char *grid = new char[M * N];
    for (int row = 0; row < M; ++row)
        for (int col = 0; col < N; ++col)
            cin >> grid[col + row * N];
    int x, y;
    cin >> x >> y;
    grid[y + x * M] = 'w';
    for (int row = 0; row < N; ++row)
        for (int col = 0; col < M; ++col)
            if (grid[col + row * M] == 'l')
            {
                dfs(grid, col + row * M);
                ++componentCount;
            }

    cout << componentCount << '\n';
}