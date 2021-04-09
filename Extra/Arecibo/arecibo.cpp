/*
    g++ -w -Wall arecibo.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o arecibo `fltk-config --ldflags --use-images`
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include "./GUI/std_lib_facilities.h"
#include <math.h>

int main()
try {
    using namespace Graph_lib;
    
    constexpr int rsize = 9; // ablak meret
    constexpr int width = 23*rsize; // 23 sor
    constexpr int heigth = 73*rsize; // 73 oszlop
    Simple_window win{Point{100,0}, width, heigth, "Arecibo message"};

    vector<char> c(1679); // 23*73 = 1679 karakter

    for (int i = 0; i < c.size(); ++i)
    cin >> c[i];

    Vector_ref<Rectangle> rect;

    int x = 0, y = 0;
    for (int i = 0; i < c.size(); ++i)
    {
        if (c[i] == '1')
        { 
            if (i % 23 == 0 && i != 0) // ha elerte a szelet, akkor ugorjon a kovetkezo sorra
            { 
                x = 0; y+=rsize; 
            }
            rect.push_back(new Rectangle(Point{x, y}, rsize, rsize));
            rect[i].set_fill_color(Color::white);
            win.attach(rect[i]);
            x+=rsize; // addig menjen amig el nem erti a szelet
        }
        if (c[i] == '0')
        {
            if (i % 23 == 0 && i != 0) // ha elerte a szelet, akkor ugorjon a kovetkezo sorra
            {
                x = 0; y+=rsize; 
            } 
            rect.push_back(new Rectangle(Point{x, y}, rsize, rsize));
            rect[i].set_fill_color(Color::black);
            win.attach(rect[i]);
            x+=rsize; // addig menjen amig el nem erti a szelet
        }
    }

    win.wait_for_button();
    return 0;

} catch (exception& e){
    cerr << e.what() << endl;
    return 1;
} catch (...){
    cerr << "Something went wrong!" << endl;
    return 2;
}
