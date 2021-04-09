/*
   g++ -w -Wall ch15_classdef_drill.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

//1,4feladat
struct Person {
    Person() : first_n(""), second_n(""), a(0) {}
    Person(string fn, string sn, int age) :first_n(fn), second_n(sn), a(age)
    {	
    	//7.feladat
        const string illegal_chars = ";:\"'[]*&^%$#@!";
        
        // Keresztnev ellenorzese
        for (int i = 0; i<fn.size(); ++i)
        {
            for (int j = 0; j<illegal_chars.size(); ++j)
            {
                if (fn[i]==illegal_chars[j])
                {
                	error("illegal character: ",string(1,fn[i]));
                }
            }
        }

        // Vezeteknev ellenorzese
        for (int i = 0; i<sn.size(); ++i)
        {
            for (int j = 0; j<illegal_chars.size(); ++j)
            {
                if (sn[i]==illegal_chars[j])
                {
                    error("illegal character: ",string(1,sn[i]));
                }
            }
        }

        // Eletkor ellenorzese
        if (a<0 or a>=150)
        {
        	error("age must be in range [0,150)");
        } 

    }
    string first_name() const { return first_n; }
    string second_name() const { return second_n; }
    int age() const { return a; }
//5.feladat
private:
    string first_n;
    string second_n;
    int a;
};


//3,6.feladat
istream& operator>>(istream& is, Person& p)
{
    string fname, sname;
    int age;
    is >> fname >> sname >> age;
    if (!is) return is;
    p = Person(fname,sname,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Name: " << p.first_name() << " " <<
        p.second_name() << ", age: " << p.age();
}

int main()
try 
{
	//2.feladat
    //Person p;
    //p.n = "Goofy";
    //p.a = 63;
    //cout << "Name: " << p.n << ", age: " << p.a << endl;

    //cout << "Enter name and age: ";
    //Person p2;
    //cin >> p2;
    //cout << p2 << endl;

    //Person p3;
    //while (cin>>p3) {
    //    cout << p3 << endl;
    //}


	//8.feladat
    vector<Person> persons;
    Person pin;

    cout << "Please enter the name and age(First name, Second name, Age): " << endl;

    while (cin>>pin)
    {
         persons.push_back(pin);
    }
    for (int i = 0; i<persons.size(); ++i)
    {
      cout << persons[i] << endl;
    }       
    
    keep_window_open();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}