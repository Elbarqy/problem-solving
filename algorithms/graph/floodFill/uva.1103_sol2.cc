// Neat solution not mine but I'm holding it for future reference

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
int n, m, s[500][500], tt[500][500], t[500][500], ctt;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
char ss[500][500];

bool in(int i, int j)
{
    return i >= 0 && i <= n && j <= m && j >= 0;
}

void dfs(int i, int j, int c, int s[500][500], int t[500][500])
{
    t[i][j] = 1;
    s[i][j] = c;
    for (int k = 0; k < 4; k++)
    {
        int ii = i + di[k], jj = j + dj[k];
        if (in(ii, jj) && s[ii][jj])
            dfs(ii, jj, c, s, t);
    }
}

char get_()
{
    int ct = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            t[i][j] = !t[i][j];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (t[i][j])
                dfs(i, j, 0, t, tt), ct++;
    return "gWAKJSD"[ct];
}

int main()
{
    while (cin >> n >> m, n + m)
    {
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++)
            scanf("%s", ss[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int x = isdigit(ss[i][j]) ? ss[i][j] - '0' : ss[i][j] - 'a' + 10;
                for (int k = 0; k < 4; k++)
                    s[i + 1][j * 4 + 4 - k] = 1 & (x >> k);
            }
        vector<char> ans;
        printf("Case %d: ", ++ctt);
        n += 10, m = m * 4 + 10;
        for (int j = 0; j <= m; j++)
            for (int i = 0; i <= n; i++)
                if (s[i][j])
                {
                    memset(t, 0, sizeof(t));
                    dfs(i, j, 0, s, t);
                    ans.push_back(get_());
                }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            putchar(ans[i]);
        putchar(10);
    }
    return 0;
}