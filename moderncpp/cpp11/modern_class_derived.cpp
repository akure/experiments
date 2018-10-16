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

struct modern_class // can not be derived 
{


    modern_class() = default; 
    modern_class(const modern_class& other) = default; // const lvalue ref param
    modern_class& operator=(const modern_class& other) = default; // const lvalue ref param
    modern_class(modern_class&& other) = default; // non const rvalue ref param, &&
    modern_class& operator=(modern_class&& other) = default; // non const rvalue ref param, &&

     void demo()  
     {
        //std::string << "its modern class demo." << std::endl;
        std::cout << "modern_class " << __FUNCTION__ << std::endl;
        for(auto elem : vec) 
        {
          std::cout << "elem : " << elem << std::endl;
        }
     }

     virtual void demo_vir() final // can not be overidded in any of the derived class if any.  however this class can not be derived. it is declared final in struct modern_class final 
     {
        std::cout << "modern_class : " << __FUNCTION__ << std::endl;
     }

     virtual void demo_vir_1() 
     {
        std::cout << "modern_class : " << __FUNCTION__ << std::endl;
     }
    
    int i = 0;
    std::vector<int> vec = {1,2,3,4,5};
}; 

struct modern_class_derived final : public modern_class 
{
    modern_class_derived() = default; 
    modern_class_derived(const modern_class_derived& other) = default; // const lvalue ref param
    modern_class_derived& operator=(const modern_class_derived& other) = default; // const lvalue ref param
    modern_class_derived(modern_class_derived&& other) = default; // non const rvalue ref param, &&
    modern_class_derived& operator=(modern_class_derived&& other) = default; // non const rvalue ref param, &&

    void demo_vir_1() override // override -> this function must be present in base class. Otherwise compile time error. However this keyword is optional. 
    {
        std::cout << "modern_class_derived: " << __FUNCTION__ << std::endl;
    }

};

int main()
{
    
    modern_class_derived mcd;
    mcd.demo();
    mcd.demo_vir();
    mcd.demo_vir_1();
    return 0;
}
