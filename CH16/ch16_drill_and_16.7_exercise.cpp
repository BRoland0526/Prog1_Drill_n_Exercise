/*
    g++ -w -Wall ch16_drill_and_16.7_exercise.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Lines_window.cpp -o asd `fltk-config --ldflags --use-images`
*/

#include "./GUI/Lines_window.h"
#include "./GUI/Graph.h"

int main()
try{

    Lines_window win{Point{100,100}, 1280, 720, "Drill16"};

    return gui_main();

}catch(exception& e){
    cerr << e.what() << endl;
    return 1;
}catch(...){
    cerr << "Why are we still here \n";
    return 2;
}