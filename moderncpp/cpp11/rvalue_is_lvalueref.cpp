#include<iostream>
#include<type_traits>

int main()
{

  std::cout << std::boolalpha;
  std::cout << "is_lvalue_reference:" << std::endl;
  std::cout << "int: " << std::is_lvalue_reference<int>::value << std::endl;
  std::cout << "int&: " << std::is_lvalue_reference<int&>::value << std::endl;
  std::cout << "int&&: " << std::is_lvalue_reference<int&&>::value << std::endl;


  int x = 10;
  int& xl = x;
  int && xr = std::move(x);
  int && xr2 = 10;

  std::cout << "x : " << std::is_lvalue_reference<decltype(x)>::value << std::endl;
  std::cout << "xl : " << std::is_lvalue_reference<decltype(xl)>::value << std::endl;
  std::cout << "xr : " << std::is_lvalue_reference<decltype(xr)>::value << std::endl;
  std::cout << "xr2 : " << std::is_lvalue_reference<decltype(xr2)>::value << std::endl;

  auto y = 10;
  auto& yl = x;
  auto && yr = std::move(y);
  auto && yr2 = 10;

  std::cout << "y  : " << std::is_lvalue_reference<decltype(y)>::value << std::endl;
  std::cout << "yl : " << std::is_lvalue_reference<decltype(yl)>::value << std::endl;
  std::cout << "yr : " << std::is_lvalue_reference<decltype(yr)>::value << std::endl;
  std::cout << "yr2 : " << std::is_lvalue_reference<decltype(yr2)>::value << std::endl;

 return 0;
}
