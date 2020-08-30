#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    int size = A.size();
    if(size == 0) return {};
    long long number = 0;
    long long power = pow(10,size-1);
    if(power == 0) power = 1;
    for(int a : A){
        number += power * a;
        if(power != 1) power = power/10;
    }
    ++number;
    vector<int >res;
    while(number != 0){
        res.insert(res.begin(),number%10);
        number = (long long ) (number / 10);
    }
    cout<<res[2]<<endl;
    return res;
}


int main(){
    vector<int> M = {9,9,9,9,9,9,9,9,9};
    plusOne(M);
    return 0;
}