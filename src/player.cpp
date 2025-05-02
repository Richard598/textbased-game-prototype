#include "player.h"
#include "screen.h"

Player::Player() {
    this->x_pos = 5;
    this->y_pos = 5;
}

void Player::move_up(Screen screen) {
    if ( x_pos-1 <screen.buffer.size() && x_pos-1 >= 0 && screen.buffer[x_pos-1][y_pos] == ' ')
        x_pos -= 1;
}

void Player::move_down(Screen screen) {
    if ( x_pos+1 <screen.buffer.size() && x_pos+1 >= 0 && screen.buffer[x_pos+1][y_pos] == ' ')
        x_pos += 1;
}

void Player::move_left(Screen screen) {
    if ( y_pos-1 <screen.buffer[0].size() && y_pos-1 >= 0 && screen.buffer[x_pos][y_pos-1] == ' ')
        y_pos -= 1;
}

void Player::move_right(Screen screen) {
    if ( y_pos+1 <screen.buffer[0].size() && y_pos+1 >= 0 && screen.buffer[x_pos][y_pos+1] == ' ')
        y_pos += 1;
}