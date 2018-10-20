#include<iostream>
#include<array>

using namespace std;

// Assuming non-negative values
const int empty = -1;

struct bst_t 
{

    bst_t () { b.fill(-1); }
    int left(int i) { return 2*i +1; }

    int right(int i) { return 2*i +2;}

    int parent(int i) { return (i-1)/2; }

    int find(int i) 
    {
        int k = 0;
        bool found = false;
        while( k <= b.size())
        {
            if(i == b[k]) { found = true; break;}
            else if ( i < b[k] ) { k = left(k); }
            else if ( i > b[k] ) { k = right(k); }
        }
        if (found) return k;
        else return -1;
    }

    int insert(int i)
    {
        bool r= false;
        int k = 0;
        while(k <= b.size())
        {
            if (b[k] == -1) { b[k] = i; r = true; break;}

            if(i == b[k]) { r = true; break;}
            else if ( i < b[k] ) { k = left(k); }
            else if ( i > b[k] ) { k = right(k); }
        }

        if (r) return k;
        else return -1;
    }

int size() { return b.size(); } 
    private: 
    std::array<int, 300000>  b;

};

int main()
{
    bst_t b;
    cout << "size : " << b.size() << endl; 
    cout << b.insert(10) << endl; // 0
    cout << b.insert(5) << endl; // 1
    cout << b.insert(20) << endl; // 2
    cout << b.insert(7) <<endl;  // 4
    cout << b.insert(50) << endl;; //6
    cout << b.insert(15) << endl;;  // 5
    cout << b.insert(4) << endl; // 3

    cout << b.find(10) << endl; 
    cout << b.find(5) << endl; 
    cout << b.find(20) << endl; 
    cout << b.find(7) << endl; 
    cout << b.find(50) << endl; 
    cout << b.find(15) << endl; 
    cout << b.find(4) << endl; 

    return 0;
}
