void menu_settings_submenu_color_changer(int which);

void menu_settings_submenu_colors()
{
    clear();
    int rows,cols;
    getmaxyx(stdscr,rows,cols);
    clearscreen(rows,cols);
    string selections[] = {"Self","Server","Others","Default","Return"};
    switch(menu_menu(selections,sizeof(selections)))
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void menu_settings_submenu_color_changer(int which)
{

}
