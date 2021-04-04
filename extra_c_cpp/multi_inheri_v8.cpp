#include <iostream>

// Base is a pure abstract class
class Base {
public:
  virtual void foo() = 0;
  virtual void bar() = 0;
};

// Removing the abstractness of foo
// But Der1 is still an abstract class
class Der1 : public virtual Base {
public:
  virtual void foo();     // Redecleared 
};

// Removing the abstractness of bar function. 
// But Der2 is still an abstract class 
class Der2 : public virtual Base {
public:
  virtual void bar() {  std::cout << "Der2::bar" << std::endl; } ; // Redecleared 
};


void Der1::foo()
{ 
    std::cout << " Der1::foo" << std::endl;
    bar();  
}
/*
void Der2::foo()
{ 
    std::cout << " Der1::foo" << std::endl;
    //bar();  
}
*/

class Join : public Der1, public Der2 {
public:
  // ...
};
int main()
{

  
  Join* p1 = new Join();
  Der1* p2 = p1;
  Base* p3 = p1;
  p1->foo();
  p2->foo();
  p3->foo();
  std::cout << "End" << std::endl;

 
}
