/*
   g++ -w -Wall ch15.6_graphing_data.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Simple_window.h"  
#include "./GUI/Graph.h"          
#include "./GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Distribution {
    int year, young, middle, old;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Distribution& d)
// assume format: ( year : young middle old )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year
        >> ch2 >> dd.young >> dd.middle >> dd.old
        >> ch3) {
            if (ch1!= '(' || ch2!=':' || ch3!=')') {
                is.clear(ios_base::failbit);
                return is;
            }
    }
    else
        return is;
    d = dd;
    return is;
}

//------------------------------------------------------------------------------

class Scale {                
    int cbase;               
    int vbase;               
    double scale;
public:
    Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) { }
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;    // ablak merete
    const int ymax = 400;

    const int xoffset = 100; // bal oldal es y koordinata kozotti tavolsag
    const int yoffset = 60;  // kepernyo alja es x kooridnata kozotti tavolsag

    const int xspace = 40;   // koordinata kozotti tavolsag
    const int yspace = 40; 

    const int xlength = xmax-xoffset-xspace;    // tengely hossza
    const int ylength = ymax-yoffset-yspace;

    const int base_year = 1960;
    const int end_year  = 2040;

    const double xscale
        = double(xlength)/(end_year-base_year); // x skala erteke
    const double yscale = double(ylength)/100;  // y skala erteke

    Scale xs(xoffset,base_year,xscale);
    Scale ys(ymax-yoffset,0,-yscale);

    string file_name = "japanese-age-data.txt";
    ifstream ifs(file_name.c_str());
    if (!ifs) error("can't open ",file_name);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;


    // file beluli adatok ellenorzese
    Distribution d;
    while (ifs>>d) {
        if (d.year<base_year || end_year<d.year) error("year out of range");
        if (d.young+d.middle+d.old != 100) error("percentages don't add up");
        int x = xs(d.year);
        children.add(Point(x,ys(d.young)));
        adults.add(Point(x,ys(d.middle)));
        aged.add(Point(x,ys(d.old)));
    }

    Simple_window win(Point(100,100),xmax,ymax,"Aging Japan");

    Axis x(Axis::x, Point(xoffset,ymax-yoffset), xlength, // x koordinata tengely
        (end_year-base_year)/10);
    x.label.move(-100,0);

    Axis y(Axis::y, Point(xoffset,ymax-yoffset), ylength, 10); // y koordinata tengely

    Line current_year(Point(xs(2004),ys(0)),Point(xs(2004),ys(100))); // 2004-nel huz egy fuggoleges vonalat
    current_year.set_style(Line_style::dash);

    // age 0-14 kiiratasa az y tengely mellett
    Text children_label(Point(20,children.point(0).y),"age 0-14");
    children.set_color(Color::red);
    children_label.set_color(Color::red);
    children_label.set_font_size(13);
    children_label.set_font(Font::times_bold);

    // age 15-64 kiiratasa az y tengely mellett
    Text adults_label(Point(20,adults.point(0).y),"age 15-64");
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);
    adults_label.set_font_size(13);
    adults_label.set_font(Font::times_bold);

    // age 65+ kiiratasa az y tengely mellett
    Text aged_label(Point(20,aged.point(0).y),"age 65+");
    aged.set_color(Color::dark_green);
    aged_label.set_color(Color::dark_green);
    aged_label.set_font_size(13);
    aged_label.set_font(Font::times_bold);

    // % of population kiiratasa az y tengely tetejere
    Text pop(Point(88, adults.point(0).y-113), "% of population");
    pop.set_font_size(13);
    pop.set_font(Font::times_bold);

    // evek kiiratasa az x tengely aljara
    Text years(Point(52, aged.point(0).y+40), "year  1960    1970    1980    1990    2000    2010    2020    2030    2040");
    years.set_font_size(13);
    years.set_font(Font::times_bold);

    // osszes adat kiiratasa a kepernyore
    win.attach(children);
    win.attach(adults);
    win.attach(aged);

    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);
    win.attach(pop);
    win.attach(years);

    win.attach(x);
    win.attach(y); 
    win.attach(current_year);

    win.wait_for_button();
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}