#include<iostream>
#include<type_traits>

int main()
{
 

 int x = 10;
 int& xl = x;
 int&& xr = std::move(x);

 std::cout << std::boolalpha;
 std::cout << std::is_same<decltype(10), decltype(std::move(10))>::value << std::endl;
 std::cout << std::is_same<decltype(x), decltype(xl)>::value << std::endl;
 std::cout << std::is_same<decltype(x), decltype(xr)>::value << std::endl;
 return 0;
}

