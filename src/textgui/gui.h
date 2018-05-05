void textgui()
{
    {
        string terminal_type = getenv("TERM");
        if((terminal_type == "xterm") || (terminal_type == "xterm-256color"))
        {
            putenv("TERM=xterm-256color");
            initscr();
            start_color();
        }
        else
        {
            cout << "This terminal doesn't support colors at all. Running in black-white mode. If it you can force this function by setting envirionement variable TERM to \"xterm\"" << endl;
            getch();
            initscr();
        }
    }

    noecho();
    curs_set(0);
    keypad(stdscr,true);
    initialize_colors();

    bkgd(COLOR_PAIR(textgui_PAIR_DEFAULT));
    menu_welcomescreen();

//            while(!menu_login())
//            {
//                menu_errorwindow("Bad login and/or password.");
//            }
//            chatwindow_window();
//
//            getch();
//            exit(0);

    while(true)
    {
        string selections[] = {"Login","Settings","Exit"};
        switch(menu_menu(selections,sizeof(selections)))
        {
        case 0: //login menu
            while(!menu_login())
            {
                menu_errorwindow("Bad login and/or password.");
            }
            chatwindow_window();
            break;
        case 1: //settings menu
            menu_settings_menu();
            break;
        case 2: //exit
            endwin();
            exit(0);
            break;
        }
        clear();
    }
}
