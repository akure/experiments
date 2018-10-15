#include<iostream>


template <typename... T>
struct size_test {
  constexpr static int value = sizeof...(T);
};

int main()
{

 std::cout << "size_test<>::value = " << size_test<>::value << std::endl;
 std::cout << "size_test<int>::value = " << size_test<int>::value << std::endl;
 std::cout << "size_test<int, char>::value = " << size_test<int, char>::value << std::endl;
 std::cout << "size_test<int, char, float >::value = " << size_test<int, char, float>::value << std::endl;

 return 0;
}
