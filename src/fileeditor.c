#include "fileeditor.h"

#define QUIT 0
#define SAVE 1

/**
* draws an empty box of symbols
* IN: width of box, height of box, symbol to draw
* OUT: void
* POST: Box is drawn, refresh is called
*/
void drawBoarder(int w, int h, char symbol);

/*func comment here*/
void printOnLine(int line, char* string);

/*function comment here*/
int inputLoop(int w, int h, char* input);

int main() {
    char input[512];
    int exitState;

    //init ncurses
    initscr();
    cbreak();
    noecho();

    //program init
    drawBoarder(50, 15, '#');
    printOnLine(16, "; to quit");
    printOnLine(17, "[ to save to file");

    exitState = inputLoop(50, 15, input);

    //deinit ncurses
    endwin();

    //quit condition
    if (exitState == QUIT) {
        printf("%s\n", input);
    } else if (exitState == SAVE) {
        //save to a file
        printf("Saved to text.txt\n");
    }

    return 0;
}

void drawBoarder(int w, int h, char symbol) {
    int x;
    int y=0;

    //top wall
    for (x=0; x<w; x++) {
        mvaddch(y, x, symbol);
    }
    //right wall
    for (y=0; y<h; y++) {
        mvaddch(y, x, symbol);
    }
    //bottom wall
    for (x=0; x<w; x++) {
        mvaddch(y, x, symbol);
    }
    //left wall
    x=0;
    for (y=0; y<h; y++) {
        mvaddch(y, x, symbol);
    }
    refresh();
}

void printOnLine(int line, char* string) {
    mvwprintw (stdscr, line, 0, string);
    refresh();
}

int inputLoop(int w, int h, char* input) {
    //Position of cursor
    int xpos=1;
    int ypos=1;

    char in;
    int inLength=0;

    move(ypos, xpos);
    refresh();
    do {
        in = getch();
        input[inLength] = in;
        inLength++;

        xpos++;
        if (xpos == w) {
            xpos = 1;
            ypos++;
        }

        mvaddch(ypos, xpos, in);
        refresh();
    } while (in != ';' && in != '[');

    if (in == ';')
        return QUIT;
    else
        return SAVE;
}
