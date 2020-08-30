#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> flip(string A)
{
    int n = A.length();

    //build new array of 1s and -1s
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        if (A[i] == '1')
            ar[i] = -1;
        else
            ar[i] = 1;

    //pair storing the answer
    pair<int, int> ans = make_pair(n, n);

    //basic kadane's algorithm implementation
    //we also storing the begin point for best till now
    int best_till_now = 0, best_ending_here = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (best_ending_here + ar[i] < 0)
        {
            l = i + 1;
            best_ending_here = 0;
        }
        else
            best_ending_here += ar[i];
        if (best_ending_here > best_till_now)
        {
            best_till_now = best_ending_here;
            ans.first = l;
            ans.second = i;
        }
    }

    //if no valid subarray found
    if (ans.first == n)
        return vector<int>();

    //return answer
    vector<int> ret;
    ret.push_back(ans.first + 1);
    ret.push_back(ans.second + 1);
    return ret;
}
int main()
{
    string a = "0101010100011101110100100100001001010111010";
    vector<int> res = flip(a);
    cout << res[0] << endl;
    return 0;
}