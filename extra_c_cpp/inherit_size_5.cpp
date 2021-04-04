#include <iostream>

// Base is a pure abstract class., Still is has a vptr
// 8 + 8
class Base {
public:
      virtual void foo() {}  ;
      int64_t data;
};

// 16 + 8
// Removing the abstractness of foo
// But Der1 is still an abstract class
class Der1 : virtual public   Base {
public: 
   
};
 
 // 16 + 8
class Der2 :   virtual public   Base {
public: 
 };


// 16 + 8
class Der3 :  virtual  public   Base {
public: 
 };

// 16 + 8 + 8 + 8
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
 std::cout <<  "size of d 3 : " << sizeof(Der3) << std::endl;

 std::cout <<  "size of j : " << sizeof(Join) << std::endl;
  
  std::cout << "size of ptr " << sizeof(void*) << std::endl;

 std::cout << "End" << std::endl;

 
}
