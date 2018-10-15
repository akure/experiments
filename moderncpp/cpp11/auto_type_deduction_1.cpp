#include<iostream>
#include<type_traits>
#include<typeinfo>

using namespace std;

template<typename U, typename V>
void is_same_type(U & u, V & v)
{

  // return is_same<U, remove_reference<decltype(u)>::type>::value;
  std::cout << boolalpha << std::endl;
  std::cout << "Arg1:" << u << "," << "Arg2:" << v << " , Result of is_same<U, V>::value ,  " << is_same<U, V>::value << std::endl;
}


int main()
{
  
  // Case #1 
  // Simple Type with no qualifiers
  auto xi = 10;
  auto xd = 10.900;
  auto xs = "10"s;
  auto xs2 = "10"; // Suspicious, const char *
  auto xc = '1';

  int yi = 10;
  double  yd = 10.900;
  std::string ys = "10";
  char ychararray[3] = "10";
  const char * ys2 = ychararray;
  char yc = '1';
  
  std::cout<< " Type Checking..." << std::endl;
  is_same_type( yi, xi);
  is_same_type( yd, xd);
  is_same_type( ys, xs);
  is_same_type( ys2, xs2); // suspicious case
  is_same_type( yc, xc);
  
 
  // Special case xs2, const char * 
  std::cout<< is_same<char * , decltype(xs2)>::value << std::endl;
  std::cout<< is_same<const char * , decltype(xs2)>::value << std::endl;
  std::cout<< is_same<std::string, decltype(xs2)>::value << std::endl;
  std::cout<< is_same<std::string & , decltype(xs2)>::value << std::endl;
  
  std::cout << "------------------------------------------" << std::endl;
  // Case #2 
  // Simple Type with qualifiers

  
  auto& x1 = xi;

  auto&& x2 = xi; // x2 will become int& after auto type deduction. Special Case.
  
  const auto x3 = xi; // x2 -> const int
  const auto& x4 = xi; // x2 -> const int & 
  // const auto&& x5 = xi; // Error 
  
  
  std::cout << is_same< decltype(x1), int & >::value << std::endl; // true
  std::cout << is_same< decltype(x2), int && >::value << std::endl; // false
  std::cout << is_same< decltype(x2), int & >::value << std::endl; // true 
  std::cout << is_same< decltype(x3), const int >::value << std::endl; // true
  std::cout << is_same< decltype(x4), const int & >::value << std::endl; // true

} 
  

