#include<iostream>


//auto main() -> int // it works as well
int main() 
{
 auto i = 1;
 auto& i_lvalref = i; 

 auto&& i_rvalref = i; // with auto it compiles :) Think How. Magic of auto. 
 
 auto&& i_rvalref_2 = std::move(i); //  compile time Convertion of an lvalue to rvalue

 auto&& i_rvalref_3 = 1; 
 
 auto&& i_rvalref_4 = i_lvalref; // with auto it compiles :) Think How. Magic of auto.

 std::cout << "i = " << i <<std::endl
	   << "i_lvalref = " << i_lvalref << std::endl 
	   << "i_rvalref_2 = " << i_rvalref_2 << std::endl
	   << "i_rvalref_3 = " << i_rvalref_3 << std::endl; 

 return 0;
}
