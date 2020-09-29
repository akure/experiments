#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    std::array<int, 6> starts = { 1, 3, 0, 5, 8, 5}; 
    std::array<int, 6> ends = {2, 4, 6, 7, 9, 9};

	std::cout << std::boolalpha 
		<< std::is_sorted(ends.begin(), ends.end()) 
		<< std::endl;
    
    std::cout << std::boolalpha 
		<< std::is_sorted(std::begin(starts), std::end(starts)) 
		<< std::endl;

       
    int total_activities = sizeof(starts)/ sizeof(starts[0]);
    
    return 0;
}


