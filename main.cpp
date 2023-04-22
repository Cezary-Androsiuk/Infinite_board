#include "include/include.hpp"
#include "include/Program/Program.hpp"
// g++ main.cpp -o main include/Program/Program.cpp include/Plane/Plane.cpp -lsfml-graphics -lsfml-window -lsfml-system; ./main

int main(){
    Program app;
    while(app.running()){
        app.update();
        app.render();
    }
}
