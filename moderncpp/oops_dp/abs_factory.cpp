#include<iostream>
#include<memory>

using namespace std;


struct product_base 
{
    product_base() { cout << "ctor product_base." << endl; }
    virtual std::string name()  { return "product_base"; } 
    virtual ~product_base() { cout << "dtor product_base." << endl; }
};

struct product_1 final : public product_base 
{
    product_1() { cout << "ctor product_1." << endl; }
    std::string name() override { return "product_1"; } 
    ~product_1() { cout << "dtor product_1." << endl; }
};

struct product_2 final : public product_base 
{
    product_2() { cout << "ctor product_2." << endl; }
    std::string name() override { return "product_2"; } 
    ~product_2() { cout << "dtor product_2." << endl; }
};
struct abs_factory 
{
    
    abs_factory() { cout << "ctor abs_factory." << endl; }
    virtual unique_ptr<product_base> make() = 0;
    virtual std::string name() { return "abs_factory."; }
    virtual ~abs_factory() { cout << "dtor abs_factory. " << endl; }

};

struct factory_1 final : public abs_factory 
{
    factory_1() { cout << "ctor factory_1." << endl; }
    unique_ptr<product_base> make() override { return make_unique<product_1>(); }  
    std::string name() override { return "factory_1."; }
    ~factory_1() { cout << "dtor factory_1." << endl; }
};

struct factory_2 final : public abs_factory 
{
    factory_2() { cout << "ctor factory_2." << endl; }
    unique_ptr<product_base> make() override { return make_unique<product_2>(); }  
    std::string name() override { return "factory_2."; }
    ~factory_2() { cout << "dtor factory_2." << endl; }
};

int main()
{
   
    unique_ptr<abs_factory> fb;
    fb = make_unique<factory_1>();

    auto p = fb->make();
    p->name();


    return 0;
}
