#include<iostream>

void withdraw_money() 
{
   std::cout << "Withdrawing Money... " << std::endl;
}

void some_error()
{
    std::cout << "Some error..." << std::endl;
}

template<typename T> // string, int
decltype(auto) money(T amount)
{ 
    std::cout << "Amount entered is : " << amount << std::endl;
    std::cout << "Withdrawing..." << std::endl;
    return amount;
}


template<typename T>
decltype(auto) sum(T a, T b) // c++14,17
//auto sum(T a, T b) // does not work in c++11. Work in c++14/17
{
    auto r = a + b;
    return r;
}

int main()
{
    ///// decltype Demo 1
    auto withdraw_or_error = [](int flag) { flag ? withdraw_money() :  some_error();  }; 
    decltype(withdraw_or_error) bank_atm_withdraw = withdraw_or_error; 
    bank_atm_withdraw(true);

    ////////////////////////////////
    ///// decltype Demo 2 
    auto result_1 = money(1000);  // Return int
    auto result_2 = money("5000"); // Return std::string

       
    ////////////////////////////////
    ///// decltype Demo 3
   
     auto result_3 = sum(10,20);   
     std::cout << "result_3 (sum) " << result_3 << std::endl;
    return 0;
}


