#include<iostream>
#include<typeinfo>
using namespace std;
//auto main() -> int // it works as well
int main() 
{
 
 // auto x1 = 10;	
 // auto x1 ='c';	
 // auto x1 = "testing"s; 
 
 // Try with different types in rhs
 // auto x1 = new int(0);	
 int &&x1 = 10;
 auto i = x1;
 auto& i_lvalref = i; 

 auto&& i_rvalref = i; // with auto it compiles :) Think How. Magic of auto. 
 
 auto&& i_rvalref_2 = std::move(i); //  compile time Convertion of an lvalue to rvalue

 auto&& i_rvalref_3 = 1; 
 
 auto&& i_rvalref_4 = i_lvalref; // with auto it compiles :) Think How. Magic of auto.

 std::cout << "i = " << i <<std::endl
	   << "i = " << i << "typeinfo = " << typeid(i).name() << std::endl 
	   << "x = " << x1 << "typeinfo = " << typeid(x1).name() << std::endl 
	   << "i_lvalref = " << i_lvalref << "typeinfo = " << typeid(i_lvalref).name() << std::endl 
	   << "i_rvalref = " << i_rvalref << "typeinf = " << typeid(i_rvalref).name() << std::endl 
	   << "i_rvalref_2 = " << i_rvalref_2 << "typeinfo = " << typeid(i_rvalref_2).name() << std::endl 
	   << "i_rvalref_3 = " << i_rvalref_3 << "typeinfo = " << typeid(i_rvalref_3).name() << std::endl 
	   << "i_rvalref_3 = " << i_rvalref_4 << "typeinfo = " << typeid(i_rvalref_4).name() << std::endl; 

 return 0;
}
