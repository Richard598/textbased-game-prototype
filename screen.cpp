#include "screen.h"
#include <sys/ioctl.h>
#include <unistd.h>

Screen::Screen() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    this->bufferfront.resize(w.ws_row);
    for(int i=0; i<w.ws_row; i++)
        this->bufferfront[i].assign(w.ws_col, ' ');
    this->bufferback.resize(w.ws_row);
    for(int i=0; i<w.ws_row; i++)
        this->bufferback[i].assign(w.ws_col, ' ');
}

void Screen::draw(int& x, int& y, vector<string> content) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    x = w.ws_row/2-2;
    y = w.ws_col/2-2;
    for(int i=0; i<content.size();i++)
        for(int j=0; j<content[i].size(); j++) {
            if(x+i < this->bufferfront.size() && y+j < this->bufferfront[0].size()) {
                this->bufferfront[x+i][y+j] = content[i][j];
            }
        }
}

void Screen::refreshfront() {
    for(int i=0; i<this->bufferback.size(); i++)
        this->bufferfront[i].assign(this->bufferback[0].size(), ' ');
}

void Screen::render() {
    for(int i=0; i<this->bufferfront.size(); i++)
        for(int j=0; j<this->bufferfront[i].size(); j++) {
            if(1) {
                cout << "\033[" << i+1 << ";" << j+1 << "H";
                cout << this->bufferfront[i][j];
            }
        }
    vector<string> copy(this->bufferfront);
    this->bufferback = copy;
    this->refreshfront();
}