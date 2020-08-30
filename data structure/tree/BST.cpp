#include <bits/stdc++.h>

using namespace std;

int BSTTopDown(int *a, int num, int size)
{
    int beg = 0;
    int end = size - 1;
    while (beg <= end)
    {
        int mid = (int)(beg + end) / 2;
        if (a[mid] > num)
        {
            end = mid;
        }
        else
        {
            if (a[mid] == num)
            {
                return mid;
            }
            else
            {
                beg = mid;
            }
        }
    }
    return -1;
}
int BSTBottomUp(int *a, int n, int l, int mid, int r)
{
    if (a[mid] == n || l >= r)
    {
        return mid;
    }
    else
    {
        if (a[mid] > n)
            return BSTBottomUp(a, n, l, (int)((l + mid) / 2), mid);
        else
            return BSTBottomUp(a, n, mid, (int)((mid + r) / 2), r);
    }
}

int main()
{
    int a[] = {9, 5, 4, 3, 1};
    sort(a, a + 4);
    cout <<a[BSTBottomUp(a, 5, 0,(5+0)/2 , 4)] << endl;
    return 0;
}