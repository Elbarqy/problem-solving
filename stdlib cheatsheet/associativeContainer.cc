#include <bits/stdc++.h>
using namespace std;

int main()
{
    //* ASSOCIATE CONTAINER set,multiSet  map, multimap

    //! limitations
    //! all values are read only
    //! traversing is slow compared to sequence container
    //! No random access
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(10);

    set<int>::iterator it = mySet.find(7); // O(log(n))
    set<int>::iterator it2 = mySet.find(10);

    pair<set<int>::iterator, bool> ret;
    ret = mySet.insert(3);
    if (ret.second == false)
        it = ret.first;  // points to three
    mySet.insert(it, 9); // it is a hint to find the value of 9
    mySet.erase(it);
    mySet.erase(7);

    //* MAPS
    map<char, int> myMap;
    myMap.insert(make_pair('a', 10));
    myMap.insert(pair<char, int>('x', 20));
    myMap.insert(pair<char, int>('b', 300));
    auto itr = myMap.find('b');

    for (itr = myMap.begin(); itr != myMap.end(); ++itr)
        cout << (*itr).first << " => " << (*itr).second << endl;
}