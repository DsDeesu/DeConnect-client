void menu_errorwindow(string msg)
{
    do
    {
        clear();
        int rows,cols;
        getmaxyx(stdscr,rows,cols);
        clearscreen(rows,cols);
        keypad(stdscr, true);
        noecho();
        mvprintw(rows/2,cols/2-(msg.length()/2),msg.c_str());
    }
    while(getch() == 410);
}

void menu_criticalerror(string msg)
{
    do
    {
        clear();
        int rows,cols;
        getmaxyx(stdscr,rows,cols);
        clearscreen(rows,cols);
        keypad(stdscr, true);
        noecho();
        mvprintw(rows/2,cols/2-(msg.length()/2),msg.c_str());
    }
    while(getch() == 410);
    close(fd);
    endwin();
    exit(0);
}
