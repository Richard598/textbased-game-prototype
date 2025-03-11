#pragma once

#include<iostream>
#include <thread>  
#include <chrono>
#include <ncurses.h> 
#include "screen.h"
#include "text.h"

using namespace std;

class Game {
    public:
        bool finish;
        Game() {
            this->finish=false;
        };
        void mainloop(Screen& screen);
};