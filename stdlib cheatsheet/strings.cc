#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "abcdefg";
    char buff[20];
    size_t len = s1.copy(buff, 3); // buff: abc => len= 3
    len = s1.copy(buff, 4, 2);     // buff: cdef  => len= 4

    //! you work with character array as strings are immutable
    //Convert to char array
    string cppstr = "this is a string";
    char target[1024];
    strcpy(target, cppstr.c_str());
}