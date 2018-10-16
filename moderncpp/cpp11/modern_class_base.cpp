#include<iostream>
#include<vector>
#include<string>

// default
// delete
// final
// member init
// initialization_list ctor.
// move copy constructor
// move assignment operator 

struct modern_class final // can not be derived 
{


    modern_class() = default; 
    modern_class(const modern_class& other) = default; // const lvalue ref param
    modern_class& operator=(const modern_class& other) = default; // const lvalue ref param
    modern_class(modern_class&& other) = default; // non const rvalue ref param, &&
    modern_class& operator=(modern_class&& other) = default; // non const rvalue ref param, &&

     void demo()  
     {
        //std::string << "its modern class demo." << std::endl;
        std::cout << "its modern class demo." << __FUNCTION__ << std::endl;
        for(auto elem : vec) 
        {
          std::cout << "elem : " << elem << std::endl;
        }
     }

     virtual void demo_vir() final // can not be overidded in any of the derived class if any.  however this class can not be derived. it is declared final in struct modern_class final 
     {
        std::cout << "its modern class demo." << __FUNCTION__ << std::endl;
     }
    
    int i = 0;
    std::vector<int> vec = {1,2,3,4,5};
};

int main()
{
    
    modern_class mc;
    mc.demo();
    mc.demo_vir();
    return 0;
}
