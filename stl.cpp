#include <iostream>
//SEQUENCE container
#include <vector>
//associative containers
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void vectorTesting()
{
    vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.push_back(4);
    vector<int>::iterator itr1 = myVec.begin();
    vector<int>::iterator itr2 = myVec.end();
    for (vector<int>::iterator itr = itr1; itr != itr2; itr++)
    {
        cout << *itr << " ";
    }
}

void setTesting()
{
    set<int> mySet;
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(7); //log insert you can provide a hint to where the item is inserted and it will be O(1) insert(it, int item)
    set<int>::iterator it;
    it = mySet.find(7); //o(log(n))
    pair<set<int>::iterator, bool> ret;
    cout << ret.second << endl; //couted 0 shout be false
    mySet.erase(7);
    //value of multiSet can not be modified they are read only
    for (auto itr1 = mySet.begin(); itr1 != mySet.end(); itr1++)
    {
        cout << *itr1 << " ";
    }
}

void mapTesting()
{
    //search oLog(n)
    //Key value pair
    //doesn't allow duplicates
    map<char, int> myMap;
    myMap.insert(make_pair('z', 200));
    myMap.insert(make_pair('2', 50));
    myMap.insert(make_pair('3', 200));
    myMap.insert(pair<char, int>('q', 100));
    map<char, int>::iterator itr = myMap.find('2');
    cout << itr->first << " " << itr->second << endl;
}

void hashMapsAndSets()
{
    //O(1) search
    //sets look for items and see if they exists or not in an O(1)
    //no changes can happen
    unordered_set<string> unOrderedSet;
    vector<string> myvec = {"works" , "maybe later" , "exists"};
    unOrderedSet.insert(myvec.begin(),myvec.end());
    cout<<*unOrderedSet.find("works")<<endl;
    //ASSOCIATIVE ARRAY
    unordered_map<char , string> unOrderedMap = {{'s',"works"},{'w',"works"},{'z',"works"}};
    cout<<unOrderedMap['s']<<endl;
    unordered_map<char , string>::iterator itr = unOrderedMap.find('a');
    if(itr == unOrderedMap.end())
        cout<<"didnt find it"<<endl;
}

int main()
{
    hashMapsAndSets();
    return 0;
}