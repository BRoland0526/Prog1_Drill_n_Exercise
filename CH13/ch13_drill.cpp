/*
    g++ -w -Wall ch13_drill.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

int main()
{

    // 1. feladat
    int width = 800;
    int height = 1000;

    Simple_window win{Point{100,100}, width, height, "CH 13 Drill"};


    // 2.feladat
    Lines grid;
    int grid_max = 800;
    int grid_size = 100;
    for (int i = grid_size; i<=grid_max; i+=grid_size) {
        grid.add(Point(i,0),Point(i,grid_max));
        grid.add(Point(0,i),Point(grid_max,i));
    }
    win.attach(grid);



    // 3.feladat
    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 8; ++i)
    {
        vr.push_back(new Rectangle(Point{i*grid_size, i*grid_size}, grid_size, grid_size));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach( vr[vr.size() -1] );
    }


    // 4.feladat
    int size200 = 200;

    Image pic1(Point(600,200),"Renato.jpg");
    pic1.set_mask(Point(0,200), size200, size200);
    win.attach(pic1);

    Image pic2(Point(200,600),"Renato.jpg");
    pic2.set_mask(Point(0,200), size200, size200);
    win.attach(pic2);

    Image pic3(Point(400,0),"Renato.jpg");
    pic3.set_mask(Point(0,200), size200, size200);
    win.attach(pic3);
    win.set_label("exercise 1-4");
    win.wait_for_button();

    

    // 5.feladat
    int size100 = 100;
    Image pic_round(Point(0,0),"Renato.jpg");
    pic_round.set_mask(Point(200,100), size100, size100);
    win.attach(pic_round);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {   
            win.wait_for_button();
            win.set_label("exercise 5");

            if (j < 7)
            {
                pic_round.move(100,0);
            } 
            else
            {
                pic_round.move(-700,100);
            } 

        }
    }

}