#include <iostream>

// Base is a pure abstract class
class Base {
public:
     //int data;
};

// Removing the abstractness of foo
// But Der1 is still an abstract class
class Der1 : public virtual Base {
public: 
};
 
class Der2 :   public virtual Base {
public: 
};

// I think that, the compiler will create two pointers in join object. 
// One is to point to the Der1 object and one for Der2. So its size is coming as 16
class Join : public Der1 , public Der2 {
public:
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
