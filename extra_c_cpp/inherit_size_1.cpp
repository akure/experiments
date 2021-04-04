#include <iostream>

// Base is a pure abstract class
class Base {
public:
     //int data;
};

// Removing the abstractness of foo
// But Der1 is still an abstract class
class Der1 : public Base {
public: 
};
 
class Der2 :   public virtual Base {
public: 
};

 


int main()
{
 

  std::cout << "size of b :" << sizeof(Base) << std::endl;
  std::cout <<  "size of d 1 : " << sizeof(Der1) << std::endl;
  std::cout <<  "size of d 2 : " << sizeof(Der2) << std::endl;
   
  std::cout << "End" << std::endl;

 
}
