#include<iostream>
#include<memory>
#include <functional>
using namespace std;

struct singleton_t final
{

    static singleton_t * get_instance()
    {
        static singleton_t obj;
        return &obj;
    }
    
    void init() 
    { 
        // Real life situation. Some specific data must be initialized 
    } 

    void name() {  std::cout << m_name << endl; } 
    singleton_t(const singleton_t &) = delete;
    singleton_t& operator=(const singleton_t &) = delete;
    singleton_t(singleton_t &&) = delete;
    singleton_t& operator=(const singleton_t &&) = delete;
    ~singleton() = default;

    private:

    singleton_t() = default;
    // Some real data in real lifea
    std::string m_name = "Singleton";
};

int main()
{
    std::function<singleton_t * () > s;
    s = singleton_t::get_instance;

    auto sing = singleton_t::get_instance;
    singleton_t *ptrs = singleton_t::get_instance();
    
    sing()->name();
    s()->name(); 
     
    singleton_t::get_instance()->name();

    ptrs->name();
    return 0;
}


