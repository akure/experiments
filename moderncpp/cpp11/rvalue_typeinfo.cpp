#include<iostream>
#include<typeinfo>

int main()
{
 
 std::cout << typeid(std::move(10)).name() << std::endl;	
 std::cout << typeid(10).name() << std::endl;	
 return 0;
}
