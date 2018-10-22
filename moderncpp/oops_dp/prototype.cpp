#include<iostream>

using namespace std;

struct product_prototype_base
{
    product_prototype_base() { std::cout << "ctor product_prototype_base." << std::endl; }
    virtual product_prototype_base * clone() = 0;
    virtual void name() { std::cout << "product_prototype_base." << std::endl; } 
    virtual ~product_prototype_base() { std::cout << "dtor product_prototype_base." << std::endl; }
};

struct prototype_1 final : public product_prototype_base
{
   prototype_1() 
   {
        std::cout << "ctor prototype_1." << std::endl;
   }
   ~prototype_1() 
   {
        std::cout << "dtor prototype_1." << std::endl;
   }
   product_prototype_base * clone() { return new prototype_1(); }  
   virtual void name() { std::cout << "protoype_1" << std::endl; } 
};

struct prototype_2 final : public product_prototype_base
{
    prototype_2() 
    {
        std::cout << "ctor prototype_2." << std::endl;
    }
    ~prototype_2() 
    {
        std::cout << "dtor prototype_2." << std::endl;
    }

   product_prototype_base * clone() { return new prototype_2(); }  
   virtual void name() { std::cout << "prototype_2" << std::endl; } 
};


struct prototype_factory
{
    prototype_factory() 
    {
        std::cout << "ctot prototype_factory." << std::endl;
        p1 = new prototype_1();
        p2 = new prototype_2();
    }
    product_prototype_base * clone(product_prototype_base * p)
    {
        return p->clone();
    }

    ~prototype_factory()
    {
        std::cout << "dtot prototype_factory." << std::endl;
        delete p1;
        delete p2;
    }
    product_prototype_base * p1;
    product_prototype_base * p2;
};
int main()
{
    prototype_factory f;

    
    product_prototype_base * p = f.clone(f.p1);
    p->name();

    delete p;
    return 0;
}
