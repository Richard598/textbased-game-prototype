#include "input.h"

Input::Input() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios; // save a copy of original terminal settings
    new_termios.c_lflag &= ~(ICANON | ECHO); //turn off echo and canonical mode
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("\033[?25l"); //hide cursor

    atexit(end);
}

void Input::end() {
    printf("\033[m"); //reset colour setting
    printf("\033[?25h"); //show cursor
    fflush(stdout);
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

char Input::get_key() {
    char ch = -1;
    int n = read(STDIN_FILENO, &ch, 1); 
    return ch;
}