#include "text.h"
#include "screen.h"
#include "game.h"
#include<iostream>

using namespace std;

int main() {
    Screen screen(10,30);
    Game game;
    game.mainloop(screen);
    cout << endl;
    return 0;
}