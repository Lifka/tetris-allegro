//
// Created by lifka on 4/07/17.
//

#ifndef PROJECT_COLORPALETTE_H
#define PROJECT_COLORPALETTE_H


#include <allegro5/color.h>
#include <map>
#include <list>
#include "ColorName.h"

class ColorPalette {

private:
    ColorPalette();
    std::map<ColorName, ALLEGRO_COLOR> colors;
    std::list<ColorName> system_colors;
    std::list<ColorName> piece_colors;

    static ColorPalette* instance;
    ColorPalette& operator=(ColorPalette const&){};
    ColorPalette(ColorPalette const&){};



public:
    static ColorPalette* getInstance();

    ColorName getRandomColor();
    ALLEGRO_COLOR getColor(ColorName);
    void removeSystemColor(ColorName);
    void setSystemColor(ColorName);


};


#endif //PROJECT_COLORPALETTE_H
