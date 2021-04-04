#include <iostream>

class Base {
public:
  // ...
public:
  int data_;
};

class Der1 : public Base 
{ 
    /*...*/ 
    
};

class Der2 : public Base 
{ 
    /*...*/ 
    
};

class Join : public Der1, public Der2 {
public:
  void method()
  {
     // data_ = 1;  // Bad: this is ambiguous; see below
  }
};
/*
Error :
error: 'Base' is an ambiguous base of 'Join'
*/
int main()
{
   Join* j = new Join();

   // D1 only knows about the j1
   Der1 * d1 = j;

  
   // Here the base is dealing with the d1. 
   // Here Base only know about d1.
   Base * b = d1;    
   b->data_ = 1;

   std::cout << " d1 data_ " << d1->data_ << std::endl;
   std::cout << " b data_ " << b->data_ << std::endl;

  // Base * b = j;   // Bad: this is ambiguous;  
   
}
