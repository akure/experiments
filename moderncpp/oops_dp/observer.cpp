#include<iostream>
#include<memory>
#include<functional>
#include<vector>
using namespace std;

struct observer 
{
    observer() { std::cout << "ctor observer." << std::endl; } 
    virtual void notify() = 0;
    virtual ~observer() { std::cout << "dtor observer." << std::endl; } 
};

struct observer_1 final : public observer 
{
    observer_1() { std::cout << "ctor observer_1." << std::endl; } 
    virtual ~observer_1() { std::cout << "dtor observer_1." << std::endl; } 
    
    public :
    virtual void notify() override
    {
        std::cout <<"observer_1 notify." << std::endl;    
    }
};

struct subject 
{
    public: 
    void register_observer(unique_ptr<observer> o)
    {
        observers.push_back(std::move(o));
    }

    void notify() // To observer
    {
        for (auto && o : observers)
        {
            o->notify();
        }
    }
    private:
    std::vector<unique_ptr<observer>> observers;
    // std::vector<std::reference_wrapper<observer>> observers;
};

int main()
{
    subject sub;
    unique_ptr<observer> o(new observer_1()); 
    
    sub.register_observer(std::move(o));
    sub.notify();
    return 0;
}
