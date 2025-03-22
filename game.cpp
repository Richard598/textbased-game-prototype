#include "game.h"


void Game::mainloop(Screen& screen){
    int a=0,b=0;
    Input input;
    while(!this->finish) {
        this_thread::sleep_for(chrono::milliseconds(50));
        char ch = input.get_key();
        if(ch == 'A' || ch == 'a') {
            screen.draw(a,b,Aletter);
            screen.render();
        }
        else if(ch == 'D' || ch == 'd') {
            screen.draw(a,b,Dletter);
            screen.render();
        }
        else if(ch == 'W' || ch == 'w') {
            screen.draw(a,b,Wletter);
            screen.render();
        }   
        else if(ch == 'S' || ch == 's') {
            screen.draw(a,b,Sletter);
            screen.render();
        }   
        else if(ch == 'E' || ch == 'e')
            this->finish = true;
    }
}