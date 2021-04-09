#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/* 
This program will have output.
 
output in c++98:    
calling f 
ctor
dtor
 
 output in c++11: 
main.cpp:16:15: note: in C++11 destructors default to noexcept                                                                                                                     
 calling f                                                                                                                                                                         
 ctor                                                                                                                                                                              
dtor                                                                                                                                                                               
terminate called after throwing an instance of 'char const*'                                                                                                                       
Aborted (core dumped)       


*/

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
    /*
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
    */
};

void f() {
    Bomb myBomb; // local variable that will blow up when torn down
    
    /*
    Bomb *pBomb = new Bomb();
    try {
        delete pBomb;
    } catch (...) {
        // Gets here but leaks storage.  Print output shows that
        // operator new was called but operator delete was not.
        printf("caught exception from destructor\n");
    }
    */
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
