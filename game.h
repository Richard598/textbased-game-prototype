#pragma once

#include<iostream>
#include <thread>  
#include <chrono> 
#include "screen.h"
#include "text.h"
#include "input.h"

using namespace std;

class Game {
    public:
        bool finish;
        Game() {
            this->finish=false;
        };
        void mainloop(Screen& screen);
};