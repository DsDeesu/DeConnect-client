void chatwindow_messageWindow()
{
    wclear(input_window);

    chatwindow_message_area(message_window,message_rows,message_columns,show_date);

    refresh();
    wrefresh(message_window);

    curs_set(1);
    move(main_rows-4,2);
}


void chatwindow_inputWindow()
{
    curs_set(1);
    wclear(input_window);
    //write input area with input_text
    chatwindow_input_area(input_window,input_text,input_rows,input_columns);
    refresh();
    wrefresh(input_window);
}

void chatwindow_messageReceiver()
{
    char buffer[4096];
    bzero(buffer,4096);
    while(true)
    {
        if(read(fd,buffer,4096) > 0)
        {
            chatwindow_get_struct_from_string(connection_decryptstring(buffer));
            chatwindow_messageWindow();
            chatwindow_inputWindow();
            bzero(buffer,4096);
        }
        else
            break;
    }
    menu_criticalerror("Server closed connection..");
}

void chatwindow_audiomanager()
{
    while(true)
    {
        if(new_message)
        {
            system("mplayer notification.mp3 > /dev/null 2>&1");
            new_message = false;
        }
    }
}

void chatwindow_window()
{

    ///debug
    get_messages(); //get messages (for this example from file message.txt)


//    static int main_rows, main_columns;
//    static WINDOW *message_window;
//    static WINDOW *input_window;
//    static int message_rows, message_columns;
//    static int input_rows, input_columns;
//
//    static int input;
//    static int how_much_scroll_up=0;
//
//    static string input_text="";
//    static bool show_date = false;


    thread t_chatreceiver(chatwindow_messageReceiver);
    thread t_audio(chatwindow_audiomanager);

    while(true) // keep chat window alive | back here ONLY if window size get changed
    {
        //create screen and capture sepcial characters

        clear();
        //get size of main window
        getmaxyx(stdscr, main_rows, main_columns);

        //create subwindows
        input_window = newwin(3,main_columns-2,main_rows-4,1);
        message_window = newwin(main_rows-7,main_columns-2,1,1);

        wbkgd(input_window,COLOR_PAIR(textgui_PAIR_DEFAULT));
        wbkgd(message_window,COLOR_PAIR(textgui_PAIR_DEFAULT));

        //get size from subwindows
        getmaxyx(input_window,input_rows,input_columns);
        getmaxyx(message_window,message_rows,message_columns);

        //write this line which separate window
        for(int i=1; i<main_columns-1; i++)
        {
            mvprintw(main_rows - 5,i,"=");
        }

        refresh();
        wrefresh(input_window);
        wrefresh(message_window);

        //display border
        clearscreen(main_rows,main_columns);
        do // message area, come back here if something on message_area will be changed
        {

            chatwindow_messageWindow();

            do //input area, come here if something on  input area get changed
            {

                chatwindow_inputWindow();
                input = getch();

                //if user press backspace, delete one character in the end
                if(input == 263)
                {
                    if(input_text.length() != 0)
                        input_text.pop_back();
                }

                //arrow up (scroll up)
                else if(input == 259)
                {
                    how_much_scroll_up++;
                }

                //arrow down (scroll down)
                else if(input == 258)
                {
                    if(how_much_scroll_up > 0)
                        how_much_scroll_up--;
                }

                //if pressed ctrl + D show/hide date
                else if(input == 4)
                {
                    show_date = !show_date;
                }

                //if user press enter
                else if(input == 10)
                {
                    //if message is not empty
                    if(input_text.length() != 0)
                    {
                        bool onlyspaces=true;
                        for(int i=0; i < input_text.length(); i++) //chech if there isn't only spaces
                        {
                            if(input_text[i] != ' ')
                            {
                                onlyspaces=false;
                            }
                        }
                        if(!onlyspaces) //if no, send message to list and display it
                        {
                            chatwindow_sendmessage(input_text);
                            input_text = ""; // and clean input for new messages
                        }
                    }
                }

                //if user press ctrl + H
                else if(input == 8)
                {
//             chatwindow_showhelp();
                }
                //if user pressed smt in 32..126 ONLY then add this to input_text (ASCII table is useful here ;p)
                else if((input >= 32) && (input <= 126))
                {
                    input_text += (char) input;
                }
            } //repeat till window get resized or enter/ctrl + D get pressed
            while(input != 410 && input != 4 && input != 259 && input != 258);
        }//repeat till enter will be pressed
        while(input != 410);
        delwin(message_window);
        delwin(input_window);
    }
}




