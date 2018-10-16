#include<iostream>

constexpr int add(int x, int y, int z)
{
    return x + y + z;
}

constexpr int add_if_positive(int x, int y, int z)
{
    if(x>0 && y>0 && z>0)  return x + y + z;
    
    return 0;
}

int main()
{
   
    constexpr auto sum = add(1,2,3);
    static_assert(sum == 6, "sum!=6");   
    // static_assert(sum != 6, "sum==6");   // this will fail. compile time

    
    constexpr auto sum_p = add_if_positive(1,2,-4);
    // static_assert(sum_p > 0, "inputs are not positive"); // this will fail. compile time
    
    constexpr auto sum_p2 = add_if_positive(1,2,4);
    static_assert(sum_p2 == 0, "inputs are positive. sum done"); // this will fail. compile time


    
    return 0;
}
