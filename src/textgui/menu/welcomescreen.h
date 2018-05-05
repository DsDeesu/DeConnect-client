void menu_welcomescreen()
{
    int input = 0;
    do
    {
        //set variables
        int rows,cols;
        getmaxyx(stdscr, rows, cols);

        //create border
        clear();
        clearscreen(rows,cols);

        //display text on screen
        string text = "[hit enter to continue]";
        mvprintw(rows / 2-1,(cols / 2) - (client_title.length() / 2), client_title.c_str());
        mvprintw(rows / 2+1,(cols / 2) - (text.length() / 2), text.c_str());

        //repeat till enter get pressed
        input = getch();
    }
    while(input != 10);
}
