#include <iostream>
#include "Model/Piece.h"
#include "Model/Point2D.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv)  {

    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    Point2D test(2,3);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
