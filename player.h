#pragma once

#include<iostream>
class Screen;

using namespace std;

class Player {
    public:
        int x_pos, y_pos;
    public:
        Player();
        void move_up(Screen screen);
        void move_down(Screen screen);
        void move_left(Screen screen);
        void move_right(Screen screen);
};