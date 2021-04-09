/*
   g++ -w -Wall ch15.5_approximation.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include <cmath>
#include <sstream>
#include "./GUI/Simple_window.h"  
#include "./GUI/Graph.h"          

using namespace std;

//------------------------------------------------------------------------------

int fac(int n)    
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        n--;
    }
    return r;
}

//------------------------------------------------------------------------------

double term(double x, int n) { return pow(x,n)/fac(n); }    

//------------------------------------------------------------------------------

double expe(double x, int n)        
{
    double sum = 0;
    for (int i=0; i<n; ++i) sum+=term(x,i);
    return sum;
}

//------------------------------------------------------------------------------

int expN_number_of_terms = 10;

double expN(double x)
{
    return expe(x,expN_number_of_terms);
}

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;      // ablak merete
    const int ymax = 400;

    const int x_orig = xmax/2; // origobol indulunk (0,0)
    const int y_orig = ymax/2; 
    const Point orig(x_orig,y_orig);

    const int r_min = -10;     // -10 es 11 kozott
    const int r_max = 11;

    const int x_scale = 30;    // x es y skala
    const int y_scale = 30;

    Simple_window win(Point(100,100),xmax,ymax,"exp approximation");

    const int xlength = xmax-40;   // x es y tengely nem log ki az ablakbol, azaz kisebb meretu lesz
    const int ylength = ymax-40;

    Axis x(Axis::x,Point(20,y_orig), xlength, xlength/x_scale);
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale);
    win.attach(x);
    win.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    Function real_exp(exp,r_min,r_max,orig,200,x_scale,y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    for (int n = 0; n<50; ++n) {
        ostringstream ss;
        ss << "exp approximation; n==" << n ;
        win.set_label(ss.str());
        expN_number_of_terms = n;
        
        Function e(expN,r_min,r_max,orig,200,x_scale,y_scale);
        win.attach(e);

        // Ha a felhasznalo kiakar lepni
        if (!win.wait_for_button())
            break;

        win.detach(e);
    }

}
catch(exception& e) {
    cout << "Exception: " << e.what() << endl;
    return 1;
}
catch(...) {
    cout << "Why are we still here" << endl;
    return 2;
}