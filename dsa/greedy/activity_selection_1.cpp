#include <iostream>
#include <algorithm>
#include <array>

typedef std::array<int, 6> arr_t_6;

void max_activity_selection(arr_t_6 & starttimings , arr_t_6 & finishtimings, int total_activities)
{
   if( !std::is_sorted(finishtimings.begin(), finishtimings.end()) )	
   {
	   std::sort(finishtimings.begin(), finishtimings.end());
	   for (auto t : finishtimings ) { std::cout << " " << t ; }
	   std::cout << std::endl;
	
   }

	int count = 0;
	int index = 0;
    int current_start_time = -1;
    int current_end_time = -1;
    while( index < starttimings.size())
    {
		if( finishtimings[index]  >= current_end_time && starttimings[index] >= current_end_time)
		{
			std::cout << " s : " << starttimings[index] << ", e : " << finishtimings[index] << std::endl; 
	    	++count;		
			current_end_time = finishtimings[index];
		} 
		++index;
    }
	
	std::cout << "Max activity = " << count << std::endl;
}

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
	max_activity_selection(starts, ends, total_activities);
	return 0;
}
