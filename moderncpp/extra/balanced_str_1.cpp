#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
unordered_set<char> opening_brackets  { '(', '{', '[' };
unordered_set<char> closing_brackets  { ')', '}', ']' };
unordered_map<char, char> co { {')','('}, {'}', '{'}, {']','['}};
bool test_str(std::string&& str)
{
    int top_idx = -1 ;
    vector<char> v(str.length()); // to avoid vector reallocation. Give capacity. 
    
    for (auto & c : str)
    {
       if (opening_brackets.find(c) != opening_brackets.end())
       {
         v[++top_idx] = c; 
         continue; 
       }
       
       if (top_idx == -1) return false;
       
       if (closing_brackets.find(c) != closing_brackets.end()) // c is one of the closing brackets 
       {
          if (co[c] == v[top_idx]) --top_idx;
          else return false;
       }
    }

    return (top_idx == -1);
}


int main()
{

    std::cout << boolalpha << std::endl;
    std::cout << test_str("(A)") << std::endl;
    std::cout << test_str("([ASDF])") << std::endl;
    std::cout << test_str("{([])}") << std::endl;
    std::cout << test_str("{([)}") << std::endl;
    return 0;
}
