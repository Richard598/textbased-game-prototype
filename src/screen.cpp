#include "screen.h"
#include<stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

Screen::Screen(int height, int width) {
    printf("\033[2J");
    this->height = height;
    this->width = width;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    this->x_pos = (w.ws_row - this->height) / 2;
    this->y_pos = (w.ws_col - this->width) / 2;
    this->buffer.resize(this->height);
    for(int i=0; i<this->height; i++)
        this->buffer[i].assign(this->width, ' ');
}

void Screen::draw(int x, int y, char content) {
    if(x < this->buffer.size() && y < this->buffer[0].size()) 
            this->buffer[x][y] = content;
}

void Screen::draw(int x, int y, string content) {
    for (int i=0; i<content.length(); i++)
        this->draw(x,y+i,content[i]);
}

void Screen::draw(int x, int y, vector<string> content) {
    for(int i=0; i<content.size();i++)
        this->draw(x+i,y,content[i]);
}

void Screen::draw(Player player) {
    this->draw(player.x_pos,player.y_pos,'@');
}

void Screen::refresh() {
    for(int i=0; i<this->buffer.size(); i++)
        this->buffer[i].assign(this->buffer[0].size(), ' ');
}

void Screen::render() {
    for(int i=0; i<this->buffer.size(); i++)
        for(int j=0; j<this->buffer[i].size(); j++) {
            if(1) {
                cout << "\033[" << this->x_pos+i+1 << ";" << this->y_pos+j+1 << "H";
                cout << this->buffer[i][j];
            }
        }
}