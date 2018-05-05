void clearscreen(int rows, int columns)
{
    attron(COLOR_PAIR(textgui_PAIR_DEFAULT));
    //if size is too small
    while(rows <= 7)
    {
        string toosmaltext="Window is too small";
        do
        {
            clear();
            curs_set(0);
            mvprintw(rows/2,columns/2 - (toosmaltext.length()/2),toosmaltext.c_str());

        }//wait till user change size od window
        while(getch() != 410);
        getmaxyx(stdscr, rows, columns); //get new window size
    }

    //write border (cube)
    writeborder(rows,columns);
    attroff(COLOR_PAIR(textgui_PAIR_DEFAULT));

//    ///just debug info
//    string debug_text;
//    debug_text = "rows: ";
//    debug_text += to_string(rows);
//    debug_text += ", columns ";
//    debug_text += to_string(columns);
//    mvprintw(rows-6,columns-debug_text.length()-2,debug_text.c_str());

}

void writeborder(int row, int col)
{
    //write upper and lower line
    writeline(row, col);

    //write left and right border
    for(int i=0; i<row; i++)
    {
        mvprintw(i,0,"=");
        mvprintw(i,col-1,"=");
    }
}
void writeline(int row, int col)
{
    //write full upper and lower line (without title)
    for(int i=1; i<col-1; i++)
    {
        mvprintw(0,i,"=");
        mvprintw(row-1,i,"=");
    }

    //write title
    mvprintw(0,(col/2) - (client_title.length() / 2), client_title.c_str());
    mvprintw(row-1,(col/2) - (client_title.length() / 2), client_title.c_str());
}
