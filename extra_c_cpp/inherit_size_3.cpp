#include <iostream>

// Base is a pure abstract class
class Base {
public:
    virtual void foo() = 0;
     //int data;
};

// Removing the abstractness of foo
// But Der1 is still an abstract class
class Der1 : public virtual Base {
public: 
   void foo() {};
};
 
class Der2 :   public virtual Base {
public: 
 void foo() {};
};

class Der3 :   public virtual Base {
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


 std::cout << "End" << std::endl;

 
}
