#include<iostream>
#include<mutex>
#include<memory>

using namespace std;

struct singleton_t
{
    // static unique_ptr<singleton_t> get_instance()
    static singleton_t& get_instance()
    {
        // std::call_once(m_once, []{ m_obj = make_unique<singleton_t>(); });
        std::call_once(m_once, []{ m_obj.reset(new singleton_t()) ;  });
        // std::call_once(m_once, []{ m_obj.reset(new singleton_t()) ;  });
        return *m_obj.get();
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
    ~singleton_t() 
    {
        std::cout << "dtor singleton." << std::endl;
    }
    private:

    singleton_t() = default;

    static unique_ptr<singleton_t>  m_obj;
    static std::once_flag m_once;

    // Some real data in real lifea
    std::string m_name = "Singleton";
};

std::once_flag singleton_t::m_once;
unique_ptr<singleton_t> singleton_t::m_obj;

int main()
{
    auto& s = singleton_t::get_instance();
    // singleton_t::get_instance()->name();
    // s->name();

    return 0;
}


