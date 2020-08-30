#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long
int maxContinousSum(int A, vector<int> &B)
{
    ll tot = 0;
    for (int val : B)
        tot += (ll)(val);

    if (tot % 3 != 0)
        return 0;

    tot = tot / 3;
    ll cur = 0, x = 0, ans = 0;
    for (int i = 0; i < A - 1; ++i)
    {
        cur += (ll)B[i];
        if (cur == 2 * tot && i > 0)
            ans += x;
        if (cur == tot)
            ++x;
    }
    return ans;
}

int main()
{
    vector<int> M = {3,0,0,3,0,3};
    cout << maxContinousSum(5, M) << endl;
    return 0;
}