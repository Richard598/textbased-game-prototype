#include "game.h"


void Game::mainloop(Screen& screen){
    int a=3,b=3;
    Input input;
    Player player;
    while(!this->finish) {
        this_thread::sleep_for(chrono::milliseconds(50));
        screen.refresh();
        screen.draw(0,0,map);
        char ch = input.get_input();
        if(ch == 'A' || ch == 'a') {
            player.move_left(screen);
        }
        else if(ch == 'D' || ch == 'd') {
            player.move_right(screen);
        }
        else if(ch == 'W' || ch == 'w') {
            player.move_up(screen);
        }   
        else if(ch == 'S' || ch == 's') {
            player.move_down(screen);
        }   
        else if(ch == 'E' || ch == 'e')
            this->finish = true;
        screen.draw(player);
        screen.render();
    }
}