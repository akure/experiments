#include<iostream>
#include<type_traits>
#include<vector>

int main()
{
       
    std::vector<int> vi { 1,2,3,4,5,6,7,8,9};
    std::cout << std::boolalpha << std::endl; 
    // Range based for loop. 
    // Get into the elements of range 
    // Access elements as per the type specified in left side .
    // By by copy,  lvalue ref, by rvalue ref(special case) 
    for(auto i : vi)
    {
        std::cout << std::is_same<decltype(i), int>::value << std::endl;
    }


    for(auto& i : vi)
    {
        std::cout << std::is_same<decltype(i), int&>::value << std::endl;
    }


    // Special Case: 
    // Look how && deduced to & 
    for(auto&& i : vi)
    {
        std::cout << std::is_same<decltype(i), int&>::value << std::endl;
    }
    return 0;
}
