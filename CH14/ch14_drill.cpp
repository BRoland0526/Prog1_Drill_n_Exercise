#include<iostream>

using namespace std;

class B1
{
public:
    virtual void vf() { std::cout << "B1::vf()" << std::endl; }
    void f()          { std::cout << "B1:f()" << std::endl; }
    virtual void pvf()=0;
};

class D1 : public B1
{
public:
    void pvf(){ std::cout << "D1::pvf()" << std::endl; }
    void vf() override { std::cout << "D1::vf()" << std::endl; }
    /*void f(){ std::cout << "D1:f()" << std::endl; }*/
};

class D2 : public D1
{
public:
    void pvf() { std::cout << "D2::pvf()" << std::endl; }
};



class B2
{
public:
    virtual void pvf()=0;
};

class D21 : public B2
{
 public:
    std::string s;
    void pvf()
    {
        std::cout << s << std::endl;
    }
};

class D22 : public B2
{
 public:
    int i;
    void pvf()
    {
        std::cout << i << std::endl;
    }
};

void f(B2& b2)
{
    b2.pvf();
}

int main()
try
{
/*
    B1 b1;
    b1.vf();
    b1.f();
    b1.pvf();
    
    D1 d1;
    d1.vf();
    d1.f();
    d1.pvf();
    
    B1& bref = d1;
    bref.vf();
    bref.f();
    bref.pvf();
*/

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();
    
    D21 d21;
    d21.s = "D21::pvf()";
    d21.pvf();
    
    D22 d22;
    d22.i = 10;
    d22.pvf();
    
    f(d21);
    f(d22);

}
catch(exception& e)
{
    cerr << "Something is wrong!" << endl;
}
catch(...)
{
    cerr << "It's still wrong!" << endl;
}