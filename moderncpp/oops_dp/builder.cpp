#include<iostream>
#include<memory>

using namespace std;


struct product_base;
using product_ptr_t = std::unique_ptr<product_base>;
struct part_1_t
{
    int id = 0;
};
struct part_2_t
{
    int id = 0;
};
struct part_3_t
{
    int id = 0;
};

struct product_base
{
    product_base() { std::cout << "ctor product_base." << std::endl; } 
    virtual std::string name() { std::cout << "product_base." << std::endl; } 
    virtual void part_details() {  std::cout << part_1->id << " " << part_2->id << " " << part_3->id << std::endl; } 
    virtual ~product_base() { std::cout << "dtor product_base." << std::endl; } 
    unique_ptr<part_1_t> part_1;
    unique_ptr<part_2_t> part_2;
    unique_ptr<part_3_t> part_3;
    string model_name;
};

struct product_model_1  final : public product_base 
{
   product_model_1() { std::cout << "ctor product_model_1" << std::endl; }    
   std::string name() override { std::cout << "product_model_1" << std::endl; }    
   virtual ~product_model_1() { std::cout << "dtor product_model_1" << std::endl; }    
};

struct product_model_2  final : public product_base 
{
   product_model_2() { std::cout << "ctor product_model_2" << std::endl; }    
   std::string name() override { std::cout << "product_model_2" << std::endl; }    
   virtual ~product_model_2() { std::cout << "dtor product_model_2" << std::endl; }    
};
struct builder_base
{
    builder_base() { cout << "ctor builder_base." << endl; } 
    virtual ~builder_base() { cout << "dtor builder_base." << endl; }
    virtual void build_part_1() = 0;
    virtual void build_part_2() = 0;
    virtual void build_part_3() = 0;
    void build() 
    {
        build_part_1();
        build_part_2();
        build_part_3();
    }
    product_base * get() { return prod.get(); }
    protected: 
    void build_part_1_i(unique_ptr<part_1_t> p) 
    { 
        // std::cout << "build_part_1_i enter" << std::endl;
        prod->part_1 = std::move(p) ;
        // std::cout << "build_part_1_i exiting" << std::endl;
    }
    void build_part_2_i(unique_ptr<part_2_t> p) { prod->part_2 = std::move(p) ; }
    void build_part_3_i(unique_ptr<part_3_t> p) { prod->part_3 = std::move(p) ; }
    product_ptr_t prod;
}; 

struct builder_1 final : public builder_base 
{
    builder_1() 
    { 
        cout << "ctor builder_1." << endl; 
        prod = make_unique<product_model_1>();
    } 
    virtual ~builder_1() { cout << "dtor builder_1." << endl; }
    void build_part_1() override {  
        // std::cout << "build_part_1" << std::endl;
        unique_ptr<part_1_t> p;
        p = make_unique<part_1_t>();
        p->id = 10;

        // std::cout << "build_part_1 bfor" << std::endl;
        builder_base::build_part_1_i(std::move(p));
        // std::cout << "build_part_1 after" << std::endl;
    }
    void build_part_2() override {  
        std::cout << "build_part_2" << std::endl;
        unique_ptr<part_2_t> p;
        p = make_unique<part_2_t>();
        p->id = 10;
        builder_base::build_part_2_i(std::move(p));
    }
    void build_part_3() override {  
        std::cout << "build_part_3" << std::endl;
        unique_ptr<part_3_t> p;
        p = make_unique<part_3_t>();
        p->id = 10;
        builder_base::build_part_3_i(std::move(p));
    }
};

struct builder_2 final : public builder_base 
{
};



int main()
{
    std::unique_ptr<builder_base> b;
    b = make_unique<builder_1>();
    b->build(); 
    b->get()->part_details();
    return 0;
}
