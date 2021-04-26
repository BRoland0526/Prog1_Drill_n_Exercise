#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <exception>
#include <fstream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

// ---------------------------------- 1.resz ----------------------------------s
struct Item
{
    Item(string n, int i, double v): name(n), iid(i), value(v) {}
    string name;
    int iid;
    double value;
};

ostream& operator<<(ostream& os, const Item& i)
{
    os << i.name << ' ' << i.iid << ' ' << i.value;
    return os;
}

template<typename Iter>
void printout(const Iter& first, const Iter& last)
{
    for (auto p = first; p != last; ++p)
        cout << *p << ' ' << endl;
}

class compByName
{
private:
    string name;
public:
    compByName(const string& s): name{s} {}
    bool operator()(const Item& i) const { return i.name == name; }
};

class compById
{
private:
    int id;
public:
    compById(const int& idd): id(idd) {}
    bool operator()(const Item& i) const { return i.iid == id; }
};

void seperate() { cout << endl << endl; }

void part1()
{
    vector<Item> vi;
    string n;
    int id;
    double val;

    cout << "----------------------- Part1 -----------------------" << endl;

    // 1.feladat
    string filename = "ch12_drill_in.txt";
    ifstream is {filename};
    if (!is) cout << "Can't open file!" << endl;

    // beolvasas
    while (is >> n >> id >> val) { vi.push_back(Item{n, id, val}); }

    // 2.feladat
    sort(vi.begin(), vi.end(), 
        [] (const Item& i1, const Item& i2) { return i1.name < i2.name; });
    // 3.feladat
    sort(vi.begin(), vi.end(), 
        [] (const Item& i1, const Item& i2) { return i1.iid < i2.iid; });
    // 4.feladat
    sort(vi.begin(), vi.end(), 
        [] (const Item& i1, const Item& i2) { return i1.value > i2.value; });

    cout << "Exercise 2-4" << endl;
    cout << "Elements after sorting:" << endl;
    printout(vi.begin(), vi.end());

    cout << endl;

    // 5.feladat
    cout << "Exercise 5" << endl;
    cout << "Elements after inserting" << endl;
    vi.insert(vi.end(), Item{"horse shoe", 99, 12.34});
    vi.insert(vi.end(), Item{"Canon S400", 9988, 499.95});
    printout(vi.begin(), vi.end());

    cout << endl;

    // 6.feladat
    auto name_erase = find_if(vi.begin(), vi.end(), compByName("ajto"));
    vi.erase(name_erase);
    // 7.feladat
    auto id_erase = find_if(vi.begin(), vi.end(), compById(1));
    vi.erase(id_erase);

    cout << "Exercise 6-7" << endl;
    cout << "Elements after erasing:" << endl;
    printout(vi.begin(), vi.end());

    cout << "----------------------- Part1 -----------------------" << endl;

    seperate();
}
// ---------------------------------- 1.resz ----------------------------------



// ---------------------------------- 1_2.resz ----------------------------------
bool sortByName(const Item& item1, const Item& item2)
{
    return item1.name < item2.name;
}

bool sortById(const Item& item1, const Item& item2)
{
    return item1.iid < item2.iid;
}

bool sortByValDesc(const Item& item1, const Item& item2)
{
    return item1.value > item2.value;
}

// 8.feladat
void part1_2()
{
    list<Item> li;
    string n;
    int id;
    double val;

    cout << "----------------------- Part1_2 -----------------------" << endl;

    // 1.feladat
    string filename = "ch12_drill_in.txt";
    ifstream is {filename};
    if (!is) cout << "Can't open file!" << endl;

    // beolvasas
    while (is >> n >> id >> val) { li.push_back(Item{n, id, val}); }

    // 2.feladat
    li.sort(sortByName);
    // 3.feladat
    li.sort(sortById);
    // 4.feladat
    li.sort(sortByValDesc);

    cout << "Exercise 2-4" << endl;
    cout << "Elements after sorting:" << endl;
    printout(li.begin(), li.end());

    cout << endl;

    // 5.feladat
    cout << "5.feladat" << endl;
    cout << "Elements after inserting: " << endl;
    li.insert(li.end(), Item{"horse shoe", 99, 12.34});
    li.insert(li.end(), Item{"Canon S400", 9988, 499.95});
    printout(li.begin(), li.end());

    cout << endl;

    // 6.feladat
    auto name_erase = find_if(li.begin(), li.end(), compByName("ajto"));
    li.erase(name_erase);
    // 7.feladat
    auto id_erase = find_if(li.begin(), li.end(), compById(1));
    li.erase(id_erase);

    cout << "Exercise 6-7" << endl;
    cout << "Elements after erasing:" << endl;
    printout(li.begin(), li.end());

    cout << "----------------------- Part1_2 -----------------------" << endl;

    seperate();
}
// ---------------------------------- 1_2.resz ----------------------------------



// ---------------------------------- 2.resz ----------------------------------
void read_val(map<string, int>& m)
{
    string s;
    int val;
    cin >> s >> val;
    m.insert({s, val});
}

template<typename T1, typename T2>
void print_map(const map<T1, T2> mapp, const string& str)
{
    cout << str << endl;
    for (const auto& e : mapp) cout << e.first << ' ' << e.second << endl;
}

double map_int_sum(const map<string, int>& mapp)
{
    int sum = 0;
    for (const auto& e : mapp) sum += e.second;
    return sum;
}

void part2()
{   
    cout << "----------------------- Part2 -----------------------" << endl;

    // 1.feladat
    map<string, int> msi;

    // 2.feladat
    msi.insert({"Kacsa", 12});
    msi.insert({"Liba", 23});
    msi.insert({"lecture", 21});
    msi.insert({"Tehen", 44});
    msi.insert({"Kocka", 11});
    msi.insert({"Piros", 65});
    msi.insert({"Lampa", 31});
    msi.insert({"Laptop", 14});
    msi.insert({"Sajt", 76});
    msi.insert({"Oof", 66});

    // 3.feladat
    cout << "Exercise 3" << endl;
    print_map(msi, "Elements of map: ");

    cout << endl;

    // 4.feladat
    msi.erase(msi.begin(), msi.end());

    // 5,6.feladat
    cout << "Exercise 5-6" << endl;
    cout << "Please enter 10 pairs of string and int: " << endl;
    constexpr int how_many = 10;
    for (int i = 0; i < how_many; ++i) read_val(msi);

    cout << endl;
    
    // 7.feladat
    cout << "Exercise 7" << endl;
    print_map(msi, "New values of map: ");

    cout << endl;

    // 8.feladat
    cout << "8.feladat" << endl;
    cout << "Sum of map's elements: " << map_int_sum(msi) << endl;

    cout << endl;

    // 9,10.feladat
    map<int, string> mis;
    for (const auto& m : msi) mis.insert({m.second, m.first});

    // 11.feladat
    cout << "Exercise 11" << endl;
    print_map(mis, "Data pairs of mis: ");

    cout << "----------------------- Part2 -----------------------" << endl;

    seperate();
}
// ---------------------------------- 2.resz ----------------------------------


// ---------------------------------- 3.resz ----------------------------------
template<typename Iter>
void printout(const Iter& first, const Iter& last, const string& s)
{
    cout << s << endl;
    for (auto p = first; p != last; ++p)
        cout << *p << ' ';
    cout << endl;
}

template<typename InputIt, typename T, class BinaryOperation>
T my_accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
{
    while(first != last) 
    {
        init = op(init, *first);
        ++first;
    }
    return init;
}

template<typename InputIt>
double my_mean(InputIt first, InputIt last)
{
    double sum = my_accumulate(first, last, 0.0, plus<double>());
    int elem_nb = distance(first, last);
    return sum/elem_nb;
}

void part3()
{
    cout << "----------------------- Part3 -----------------------" << endl;

    vector<double> vd;

    // 1.feladat
    string filename = "ch21_drill_in2.txt";
    ifstream is {filename};
    if (!is) cout << "Can't open file!" << endl;

    double data;
    while (is >> data) { vd.push_back(data); }

    // 2.feladat
    cout << "Exercise2" << endl;
    printout(vd.begin(), vd.end(), "Elements of vd: ");

    cout << endl;

    // 3.feladat
    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());

    // 4.feladat
    cout << "Exercise 4" << endl;
    for (int i = 0; i < vi.size(); ++i) cout << vd[i] << ' ' << vi[i] << endl; 

    cout << endl;

    // 5.feladat
    cout << "Exercise 5" << endl;
    double vd_sum = my_accumulate(vd.begin(), vd.end(), 0.0, plus<double>());
    cout << "Sum of vd's elements: " << vd_sum << endl;

    cout << endl;

    // 6.feladat
    cout << "Exercise 6" << endl;
    int vi_sum = my_accumulate(vi.begin(), vi.end(), 0, plus<int>());
    cout << "Difference between vd_sum and vi_sum: " << vd_sum-vi_sum << endl;

    cout << endl;

    // 7.feladat
    cout << "Exercise 7" << endl;
    reverse(vd.begin(), vd.end());
    printout(vd.begin(), vd.end(), "Elements of vd after reversing: ");

    cout << endl;

    // 8.feladat
    cout << "Exercise 8" << endl;
    double avg = my_mean(vd.begin(), vd.end());
    cout << "Mean/avg of vd: " << avg << endl;

    cout << endl;

    // 9.feladat
    cout << "Exercise 9" << endl;
    vector<double> vd2;
    copy_if(vd.begin(), vd.end(), back_inserter(vd2), [avg] (const double& val) { return val < avg; });
    printout(vd2.begin(), vd2.end(), "Elements which are less than vd's mean/avg");

    cout << "----------------------- Part3 -----------------------" << endl;
}
// ---------------------------------- 3.resz ----------------------------------


int main()
try
{
    part1();

    part1_2();

    part2();

    part3();

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << endl;
    return 1;
}
catch(...)
{
    cerr << "Why are we still here" << endl;
    return 2;
}