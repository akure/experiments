#include<iostream>

template<typename T>
void print_list(const std::initializer_list<T>& l ) 
{

   std::cout << "Print a New List : " << std::endl;
    for (auto& e : l) 
    { 
      std::cout << e << std::endl;
    }
  
}


int main()
{
  
auto l = { 'A', 'B', 'C', 'D' };

// Pre C++11 syntax of calling template function
print_list<char>(l); 
print_list<int>({ 11, 22, 33 }); 

// New syntax of calling template function
print_list(l); 
print_list({ 11, 22, 33 }); 
// print_list({}); 

}

