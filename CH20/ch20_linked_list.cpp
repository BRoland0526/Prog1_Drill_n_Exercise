#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

template<typename Elem> struct Link
{
    Link* prev;    // elozo elem
    Link* succ;    // kovetkezo elem
    Elem  val;     // ertek
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : val(v), prev(p), succ(s) {}
};

//------------------------------------------------------------------------------

template<typename Elem> class list 
{
public:
    class iterator;    

    list() : first(new Link<Elem>()), last(first) {}

    iterator begin();   // Elso elemtol kezdje a vizsgalatot
    iterator end();     // Utolso elemig menjen a vizsgalat

    iterator insert(iterator p, const Elem& v); // v elemet beszurja a p utan
    iterator erase(iterator p);                 // p elem eltavolitasa 

    void push_back(const Elem& v);  // v elemet szurja be a legutolso helyre
    void push_front(const Elem& v); // v elemet szurja be a legelso helyre
    void pop_front();   // elso elem torlese
    void pop_back();    // utolso elem torlese

    Elem& front();      // az elso elem
    Elem& back();       // az utoslo elem

    Link<Elem>* first;
    Link<Elem>* last;   
};

//------------------------------------------------------------------------------

template<typename Elem> class list<Elem>::iterator
{
    Link<Elem>* curr;   
public:
    iterator(Link<Elem>* p) :curr(p) { }
    iterator& operator++() {curr = curr->succ; return *this; } // elore lepes
    iterator& operator--() {curr = curr->prev; return *this; } // vissza fele lepes
    Elem& operator*() { return curr->val; } // ertek megszerzese

    friend bool operator==(const iterator& a, const iterator& b)
    {
        return a.curr==b.curr;
    }

    friend bool operator!=(const iterator& a, const iterator& b)
    {
        return a.curr!=b.curr;
    }
};

//------------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::iterator list<Elem>::begin()  // iterator az elso elemre
{ 
    return iterator(first); 
}

//------------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::iterator list<Elem>::end() // iterator az utolso elemre
{ 
    return iterator(last); 
}

//------------------------------------------------------------------------------

template<typename Elem> 
void list<Elem>::push_front(const Elem& v) // v elem(ek) beszurasa
{
    first = new Link<Elem>(v,0,first);
}

//------------------------------------------------------------------------------

// a legnagyobb erteku elemet adja vissza
template<typename Iterator >
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

void f()
{
    list<int> lst;
    int x;
    while (cin >> x) lst.push_front(x);

    list<int>::iterator p = high(lst.begin(), lst.end());
    if (p==lst.end())    // megvizsgalja hogy elertuk-e a veget vagy nem
        cout << "The list is empty" << endl;
    else
        cout << "the highest value is " << *p << endl;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}
