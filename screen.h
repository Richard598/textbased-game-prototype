#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Screen {
    public:
        vector<string> bufferfront, bufferback;
        Screen();
        void draw(int& x, int& y, vector<string> content);
        void refreshfront();
        void render();
};