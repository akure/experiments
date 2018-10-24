#include<iostream>
#include<memory>

struct chain_of_responsibility
{
  
    chain_of_responsibility() 
    {
        std::cout << "ctor base." << std::endl;
    }

    virtual ~chain_of_responsibility() 
    {
        std::cout << "dtor base." << std::endl;
        if (next) delete next;
    }

    virtual void do_something_here() = 0;

    void handover_responsibility()
    {
        if(next) next->do_something_here();
    }

    void set_next(chain_of_responsibility * n)
    {
        next = n;
    }


    chain_of_responsibility * next;  
  
};

struct ceo final : public chain_of_responsibility
{
    ceo() { std::cout <<"ctor ceo." << std::endl; }
    ~ceo() { std::cout <<"dtor ceo." << std::endl; }
   
    
    void do_something_here() override
    {
        std::cout << "CEO : do something here | Mr. CEO Created a Peoject." << std::endl;
        handover_responsibility();
    }

};
struct product_manager final : public chain_of_responsibility
{
    product_manager() { std::cout <<"ctor product_manager." << std::endl; } 
    ~product_manager() { std::cout <<"dtor product_manager." << std::endl; }
   
    
    void do_something_here() override
    {
        std::cout << "Mr PRoduct Manager creaded project plan.." << std::endl;
        handover_responsibility();
    }
};

int main()
{
    chain_of_responsibility * _ceo;
    chain_of_responsibility * _pm;;
    _ceo = new ceo();
    _pm = new product_manager();
    _ceo->set_next(_pm);
    
    _ceo->do_something_here();

    delete _ceo;

    return 0;
    
}
