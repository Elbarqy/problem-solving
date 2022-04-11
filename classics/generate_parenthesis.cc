#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        this->generator("", n, n, result);
        return result;
    }
    // TODO
    // Do an iterative approach to this solution
    void generator(string res, int open, int close, vector<string> &result)
    {
        if (open == 0 && close == 0)
        {
            result.push_back(res);
        }
        else
        {
            if (open != 0)
                generator(res + '(', open - 1, close, result);
            if (close != 0 && open < close)
                generator(res + ')', open, close - 1, result);
        }
    }
};