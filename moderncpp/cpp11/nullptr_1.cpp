#include<iostream>

// nullptr is a typesafe nullptr.  
// It is backword compatible to 0 and NULL
struct test_t 
{

};

void null_testing(test_t * ptr)
{
   std::cout << "pointer version" << std::endl;
}

void null_testing(int i)
{
   std::cout << "int  version" << std::endl;
} 

int main()
{
    test_t *p = nullptr;

    std::cout << "calling null_testing with nullptr" << std::endl;
    null_testing(nullptr);

    std::cout << "calling null_testing with int 0" << std::endl;
    null_testing(0);
   //  null_testing(NULL); 

    std::cout << "---------" << std::endl;

    if (nullptr == 0)  std::cout<< "nullptr == 0" << std::endl; 
    else  std::cout<< "nullptr != 0" << std::endl; 
    
    if (nullptr == NULL)  std::cout<< "nullptr == NULL" << std::endl; 
    else  std::cout<< "nullptr !== NULL" << std::endl; 
    

    return 0;
}
