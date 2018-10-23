#include<iostream>
#include<memory>
using namespace std;

struct strategy_base
{
    
    strategy_base() { std::cout << "ctor strategy_base." << std::endl; }
    virtual void do_something_crazy() = 0;
    virtual ~strategy_base() { std::cout << "dtor strategy_base." << std::endl; }

};


struct strategy_1 final : public strategy_base
{
            
    strategy_1() { std::cout << "ctor strategy_1." << std::endl; }
    void do_something_crazy() override
    {
        std::cout << "strategy_1 : crazy work." << std::endl;
    }
    virtual ~strategy_1() { std::cout << "dtor strategy_1." << std::endl; }
};

struct strategy_2 final : public strategy_base
{
    strategy_2() { std::cout << "ctor strategy_2." << std::endl; }
    void do_something_crazy() override
    {
        std::cout << "strategy_2 : crazy work." << std::endl;
    }
    virtual ~strategy_2() { std::cout << "dtor strategy_2." << std::endl; }
};


struct user
{
    void run_stg()
    {
        s->do_something_crazy();
    }   
    void set_stg(unique_ptr<strategy_base> s1)
    {
        s = std::move(s1);
    }
    unique_ptr<strategy_base> s;
};

int main()
{
    user u;
    unique_ptr<strategy_base> sp( new strategy_1()) ;
    u.set_stg(std::move(sp));
    u.run_stg();
    unique_ptr<strategy_base> sp1( new strategy_2()) ;
    u.set_stg(std::move(sp1));
    u.run_stg();
    return 0;
}
