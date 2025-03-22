#pragma once

#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<iostream>

static struct termios orig_termios, new_termios;

using namespace std;

class Input {     
    public:
        Input();
        char get_key();
        static void end();
};

