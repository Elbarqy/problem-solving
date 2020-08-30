
#include <bits/stdc++.h>

using namespace std;

class number
{
    vector<int> digits;

public:
    int a;
    number(int b)
    {
        this->a = b;
        int z = b;
        while (z != 0)
        {
            this->digits.insert(this->digits.begin(), z % 10);
            z = (int)z / 10;
        }
    }
    bool operator<(number b)
    {
        int i = 0;
        int j = 0;
        int size = this->digits.size();
        int secondSize = b.digits.size();
        for (i = 0; i < size; i++)
        {
            if (j < secondSize)
            {
                if (this->digits[i] > b.digits[j])
                    return true;
                if (this->digits[i] == b.digits[j])
                    j++;
                if (this->digits[i] < b.digits[j])
                    return false;
            }else{
                break;
            }
        } // it ended without returning
        if(j < secondSize){
            //second element is greater in size
            //both elements are equale
            if(size == secondSize) return true;
            if(this->digits[0] > b.digits[j]) return true;
            else return false;
        }else{
            //this means second is less in size;
            //this means both are equale;
            if(size == secondSize) return true;
            if(this->digits[i] > b.digits[j]) return true;
            else return false;
        }
    }
};


string largestNumber(const vector<int> &A) {
    vector<number> B;
    for (int a : A)
    {
        number x = number(a);
        B.push_back(x);
    }
    sort(B.begin(), B.end());
    string x = "";
    for (number a : B)
    {
        x+= to_string(a.a);
    }
    return x;
}
int main()
{
    vector<int> A = {0, 0, 0, 0, 0};
    // vector<int> A = {3, 30, 34, 5, 9};
    string sol = largestNumber(A);
    cout<<sol<<endl;
    return 0;
}