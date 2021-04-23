#include "std_lib_facilities.h"

// 1-2.feladat
template<typename T> struct S
{
    S() {}
    S(T v): val{v} {}

    // 11.feladat
    T& get(); 
    const T& get() const;

    // 9-10.feladat
    void set(T t) { val = t; }
    S& operator= (const T& t) { val = t; return val; }

    friend istream& operator>> (istream& is, S<T>& t) // https://en.cppreference.com/w/cpp/language/friend
    {
        is >> t.val;
        return is;
    }
    // Engedelyt ad a class-on kivuli fuggvenyeknek, hogy hozzaferhessenek a class-on beluli informaciohoz

// 7.feladat
private:
    T val;
};

// --- 6.feladat ---
template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}
// --- 6.feladat ---

// 12.feladat
template<typename T>
void read_val(T& v)
{
    cin >> v;
}


int main()
try
{   // --- 3-5,8,13.feladat ---
    S<int> sint {5};
    sint.set(17);
    cout << sint.get() << endl << "new sint: ";
    read_val(sint);
    cout << sint.get() << endl;

    S<char> schar {'F'};
    cout << schar.get() << endl << "new schar: ";
    read_val(schar);
    cout << schar.get() << endl;

    S<double> sdouble {2.333};
    cout << sdouble.get() << endl << "new sdouble: ";
    read_val(sdouble);
    cout << sdouble.get() << endl;
    
    S<string> sstring {"Hi there c:"};
    cout << sstring.get() << endl;

    S<vector<int>> sintvector {vector<int>(10,0)};
    for(int i : sintvector.get())
    cout << i << endl;
    // --- 3-5,8,13.feladat ---
    
    return 0;

}catch(exception& e)
{
    cerr << e.what() << endl;
}catch(...)
{
    cerr << "Why are we still here\n"; 
}