#include <bits/stdc++.h>

using namespace std;

class Permutator
{
private:
    char source[4] = {'A', 'B', 'C', 'D'};
    int n = 4;
    inline void swap(int i, int j)
    {
        char temp = source[i];
        source[i] = source[j];
        source[j] = temp;
    }

public:
    void permutate(int current)
    {
        if (current == n - 1)
        {
            for (char c : source)
                cout << c;
            cout << endl;
        }
        else
            for (int i = current; i < n; ++i)
            {
                swap(i, current);
                permutate(current + 1);
                swap(i, current);
            }
    }
    void run()
    {
        this->permutate(0);
    }
};

int main()
{
    Permutator *permutator = new Permutator();
    permutator->run();
}