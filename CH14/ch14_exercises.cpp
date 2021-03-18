/*
    g++ -w -Wall ch14_exercises.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

int main()
try
{
	using namespace Graph_lib;

    // 1.feladat Graph.cpp 1564 - 1694 , Graph.h 782 - 822
	Point t1(200,50);
	Simple_window win(t1, 1200, 800, "Chapter 14 exercises");

	Smiley s1(Point(400,400), 100);
	s1.set_fill_color(Color::yellow);
	win.attach(s1);

    Graph_lib::Arc arc1(Point{400,305},50, 30, 0, 180);
    win.attach(arc1);
    arc1.set_fill_color(Color::green);


    Frowny s2(Point(800,400), 100);
    s2.set_fill_color(Color::dark_cyan);
    win.attach(s2);

    Graph_lib::Arc arc2(Point{800,305},50, 30, 0, 180);
    win.attach(arc2);
    arc2.set_fill_color(Color::red);

	win.set_label("exercise 1");
	win.wait_for_button();

    win.detach(s1);
    win.detach(s2);
    win.detach(arc1);
    win.detach(arc2);


    // 11.feladat   Grap.h 737-759 sor
    Binary_tree bt(Point(600,50),6,"");
    win.attach(bt);
    win.set_label("exercise 11");
    win.wait_for_button();

    win.detach(bt); 


    // 12.feladat
    Binary_tree_squares bts(Point(600,50),6,"");
    win.attach(bts);
    win.set_label("exercise 12");
    win.wait_for_button();

    win.detach(bts);

    // 13.feladat
    Binary_tree bt2(Point(600,50),6,"au");
    win.attach(bt2);
    win.set_label("exercise 13");
    win.wait_for_button();

    win.detach(bt2);

    // 14.feladat
    Binary_tree bt3(Point(600,50),6,"ad");
    win.attach(bt3);

    bt3.set_node_label("l","Root"); // Honnan menjen, neve
    bt3.set_node_label("lr","lr");
    bt3.set_node_label("lrr","lrr");
    bt3.set_node_label("lrrr","lrrr");
    bt3.set_node_label("lrrrl","lrrrl");
    bt3.set_node_label("lrrrll","lrrrll");

    win.set_label("exercise 14");
    win.wait_for_button();


}
catch(exception& e)
{
	cerr << "exception\n" << e.what() << endl;
	keep_window_open();
}
catch(...)
{
	cerr << "exception\n";
	keep_window_open();
}
