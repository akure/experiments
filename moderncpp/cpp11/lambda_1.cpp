#include<iostream>

int main()
{
  
  // In lambda :  param section, mutable keyword and trailing return is optional if not needed
  int x = 10;
  auto add = [=](int i)->int { return x + i ; } ;
  auto add_1 = [=](int i) mutable ->int 
  { 
    ++x;  // 11 
    return x + i ; 
  } ;
 
  auto change_val = [&](int new_val) { x = new_val;} ;

  std::cout << add(10) << std::endl;
  std::cout << add_1(10) << std::endl;

  change_val(11);
  std::cout << x << std::endl; 

  auto square = [x]{ return x*x; };
  std::cout << square() << std::endl;

  return 0;
}
