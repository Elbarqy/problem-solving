
#include <bits/stdc++.h>

using namespace std;
// 1
// 5 9
// 1 4 5 7 8
// 50 40 60 80 10
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int wts[n];
        int val[n];

        for (int I = 0; I < n; ++I)
            cin >> wts[I];

        for (int I = 0; I < n; ++I)
            cin >> val[I];


        int dp[n][k];
        memset(dp, 0, sizeof(dp));

        //items will be denoted by I
        //sizes of the knapsack will be denoted by j
        for (int I = 0; I < n; ++I)
        {
            for (int j = 1; j < k+1; ++j)
            {
                //if the capacity of the knapsack can't handle item
                if (wts[I] > j)
                {
                    if (I != 0)
                        dp[I][j-1] = dp[I - 1][j-1];
                }
                else
                {
                    //go back in time and replace the old item of similar size
                    int prev;
                    if(I != 0 && j - wts[I] > 0) prev = dp[I - 1][j - wts[I]] + val[I];
                    else prev = val[I];
                    if(I != 0) dp[I][j-1] = max(dp[I - 1][j-1], prev);
                    else dp[I][j-1] = prev;
                }
            }
        }
        cout<<dp[n-1][n-1]<<endl;
    }
    return 0;
}