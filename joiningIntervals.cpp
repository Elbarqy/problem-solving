#include <bits/stdc++.h>

using namespace std;

struct Interval
{
 int start;
 int end;
 Interval():start(0),end(0){}
 Interval(int a, int b){
    this->start = a;
    this->end = b;
 }
};

vector<Interval>
sol(vector<Interval> &intervals, Interval newInterval)
{
    map<int, int> nonOverLab;
    int size = intervals.size();
    for (int i = 1; i < size + 1; ++i)
    {
        Interval x = intervals[i - 1];
        nonOverLab.insert(make_pair(min(x.start , x.end), i));
        nonOverLab.insert(make_pair(max(x.start , x.end), -1 * i));
    }
    nonOverLab.insert(make_pair(min(newInterval.start , newInterval.end), size + 2));
    nonOverLab.insert(make_pair(max(newInterval.start , newInterval.end), -1 * (size + 2)));
    bool flag = false;
    int prev = 0;
    bool newBoundairy = false;
    for (auto itr : nonOverLab)
    {
        //this marks the begining of the new interval
        if (itr.second == size + 2)
        {
            flag = true;
            //check prev boundairy
        }
        if (flag)
        {
            if (itr.second == -1 * (size + 2))
            {
                //mark it with the previous range * -1 as a new boundairy
                //remove it from the map if it's part of a bigger range
                if (newBoundairy)
                    itr.second = -1 * prev;
                else
                    itr.second = 0;
                flag = false;
                break;
            }
            else
            {
                if (itr.second == -1 * prev)
                    newBoundairy = true;
                itr.second = 0;
            }
        }
        else
        {
            prev = itr.second;
        }
    }
    vector<Interval> res;
    prev = 0;
    bool created = false;
    Interval myInterval;
    for (auto itr : nonOverLab)
    {
        if (itr.second != 0)
        {
            if (!created)
            {
                myInterval.start = itr.first;
                created =true;
            }
            else
            {
                myInterval.end = itr.second;
                res.push_back(myInterval);
            }
        }
    }
    return res;
}

int main(){
    vector<Interval> x;
    Interval y = Interval(1,2);
    x.push_back(y);
    y = Interval(3,6);
    x.push_back(y);
    y= Interval(10,8);
    sol(x,y);
    return 0;
}