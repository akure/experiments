#include<iostream>
#include<map>
#include<algorithm>


int main()
{
  // template<typename T>
  using map_is_t = std::map<int, std::string>;
  using map_is_itr= std::map<int, std::string>::iterator;

  map_is_t id_name_table;
  id_name_table[1] = "Ram";
  id_name_table[2] = "Ryan";
  id_name_table[3] = "Alex";
  id_name_table[4] = "Frian"; 

  
  // Range based for loop demonstration for map
  for ( auto kv : id_name_table )
  { 
      // It access the pair elements directly. no pointer or iterator. 
      std::cout << kv.first << " : " << kv.second << std::endl;
  } 

  std::cout << "========" << std::endl;
  map_is_itr start = std::begin(id_name_table);
  map_is_itr end = std::end(id_name_table);
  
  while( start != end) 
  { 
        std::cout << "ID : " << (*start).first << ", NAME : " << (*start).second << std::endl; 
        ++start;               
  } 
  return 0;
}
