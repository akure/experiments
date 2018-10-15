#include<iostream>

int main()
{
  
    auto l = { }; // compilation error : Can not deduce type from in empty initialization list.
    // error: unable to deduce ‘std::initializer_list<auto>’ from ‘<brace-enclosed initializer list>()’

}

