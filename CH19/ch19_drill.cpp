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
template<typename T> void read_val(T& v)
{
    cin >> v;
}


int main()
try
{   // --- 3-5,8,13.feladat ---
    S<int> si {5};
    si.set(17);
    cout << si.get() << endl << "new sint: ";
    read_val(si);
    cout << si.get() << endl;

    S<char> sc {'y'};
    cout << sc.get() << endl << "new schar: ";
    read_val(sc);
    cout << sc.get() << endl;

    S<double> sd {1.234};
    cout << sd.get() << endl << "new sdouble: ";
    read_val(sd);
    cout << sd.get() << endl;
    
    S<string> sstr {"hola"};
    cout << sstr.get() << endl;

    S<vector<int>> sivec {vector<int>(10,0)};
    for(int i : sivec.get())
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