/*
    g++ -w -Wall ch12_exercises.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp `fltk-config --ldflags --use-images` -o asd
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

using namespace Graph_lib;

int main()
try{
	int height = 800;
	int width = 1600;

	Simple_window win{Point{100,100}, height, width, "ch12 exercises"};
	


    // 1,feladat
	Polygon poly1;
    
    poly1.add(Point(700,650)); // 4db pont megadasa
    poly1.add(Point(700,400));
    poly1.add(Point(550,400));
    poly1.add(Point(550,650));
    poly1.set_color(Color::red);
    win.attach(poly1);

    Rectangle rectangle1 {Point{350, 100}, 100, 50}; // 100 szeles 50 magas
    rectangle1.set_color(Color::blue);
    win.attach(rectangle1);
    win.set_label("exercise 1");
    win.wait_for_button();


    
    // 2.feladat
    Rectangle rectangle2 {Point{400,600}, 100, 30};
    win.attach(rectangle2);

    Text t1 {Point{425,620}, "Howdy!"};
    win.attach(t1);
    win.set_label("exercise 2");
    win.wait_for_button();


    
    // 3.feladat
    Text t2 {Point{50, 350}, "H"};
    t2.set_font(Font::courier);
    t2.set_font_size(150);

    Text t3 {Point{135, 350}, "S"};
    t3.set_font(Font::courier);
    t3.set_font_size(150);

    t2.set_color(Color::magenta);
    t3.set_color(Color::blue);

    win.attach(t2);
    win.attach(t3);

    win.set_label("exercise 3");
    win.wait_for_button();
    

    
    // 4.feladat
    Vector_ref<Rectangle> vr;
    int w = 50; // kocka

    for(int row = 0; row < 3; ++row) // sor
    {
        for(int col = 0; col < 3; ++col) // oszlop
        {
            vr.push_back(new Rectangle {Point{350+w*col, 200+w*row}, w, w});
            int i = vr.size()-1;

            cout << i << endl;

            if(i % 2 == 0)
            {
                vr[i].set_fill_color(Color::red);
            }
            else
            {
                vr[i].set_fill_color(Color::white);
            }
            win.attach(vr[i]);
        }
    }

    win.set_label("exercise 4");
    win.wait_for_button();

    
    // 5.feladat
    int xmax = (x_max()/4)*3;
    int ymax = (y_max()/3)*2;
	Rectangle rect(Point(217,63),xmax,ymax);
    rect.set_color(Color::red);
    rect.set_style(Line_style(Line_style::solid,15));
    win.attach(rect);
    win.set_label("exercise 5");
    win.wait_for_button();



    // 6.feladat
    Rectangle rectangle6(Point{100,100},2000,1000); // very big
    win.attach(rectangle6);
    win.set_label("exercise 6");
    win.wait_for_button();

    

    // 7.feladat

    //Teto
    Polygon tri;
    tri.add(Point{400,400});
    tri.add(Point{350,450});
    tri.add(Point{450,450});
    tri.set_color(Color::black);
    tri.set_fill_color(Color::yellow);


    //Haz alakzat
    Rectangle sqr {Point{350,450}, 100, 100};
    sqr.set_color(Color::black);
    sqr.set_fill_color(Color::green);
    win.attach(sqr);


    //Kemeny
    Rectangle sqr2 {Point{425,391}, 25, 60};
    sqr2.set_color(Color::black);
    sqr2.set_fill_color(Color::red);


    //Ablak
    Vector_ref<Rectangle> vr2;
    int kocka = 20; 

    for(int sor = 0; sor < 2; ++sor) 
    {
        for(int oszlop = 0; oszlop < 2; ++oszlop) 
        {
            vr2.push_back(new Rectangle {Point{370+kocka*sor, 460+kocka*oszlop}, kocka, kocka});
            
            int i = vr2.size()-1;

            if(i <= vr2.size()+1)
            {
                vr2[i].set_fill_color(Color::magenta);
            }
            win.attach(vr2[i]);
        }
    }


    //Ajto
    Rectangle sqr3 {Point{410, 510}, 25, 40};
    sqr3.set_color(Color::black);
    sqr3.set_fill_color(Color::cyan);


    win.attach(sqr2);
    win.attach(tri);
    win.attach(sqr3);



    win.set_label("exercise 7");
    win.wait_for_button();



    // 8.feladat
    Circle c1(Point(170,790),50);
    c1.set_style(Line_style(Line_style::solid,5));
    c1.set_color(Color::blue);
    win.attach(c1);

    Circle c2(Point(240,790),50);
    c2.set_style(Line_style(Line_style::solid,5));
    win.attach(c2);

    Circle c3(Point(320,790),50);
    c3.set_style(Line_style(Line_style::solid,5));
    c3.set_color(Color::red);
    win.attach(c3);

    Circle c4(Point(210,850),50);
    c4.set_style(Line_style(Line_style::solid,5));
    c4.set_color(Color::yellow);
    win.attach(c4);

    Circle c5(Point(290,850),50);
    c5.set_style(Line_style(Line_style::solid,5));
    c5.set_color(Color::green);
    win.attach(c5);
    win.set_label("exercise 8");
    win.wait_for_button();

    

    // 9.feladat
    Image pic {Point{100,200},"meme.jpeg"};
    win.attach(pic);
    win.set_label("exercise 9");
    win.wait_for_button();



}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){ 
	cerr << "It involved into a big freakin problem" << endl;
	return 2;
}

