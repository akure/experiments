#include<iostream>


int main()
{
 int i = 1;
 int& i_lvalref = i; 

 // int&& i_rvalref = i; // compiler error : error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
 
 int&& i_rvalref_2 = std::move(i); //  compile time Convertion of an lvalue to rvalue

 int&& i_rvalref_3 = 1; 
 
 // int&& i_rvalref_4 = i_lvalref; // compiler error : cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’

 std::cout << "i = " << i <<std::endl
	   << "i_lvalref = " << i_lvalref << std::endl 
	   << "i_rvalref_2 = " << i_rvalref_2 << std::endl
	   << "i_rvalref_3 = " << i_rvalref_3 << std::endl; 

 return 0;
}
