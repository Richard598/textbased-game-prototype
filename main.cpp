#include "text.h"
#include "screen.h"
#include "game.h"
#include<iostream>

using namespace std;

int main() {
    Screen screen;
    Game game;
    game.mainloop(screen);
    return 0;
}