#include<iostream>
#include<string>
#include<memory>

struct product_base 
{
    product_base() { std::cout << "product_base ctor" << std::endl; }
    virtual std::string  name() 
    { return "product_base"; } 

    virtual ~product_base() { std::cout << "product_base dtor" << std::endl; }
};

struct product_1 final : public product_base
{
    product_1() { std::cout << "product_1 ctor" << std::endl; }
    std::string name() override 
    {
        return "product_1";
    }
    virtual ~product_1() { std::cout << "product_1 dtor" << std::endl; }
};

struct product_2 final : public product_base
{

    product_2() { std::cout << "product_2 ctor" << std::endl; }
    std::string name() override 
    {
        return "product_2";
    }
    virtual ~product_2() { std::cout << "product_2 dtor" << std::endl; }
};

enum class product_type { P1, P2 };

struct factory_method_t
{
    static std::unique_ptr<product_base> make(product_type t)
    {
        if (t == product_type::P1)
        {
            return std::move(std::make_unique<product_1>());      
        }
        else if (t == product_type::P2)
        {
            return std::move(std::make_unique<product_2>());      
        }
    }
};


int main()
{
    
    std::unique_ptr<product_base> p;
    p = factory_method_t::make(product_type::P1);
    std::cout << p->name() << std::endl;
    p = factory_method_t::make(product_type::P2);
    std::cout << p->name() << std::endl;

    /* output :
       product_base ctor
       product_1 ctor
       product_1
       product_base ctor
       product_2 ctor
       product_1 dtor
       base dtor
       product_2
       product_2 dtor
       base dtor

     */
    return 0;
}
