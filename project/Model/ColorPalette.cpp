//
// Created by lifka on 4/07/17.
//

#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <random>
#include "ColorPalette.h"


ColorPalette* ColorPalette::instance = nullptr;


ColorPalette* ColorPalette::getInstance() {

    if (!instance){
        instance = new ColorPalette();
    }
    return instance;
}

ColorName ColorPalette::getRandomColor() {
    std::list<ColorName>::iterator begin = piece_colors.begin();

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> colorrnd(0,17); // distribution in range [1, 6]
    unsigned long k = colorrnd(rng);

    std::advance(begin, k);

    /**///std::cout << "[DEBUG]: (ColorPalette:getRandomColor) Color generated --> " << *begin << " --- k: " << k << std::endl;

    return (*begin);
}

ALLEGRO_COLOR ColorPalette::getColor(ColorName color) {
    return colors[color];
}

ColorPalette::ColorPalette() {
    colors[ColorName::blue] = ALLEGRO_COLOR(al_map_rgb(33,150,243));
    colors[ColorName::brown] = ALLEGRO_COLOR(al_map_rgb(121,85,72));
    colors[ColorName::cyan] = ALLEGRO_COLOR(al_map_rgb(0,188,212));
    colors[ColorName::green] = ALLEGRO_COLOR(al_map_rgb(76,175,80));
    colors[ColorName::grey] = ALLEGRO_COLOR(al_map_rgb(158,158,158));
    colors[ColorName::orange] = ALLEGRO_COLOR(al_map_rgb(255,152,0));
    colors[ColorName::indigo] = ALLEGRO_COLOR(al_map_rgb(63,81,181));
    colors[ColorName::pink] = ALLEGRO_COLOR(al_map_rgb(233,30,99));
    colors[ColorName::purple] = ALLEGRO_COLOR(al_map_rgb(156,39,176));
    colors[ColorName::red] = ALLEGRO_COLOR(al_map_rgb(244,67,54));
    colors[ColorName::teal] = ALLEGRO_COLOR(al_map_rgb(0,150,136));
    colors[ColorName::black] = ALLEGRO_COLOR(al_map_rgb(0,0,0));
    colors[ColorName::bluegrey] = ALLEGRO_COLOR(al_map_rgb(96,125,139));
    colors[ColorName::lime] = ALLEGRO_COLOR(al_map_rgb(205,220,57));
    colors[ColorName::yellow] = ALLEGRO_COLOR(al_map_rgb(255,235,59));
    colors[ColorName::white] = ALLEGRO_COLOR(al_map_rgb(255,255,255));

    for (std::map<ColorName,ALLEGRO_COLOR>::iterator it = colors.begin(); it != colors.end(); ++it){
        piece_colors.push_back((*it).first);
    }
}

void ColorPalette::removeSystemColor(ColorName color) {
    piece_colors.push_back(color);
    system_colors.remove(color);
}

void ColorPalette::setSystemColor(ColorName color) {
    system_colors.push_back(color);
    piece_colors.remove(color);
}
