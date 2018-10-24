#include<iostream>
#include<memory>


// simple visitor and host
struct host;

struct visitor
{
    
    visitor() { std::cout << "ctor visitor" << std::endl; }
    virtual ~visitor() { std::cout << "dtor visitor" << std::endl;  }

    void visit(host * h);

};

struct host 
{
    host() { std::cout << "ctor host." << std::endl; }
    ~host() { std::cout << "dtor host." << std::endl; }

    void accept(visitor * v)
    {
        
        std::cout << "host::accept -> accepting a visitor. " << std::endl;
        v->visit(this);

    }

    void check_my_place()
    {
        std::cout <<"I am host. It is my place. Did you  like it? " << std::endl;
    }

};

void visitor::visit(host * h)
{
    std::cout << "visitor::vist -> Going to visit host. " << std::endl;
    h->check_my_place();
}

int main()
{
    
    visitor v;
    host h;

    h.accept(&v);


}
