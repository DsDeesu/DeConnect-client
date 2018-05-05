void menu_settings_menu()
{
    string selections[] = {"Colors","Server IP","Server Port","Menu"};
    switch(menu_menu(selections,sizeof(selections)))
    {
    case 0:
        menu_settings_submenu_colors();
        break;
    case 1:
        menu_settings_submenu_ip();
        break;
    case 2:
        menu_settings_submenu_port();
        break;
    case 3:
        break;
    }
}
