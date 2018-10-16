#include<iostream>
#include <stdlib.h>

#include<string>

// overload operator "" 
// const char *  to double conversion.
// literarl  operator overloading. quote-quote
double operator "" _stod(const char * s, size_t)
{
    return std::stod(s); 
}

double operator "" _atof(const char * s, size_t)
{
    return atof(s);
}
double operator "" _stoi(const char * s, size_t)
{
    return std::stoi(s); 
}
int main()
{
    int i = "111"_stoi;
    double d = "123.123"_stod;
    double d1 = "123.123"_atof;

    std::cout << "i : " << i << ", d : " << d << ", d1 " << d1  << std::endl;
    return 0;
}
