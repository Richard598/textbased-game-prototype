#pragma once

#include<iostream>
#include<vector>
#include<string>
#include "player.h"

using namespace std;

class Screen {
    public:
        vector<string> buffer;
        int width,height,x_pos,y_pos;
    public:
        Screen(int height,int width);
        void draw(int x, int y, char content);
        void draw(int x, int y, string content);
        void draw(int x, int y, vector<string> content);
        void draw(Player player);
        void refresh();
        void render();
};