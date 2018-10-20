#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int next_num(int num)
{
    std::string r;
    std::set<int> digits; // all digits other than msb.

    
    auto s = std::to_string(num);
    auto len = s.length();
    
    for ( auto c : s)
    {
        digits.insert(int(c) - 48);
    }
    int min = 0;
    for (auto i : digits)
    {
        if(i == min) ++min;
        if(i> min) break;
    }

    auto msd = int(s[0]) - 48 ;
    if (msd == 9)  
    {
        r.reserve(len + 1); // for speed optimization

        if(digits.find(1) != digits.end()) r.push_back(char(min+48));
        else r.push_back('1') ;

        if(digits.find(0) != digits.end()) r.push_back(char(min+48));
        else r.push_back('0') ;
        
    }
    else
    {
        r.reserve(len); // for speed optimization
        auto msd_c = char( msd + 1 + 48);
        r.push_back(msd_c);
    }

    // Filling remaining places    
    int i = 1;
    while(i<= len - 1)
    {
        r.push_back(char(min+48));
        i++;
    }
    return stoi(r);
}


int main()
{
    cout << next_num(910) << endl;
    cout << next_num(810) << endl;
    cout << next_num(662) << endl;
    cout << next_num(654321) << endl;
    cout << next_num(987654321) << endl;
    return 0;
}
