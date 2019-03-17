#include<iostream>
#include<typeinfo>


int main()
{
  int i = 0;
  int * pi = &i;
  int ** ppi = &pi;

  std::cout << i << *pi << **ppi << std::endl;
  std::cout << typeid(i).name() << std::endl;

  std::cout << typeid(pi).name() << std::endl;
  std::cout << typeid(ppi).name() << std::endl;
  std::cout << std::boolalpha;
  std::cout << std::is_same<int, std::int32_t>::value << '\n';

  int * pj = & i;
  auto pj2 = &pj;
  auto && pj3 = pj2;
  int ** & pj4 = pj2;
  std::cout << std::is_same<decltype(pj2), int **>::value << '\n';
  std::cout << std::is_same<decltype(pj3), int ** &>::value << '\n';
  std::cout << std::is_same<decltype(pj3), decltype(pj4)>::value << '\n';

  std::cout << **pj2 << std::endl;
  std::cout << **pj3 << std::endl;
  std::cout << **pj4 << std::endl;

  std::cout << &(**pj2) << std::endl;
  std::cout << &(**pj3) << std::endl;
  std::cout << &(**pj4) << std::endl;
  return 0;
}
