#include <iostream>

// Base is a pure abstract class., Still is has a vptr
class Base {
public:
      void foo()  ;
     int data;
};

// Removing the abstractness of foo
// But Der1 is still an abstract class
class Der1 : public   Base {
public: 
   void foo() {};
   // virtual void bas() {} ;
};
 
class Der2 :   public   Base {
public: 
 void foo() {};
};

class Der3 :   public   Base {
public: 
 void foo() {};
};


class Join : public Der1 , public Der2, public Der3 {
public:
 void foo() {};
  // ...
};


int main()
{
 
 // Think , how compiler will layout the Join object
 std::cout <<  "size of b :" << sizeof(Base) << std::endl;
 std::cout <<  "size of d 1 : " << sizeof(Der1) << std::endl;
 std::cout <<  "size of d 2 : " << sizeof(Der2) << std::endl;
 std::cout <<  "size of j : " << sizeof(Join) << std::endl;
  
  std::cout << "size of ptr " << sizeof(void*) << std::endl;

 std::cout << "End" << std::endl;

 
}
