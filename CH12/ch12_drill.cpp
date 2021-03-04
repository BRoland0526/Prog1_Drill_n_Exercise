/* 
g++ -w -Wall GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ch12_drill.cpp `fltk-config --ldflags --use-images` -o asd
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    
    Point tl {100, 100};        

    Simple_window win {tl, 600, 400, "My window"};
    win.wait_for_button();      

    
    // 12.7.3 
    Axis xax {Axis::x, Point{20, 300}, 280, 10, "x axis"};   // x koordinata tengely
    
    win.attach(xax);                 
    win.set_label("My window #2");  
    win.wait_for_button();          

    Axis yax {Axis::y, Point{20, 300}, 280, 10, "y axis"};   // y koordinata tengely
    yax.set_color(Color::cyan);              
    yax.label.set_color(Color::dark_red);    
    win.attach(yax);
    win.set_label("My window #3");
    win.wait_for_button();                  

    // 12.7.4 
    Function szinusz {sin, 0, 100, Point{20, 150}, 1000, 50, 50};  

    win.attach(szinusz);
    win.set_label("My window #4");
    win.wait_for_button();
    
    // 12.7.5 
    szinusz.set_color(Color::blue);    

    Polygon poly;                   
    poly.add(Point{300, 200});      
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("My window #5");
    win.wait_for_button();

    // 12.7.6 
    Rectangle r {Point{200, 200}, 100, 50};
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});
    win.attach(poly_rect);

    win.set_label("My window #6");
    win.wait_for_button();

    // 12.7.7 
    r.set_fill_color(Color::yellow);    
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("My window #7");
    win.wait_for_button();

    // 12.7.8 
    Text t {Point{150, 150}, "Hello World"};
    win.attach(t);
    win.set_label("My window #8");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("My window #9");
    win.wait_for_button();

    // 12.7.9 
    Image ii {Point{100, 50}, "meme.jpeg"};
    win.attach(ii);
    win.set_label("My window #10");
    win.wait_for_button();

    ii.move(100, 200);
    win.set_label("My window #11");
    win.wait_for_button();

    // 12.7.10 
    Circle c {Point{100, 200}, 50};
    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m {Point{100, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100, 20}, oss.str()};

    Image cal {Point{225, 225}, "snow_cpp.gif"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("My window #12");
    win.wait_for_button();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}