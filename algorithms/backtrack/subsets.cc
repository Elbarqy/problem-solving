#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    int size;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        size = nums.size();
        dfs_backtrack(0, nums, *(new vector<int>()));
        return res;
    }
    void dfs_backtrack(int depth, vector<int> &nums, vector<int> &state)
    {
        res.push_back(state);
        for (int i = depth; i < size; ++i)
        {
            state.push_back(nums[i]);
            dfs_backtrack(i + 1, nums, state);
            state.pop_back();
        }
    }
};

int main()
{
    Solution *x = new Solution();
    x->subsets(*(new vector<int>{1, 2, 3}));
}