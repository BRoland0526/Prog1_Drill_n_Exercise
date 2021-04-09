/*
   g++ -w -Wall ch15_graphing_drill.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

//---------------------- Shape function ----------------------

//1.feladat
double one(double x)
{
    return 1; 
}

//4.feladat
double slope(double x)
{
    return x/2; 
}

//6.feladat
double square(double x) 
{ 
    return x*x;
}

//9.feladat
double sloping_cos(double x)
{
    return cos(x) + slope(x); 
}

//---------------------- Shape function ----------------------

int main()
try {
    const int xmax = 600; // 1.feladat ablak meret meghatarozasa
    const int ymax = 600;

    const int x_orig = xmax/2; // origobol indulunk (0,0)
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    const int range_min = -10; // 1.feladat range [-10,11]
    const int range_max = 11; 

    const int n_points = 400; // 1.feladat 400 pont

    const int x_scale = 20; // 2.feladat x es y skala 
    const int y_scale = 20;

    //---------------------- Function graphing ----------------------

    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Function graphs");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale);
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale);
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();

    //---------------------- Function graphing ----------------------


    //---------------------------- Shape ----------------------------

    //1.feladat
    Function s(one,range_min,range_max,orig,n_points,x_scale,y_scale);
    win.attach(s);
    win.set_label("exercise 1");
    win.wait_for_button();

    //4.feladat
    Function s2(slope,range_min,range_max,orig,n_points,x_scale,y_scale);
    win.attach(s2);
    win.set_label("exercise 4");
    win.wait_for_button();

    //5.feladat
    Text ts2(Point(100,y_orig+4*y_scale),"x/2");
    win.attach(ts2);
    win.set_label("exercise 5");
    win.wait_for_button();

    //6.feladat
    Function s3(square,range_min,range_max,orig,n_points,x_scale,y_scale);
    win.attach(s3);
    win.set_label("exercise 6");
    win.wait_for_button();

    //7-8.feladat
    Function s4(cos,range_min,range_max,orig,n_points,x_scale,y_scale);
    s4.set_color(Color::blue);
    win.attach(s4);
    win.set_label("exercise 7-8");
    win.wait_for_button();

    //9.feladat
    Function s5(sloping_cos,range_min,range_max,orig,n_points,x_scale,y_scale);
    win.attach(s5);
    win.set_label("exercise 9");
    win.wait_for_button();

    //---------------------------- Shape ----------------------------
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "Kill me \n";
    keep_window_open();
}