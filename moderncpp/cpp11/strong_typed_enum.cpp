#include<iostream>

enum class Person { Students = 0 , Teacher= 1 , Professor = 2 , Chairman = 3 , Director= 4, SecurityGuard=5 } ;

int main ()
{


    Person s = Person::Students;
    // Person s =Students; // Compiler error. no direct access to strongly typed enums elements
    if(s == Person::Students) std::cout << "Its students. " << std::endl;
    
    
    // if(s == 1) std::cout << "Its students. " << std::endl; // Compiler error. No implicit conversion.
    // std::cout << Person::Student << std::endl;
    return 0;
}
