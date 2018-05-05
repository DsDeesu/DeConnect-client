//menu function, which need string array and sizeof of this array (IMPORTANT, MENU STARTS COUNTING FROM 0)
int menu_menu(string selections[], int array_length)
{

    //how many selections is
    int selections_count = array_length / sizeof(selections[0]);

    int minimal = 0; ///START COUNTING FROM 0
    int maximal = selections_count-1;
    int choice = 0;
    int input_char;


    while(true)
    {
        //set variables
        int rows,cols;
        getmaxyx(stdscr, rows, cols);

        //wrie border
        clear();
        clearscreen(rows,cols);

        //if pressed upper arrow
        if(input_char == 259 && choice != minimal)
        {
            choice--;
        }
        //if pressed lower arrow
        else if(input_char == 258 && choice != maximal)
        {
            choice++;
        }
        //if pressed enter
        if(input_char == 10)
        {
            return choice;
        }

        //divide selections to upper (above rows/2), and lower (under rows/2)
        int selections_half = selections_count / 2;

        //is this number even? If so, then arrange every selection by empty middle, otherwise
        //$selectnion_half selection put in the middle
        int is_even=0;
        if(selections_count % 2 == 0)
            is_even=1;

            //if selected is middle selection, then colorize it
            if(selections_half == choice) attron(A_REVERSE);
        //display middle selection, if there is even number of selection, move it one to bottom
        //and leave empty middle row
        mvprintw(rows/2+is_even,(cols/2) - (selections[selections_half].length()/2), selections[selections_half].c_str());
            //disable reverse color
            attroff(A_REVERSE);

            //for uppers selections!
        for(int j=2,i=selections_half-1; i>=0; i--)
        {
            attroff(A_REVERSE);
            if(i == choice) attron(A_REVERSE);
            mvprintw(rows/2-j+is_even,(cols/2)-(selections[i].length()/2),selections[i].c_str());
            j = j + 2; // j is space between options
        }

            //for lowers selections!
        for(int j=2,i=selections_half+1; i<=selections_count; i++)
        {
            attroff(A_REVERSE);
            if(i == choice) attron(A_REVERSE);
            mvprintw(rows/2+j+is_even,(cols/2)-(selections[i].length()/2),selections[i].c_str());
            j = j + 2; // j is space between options
        }
        input_char = getch();
    }
}


//int menu_menu()
//{
//    //show welcome screen
//    menu_welcomescreen();
//
//    string login_message = "Login";
//    string settings_message = "Settings";
//    string exit_message = "Exit";
//
//    int minimal = 1;
//    int maximal = 3;
//    int choice = 1;
//    int input_char;
//
//
//    while(true)
//    {
//        //set variables
//        int rows,cols;
//        getmaxyx(stdscr, rows, cols);
//
//        //wrie border
//        clear();
//        clearscreen(rows,cols);
//
//        if(input_char == 259 && choice != minimal)
//        {
//            choice--;
//        }
//        else if(input_char == 258 && choice != maximal)
//        {
//            choice++;
//        }
//
//        if(input_char == 10)
//        {
//            if(choice == maximal)
//                return 0;
//            else
//                return choice;
//        }
//
//        mvprintw(rows / 2 - 3, (cols / 2) - (login_message.length() / 2), login_message.c_str());
//        mvprintw(rows / 2, (cols / 2) - (settings_message.length() / 2 - 1), settings_message.c_str());
//        mvprintw(rows / 2 + 3, (cols / 2) - (exit_message.length() / 2), exit_message.c_str());
//        //mvprintw(rows-3,cols-5,to_string(choice).c_str());
//
//        switch(choice)
//        {
//        case 1:
//            attron(A_REVERSE);
//            mvprintw(rows / 2 - 3, (cols / 2) - (login_message.length() / 2), login_message.c_str());
//            break;
//        case 2:
//            attron(A_REVERSE);
//            mvprintw(rows / 2, (cols / 2) - (settings_message.length() / 2 - 1), settings_message.c_str());
//            break;
//        case 3:
//            attron(A_REVERSE);
//            mvprintw(rows / 2 + 3, (cols / 2) - (exit_message.length() / 2), exit_message.c_str());
//            break;
//        }
//        attroff(A_REVERSE);
//        input_char = getch();
//        if(input_char == 410)
//            input_char = 1;
//    }
//}
