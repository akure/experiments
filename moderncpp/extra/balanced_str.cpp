#include<vector>
#include<string>
#include<iostream>

using namespace std;
bool test_str(std::string&& str)
{
    int top_idx = -1 ;
    vector<char> v(str.length()); 

    for (auto & c : str)
    {
       // std::cout << "C : " << c  << ", " << str << std::endl;
       if ( c == '(' || c == '{' || c == '[' )
       {
         v[++top_idx] = c; // ++top_idx;
         continue; 
       }
       
       if (top_idx == -1) return false;


       // std::cout << "char : " << c << ": top_idx " << top_idx << std::endl;
       if (c == ')')
       {
          // std::cout << "(c == ')" << std::endl;
          if ( v[top_idx] == '{' || v[top_idx] == '[') 
          return false;
          else --top_idx;
       }
       else if ( c == ']')
       {
          if ( v[top_idx] == '(' || v[top_idx] == '{') 
          return false;
          else --top_idx;
       }
       else if ( c == '}')
       {
          if ( v[top_idx] == '(' || v[top_idx] == '[') 
          return false;
          else --top_idx;
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
