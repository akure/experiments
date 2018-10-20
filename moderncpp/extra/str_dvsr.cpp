#include<iostream>
#include<unordered_map>
#include<string>
#include<memory>

using namespace std;
using map_t = unordered_map<int, string>;
unique_ptr<string> nextNum(const map_t & m, int&& v)
{
    unique_ptr<string> s(new string()); // string can be large local
    s->reserve(100); 
   for(auto &  kv : m ) 
        if (v % kv.first == 0) s->append(kv.second) ;
   return std::move(s);
}

int main()
{

    map_t m;
    m.insert(make_pair(3, "fizz"));
    m.insert(make_pair(4, "buzz"));

    cout << *nextNum(m, 12) << endl;
    cout << *nextNum(m, 3) << endl;
    cout << *nextNum(m, 4) << endl;
    cout << *nextNum(m, 7) << endl;

    return 0;
}
