class Base {
public:
  // ...
protected:
  int data_;
};

class Der1 : public Base { /*...*/ };
class Der2 : public Base { /*...*/ };

class Join : public Der1, public Der2 {
public:
  void method()
  {
     data_ = 1;  // Bad: this is ambiguous; see below
  }
};
/*
Error :
error: 'Base' is an ambiguous base of 'Join'
*/
int main()
{
  // Join* j = new Join();
  // Base & b = *j;   // Bad: this is ambiguous;  
   
}
