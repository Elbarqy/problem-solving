#include <bits/stdc++.h>

using namespace std;

void helloWorld()
{
    cout << "world" << endl;
}

void forEach(vector<int> &vec, void (*ops)(int))
{
    for (int val : vec)
        ops(val);
}

void printValue(int val)
{
    cout << val << " ";
}
int main()
{
    // void (*func)() = &helloWorld;
    // auto func = &helloWorld;
    // func();

    vector<int> myVec = {1, 2, 3, 4};
    forEach(myVec, [](int val)
            { cout << "printing value " << val << "\n"; });
}