#include <stdio.h>
#include <iostream>
using namespace std;
bool isIsomorphic(string str1, string str2)
{
    // now we will have two arrays for the mapping purpose
    int map1[128] = {0};
    int map2[128] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        if (map1[str1[i]] != map2[str2[i]])
            return false;

        map1[str1[i]] = i + 1;
        map2[str2[i]] = i + 1;
    }
    return true;
}
int main()
{
    string str1 = "boob";
    string str2 = "cooc";
    if (isIsomorphic(str1, str2))
        cout << "Strings are isomorphic"<<endl;
    else
        cout << "Strings are not isomorphic"<<endl;
    return 0;
}