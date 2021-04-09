
/*
In C++ 11 : 
About • FAQ • Blog • Terms of Use • Contact Us • GDB Tutorial • Credits • Privacy
© 2016 - 2021 GDB Online
       Language 
C++
  
main.cpp
  
  
input
main.cpp:16:15: warning: throw will always call terminate() [-Wterminate]                                                                                                          
main.cpp:16:15: note: in C++11 destructors default to noexcept                                                                                                                     
 calling f                                                                                                                                                                         
 After Bomb 1                                                                                                                                                                      
operator new called                                                                                                                                                                
 ctor                                                                                                                                                                              
dtor                                                                                                                                                                               
terminate called after throwing an instance of 'char const*'                                                                                                                       
Aborted  


In C++ 98 : 
calling f 
 After Bomb 1 
operator new called
 ctor
dtor

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class Bomb { 
    // bad class throws exception from destructor
    int x;
public:
    Bomb() : x(0) 
    {  std::cout << " ctor" << std::endl; }
    
    ~Bomb() 
    { 
        
        std::cout << "dtor" << std::endl;

        throw "boom"; 
    }
    
    void * operator new(size_t n) throw()
    {
        printf("operator new called\n");
        return malloc(n);
    }
    
    void operator delete(void *p) throw()
    {
        printf("operator delete called\n"); // never gets here
        if (p != 0) free(p);
    }
    
};

void f() {
   //Bomb myBomb; // local variable that will blow up when torn down
    
    std::cout << " After Bomb 1 " << std::endl; 
    Bomb *pBomb = new Bomb();
    try {
        delete pBomb;
    } catch (...) {
        
       // code is not coming here
        printf("caught exception from destructor\n");
    }
    
    // program dies here: can't throw two exceptions
    // ("boom" and "no boom") at the same time.
    //throw "no boom"; // program dies here
}

int main(int argc, char **argv)
{
    
    try {
        std::cout <<" calling f " << std::endl;
        f();
    } 
    catch(...) {
    //catch (char *message) {
        
        std::cout << "catch 2 " << std::endl;
       // printf("f threw %s\n", message); // never gets here
    }
    
    
}
