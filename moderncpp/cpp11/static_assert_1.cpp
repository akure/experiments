#include<iostream>

int main()
{
 

   // Compile time expressions 
   constexpr int x = 10;
   constexpr int y = 10;

   //  Compile time assertion
   static_assert(x==y , "asert failed. x!=y"); // First arg is expression. Second arg is string for printing. 
 

   // This line will not compile and give error.
   static_assert(x!=y , "asert failed. x==y"); // First arg is expression. Second arg is string for printing. 
   return 0;
}
