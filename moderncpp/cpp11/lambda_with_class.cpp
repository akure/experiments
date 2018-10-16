#include<iostream>
#include<vector>
#include <algorithm>    // std::for_each

struct hero 
{
  std::string m_name = "ironman";
  std::string m_mission = "test";
  bool m_on_mission = true;

  bool any_of(std::vector<std::string> vec) 
  { 
      bool result = false;
      std::for_each(vec.begin(), vec.end(), [this, &result](const std::string & mission) 
                                          { 
                                             if (!result) result = ( mission == m_mission) ;
                                             // return result;
                                          } );

      return result;
  }
};


int main()
{
    hero h;

    // bool r = h.any_of({"test", "home", "tara", "blackops", "ocean"});
    bool r = h.any_of({"home", "tara", "blackops", "ocean"});

    std::cout << std::boolalpha << std::endl;
    std::cout << " Result : " << r << std::endl; 
    
      
    
    return 0;
}
