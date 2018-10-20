#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int nextNum(vector<int> vec, int n1, int n2)
{ 
    int sum = 0;
   // n1 to n2 inclusive. 
   // n2+1 -> to make n2 inclusive
   for_each(vec.begin() + n1 , vec.begin() + n2 + 1, [&](int & i) { sum += i; });

   return sum;
}

/*
int nextNum1(vector<int> vec, int n1, int n2)
{
   int sum = 0;
   int idx = 0;
   for ( auto i : vec)
   {
        if (idx == n1 -1 || ( idx >= n1 -1 && idx <= n2-1))
        {
            sum = sum + i;
        }
        idx++;
   }

   return sum;
}

*/
int main()
{

  vector<int> vec = { 10, 20, 30, 40, 50, 60 };
  // cout << nextNum(vec, 0, 5) << std::endl;;
  cout << nextNum(vec, 2, 5) << std::endl;;
  cout << nextNum1(vec, 2, 5) << std::endl;;
  cout << nextNum1(vec, 1, 2) << std::endl;;
  cout << nextNum(vec, 1, 2) << std::endl;;
  return 0;
}
