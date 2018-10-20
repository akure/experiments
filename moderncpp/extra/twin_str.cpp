#include<iostream>
#include<set>
#include<string>

using namespace std;

bool twin(const string & s1, const string & s2)
{
    
    if ( s1.length() != s2.length() ) return false;
    set<char> e;
    set<char> o;

    // processing s1
    for (int k = 0; k <= (s1.length() - 1 - 1 ); k += 2) 
    {
        e.insert(s1[k]);
        o.insert(s1[k+1]);
    }
    if ( s1.length() % 2 != 0 )  e.insert(s1[s1.length()-1]);


    // processing s2
    for (int k = 0; k <= (s2.length() - 1 - 1 ); k += 2) 
    {
        if (e.find(s2[k]) != e.end()) e.erase(s2[k]);
        if (o.find(s2[k+1]) != o.end()) o.erase(s2[k+1]);
    }

    if(s2.length() % 2 != 0 ) // even elements
        if ( e.find(s2[s2.length() -1]) != e.end()) e.erase(s2[s2.length()-1]);

    if (e.size() <= 1 && o.size() <= 1) return true;
    else return false;

}

int main()
{

    cout << boolalpha << endl;
    cout << twin("outlook", "lookout") << endl;
    cout << twin("silent", "listen") << endl;
    cout << twin("silent", "iselnt") << endl;
    return 0;
}
