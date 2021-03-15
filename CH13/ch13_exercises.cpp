/*
    g++ -w -Wall ch13_exercises.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

int main()
try
{
	using namespace Graph_lib;

	// 1.feladat
	Point t1(200,50);
	Simple_window win(t1, 800, 800, "CH 13 exercises");

	Graph_lib::Arc arc1(Point{150,100},100, 50, 50, 100); // pont, szelessseg, magassag
	win.attach(arc1);
	arc1.set_color(Color::black);
	arc1.set_angle1(0);
	arc1.set_angle2(180);
	arc1.set_angles(-75,5);
	arc1.set_style(Line_style(Line_style::solid,3));
    win.set_label("exercise 1");
    win.wait_for_button();



	// 2.feladat
	Box box2(Point{150,300},200, 100, 20);
	win.attach(box2);

	box2.set_fill_color(Color::black);
    win.set_label("exercise 2");
    win.wait_for_button();


	// 3.feladat
	Arrow arrow1(Point{100,500}, Point{400,500});
	win.attach(arrow1);
    win.set_label("exercise 3");
    win.wait_for_button();


	// 6.feladat
	Box box3(Point{500,300}, 70,30,10);
	win.attach(box3);
	box3.set_fill_color(Color::green);

	Box box4(Point{475,360}, 120,30,10);
	win.attach(box4);
	box4.set_fill_color(Color::green);

	Text t2 {Point{509,320}, "Window"};
	t2.set_font(Font::times_bold);
	t2.set_font_size(12);
	win.attach(t2);

	Text t3 {Point{484,380}, "Simple_window"};
	t3.set_font(Font::times_bold);
	t3.set_font_size(12);
	win.attach(t3);

	Arrow arrow2(Point{536,360}, Point{536,329});
	win.attach(arrow2);

    win.set_label("exercise 6");
    win.wait_for_button();



    // 7.feladat
    Vector_ref<Rectangle> vr;
    int c = 50; // kocka

    for(int row = 0; row < 4; ++row) // sor
    {
        for(int col = 0; col < 3; ++col) // oszlop
        {
            vr.push_back(new Rectangle {Point{500+c*col, 500+c*row}, c, c});
            int i = vr.size()-1;

            if(i == 0) vr[i].set_fill_color(Color::red);
            if(i == 1) vr[i].set_fill_color(Color::blue);
            if(i == 2) vr[i].set_fill_color(Color::green);
            if(i == 3) vr[i].set_fill_color(Color::yellow);
            if(i == 4) vr[i].set_fill_color(Color::black);
            if(i == 5) vr[i].set_fill_color(Color::magenta);
            if(i == 6) vr[i].set_fill_color(Color::cyan);
            if(i == 7) vr[i].set_fill_color(Color::dark_red);
            if(i == 8) vr[i].set_fill_color(Color::dark_green);
            if(i == 9) vr[i].set_fill_color(Color::dark_yellow);
            if(i == 10) vr[i].set_fill_color(Color::dark_blue);
            if(i == 11) vr[i].set_fill_color(Color::dark_magenta);


            win.attach(vr[i]);
        }
    }
    /*
		Graph.h

        red=FL_RED,
        blue=FL_BLUE,
        green=FL_GREEN,
        yellow=FL_YELLOW,
        white=FL_WHITE,
        black=FL_BLACK,
        magenta=FL_MAGENTA,
        cyan=FL_CYAN,
        dark_red=FL_DARK_RED,
        dark_green=FL_DARK_GREEN,
        dark_yellow=FL_DARK_YELLOW,
        dark_blue=FL_DARK_BLUE,
        dark_magenta=FL_DARK_MAGENTA,
        dark_cyan=FL_DARK_CYAN
     */

    win.set_label("exercise 7");
    win.wait_for_button();

  


}
catch(exception& e)
{
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch(...)
{
	cerr << "exception\n";
	keep_window_open();
}