#include <bits/stdc++.h>
using namespace std;

int main()
{
    //* SEQUENCE Containers vector deque list
    vector<int> vec;
    vec.push_back(20);
    vec.push_back(4);
    vec.push_back(5);
    // you can copy by constructor
    // you can swap vec2.swap(vec1)
    vector<int>::iterator itBegin = vec.begin();
    vector<int>::iterator itEnd = vec.end();
    cout << "iterator _1 \n";
    for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        cout << *itr << " ";
    cout << "sort then print with auto \n";
    sort(vec.begin(), vec.end());
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    //? list
    list<int> myList = {5, 10, 2, 1};
    list<int>::iterator itr = find(myList.begin(), myList.end(), 10);
    myList.insert(++itr, 15);
    for (int i : myList)
        cout << i;
    cout << "\ninserted 15 infront of 10 in the list {5,10,..} " << *--itr << "\n";

    //! here is the huge advantage of myList o(1) insertion of a big list
    list<int> list2 = {1};
    list2.splice(list2.begin(), myList, myList.begin(), myList.end());
    cout << "insertion in o(1)" << endl;
    for (int i : list2)
        cout << i << " ";
    cout << endl;
}