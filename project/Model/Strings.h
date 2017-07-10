//
// Created by lifka on 5/07/17.
//

#ifndef PROJECT_STRINGS_H
#define PROJECT_STRINGS_H


class Strings {
private:

    Strings(){};

    static Strings* instance;
    Strings& operator=(Strings const&){};
    Strings(Strings const&){};

    const char* score = "Score";
    const char* level = "Level";
    const char* next_piece = "Next piece";
    const char* title = "Tetris";
    const char* gameover = "GAME OVER";
    const char* pressToRestart = "Press R to restart";
public:
    const char *getScore() const;
    const char *getLevel() const;
    const char *getNext_piece() const;
    const char *getTitle() const;
    const char *getGameOver() const;
    const char *getPressToRestart() const;

    static Strings* getInstance();
};


#endif //PROJECT_STRINGS_H
