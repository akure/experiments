#include<iostream>

template<typename T>
void fun_1(T param)
{

  std::cout << __PRETTY_FUNCTION__ << std::endl;

}

template<typename T>
void fun_2(T & param)
{

  std::cout << __PRETTY_FUNCTION__ << std::endl;

}

template<typename T>
void fun_3(T && param)
{

  std::cout << __PRETTY_FUNCTION__ << std::endl;

}

template<typename T>
void fun_4(T * param)
{

  std::cout << __PRETTY_FUNCTION__ << std::endl;

}

int main()
{
  auto i = 1;
  auto j =  &i;
  auto k = &j;
  auto f1 = [](int i) { std::cout << "Test lambda closure 1 : i " << i << std::endl; };
  int && i_refref = 10;
  // int && i2_refref = i; // Can not bind int l value to int &&
  // int && i3_refref = j; // invalid conversion from int * to int
  // int && i4_refref = ( int && ) j;  Compile but dangerous
  // int && i_refref5 = i_refref; // can not bind int l value to int &&


  auto const ci = 1;
  auto const cj =  &i;
  auto const ck = &j;
  auto const cf1 = [](int i) { std::cout << "Test lambda closure 1 : i " << i << std::endl; };

  auto const * pci = &i;
  auto const * pcj =  &cj;
  auto const * pck = &ck;
  // auto const * pcf1 = [](int i) { std::cout << "Test lambda closure 1 : i " << i << std::endl; }; // unable to deduce const auto * from lambda expression.
  // auto const * pcf1 = cf1; // unable to deduce const auto *
  // auto * pcf1 = cf1; // unable to deduce auto *

  fun_1(i);
  fun_1(j);
  fun_1(k);
  fun_1(f1);
  f1(10);
  fun_1(i_refref);
  fun_1(10);
  fun_1([i](){std::cout << i << std::endl;});



  fun_1(ci);
  fun_1(cj);
  fun_1(ck);
  fun_1(cf1);

  fun_1(pci); // pointed to const ness preserved
  fun_1(pcj); // pointed to const ness preserved
  fun_1(pck); // pointed to const ness preserved
  std::cout << "+++++++++++++++++++++++++++" << std::endl;

  fun_2(i);
  fun_2(j);
  fun_2(k);
  fun_2(f1);

  fun_2(i_refref);
  // fun_2(10); // error : initialization of non-const ref of type 'int&' from an rvalue
  // fun_2([i](){std::cout << i << std::endl;});

  fun_2(ci);
  fun_2(cj);
  fun_2(ck);
  fun_2(cf1);

  fun_2(pci); // pointed to const ness preserved
  fun_2(pcj); // pointed to const ness preserved
  fun_2(pck); // pointed to const ness preserved

  std::cout << "+++++++++++++++++++++++++++" << std::endl;

  fun_3(i);
  fun_3(j);
  fun_3(k);
  fun_3(f1);

  fun_3(i_refref);
  fun_3(10);
  fun_3([i](){std::cout << i << std::endl;});

  fun_3(ci);
  fun_3(cj);
  fun_3(ck);
  fun_3(cf1);

  fun_3(pci); // pointed to const ness preserved
  fun_3(pcj); // pointed to const ness preserved
  fun_3(pck); // pointed to const ness preserved

  std::cout << "+++++++++++++++++++++++++++" << std::endl;

  fun_4(&i);
  fun_4(j);
  fun_4(k);
  //fun_4(f1);

  //fun_4(i_refref);
  //fun_4(10);
  //fun_4([i](){std::cout << i << std::endl;});

  fun_4(&ci);
  fun_4(cj);
  fun_4(ck);
  // fun_4(cf1);

  fun_4(pci); // pointed to const ness preserved
  fun_4(pcj); // pointed to const ness preserved
  fun_4(pck); // pointed to const ness preserved

  return 0;
}
