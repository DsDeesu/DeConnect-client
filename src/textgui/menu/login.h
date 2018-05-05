bool menu_login()
{
    string login="";
    string password="";
    bool enter_pressed=false; //switched to password?
    int input=0;
    if(!connection_connect())
        menu_criticalerror("Error connecting to server "+(string)SERVERIP+" on port "+to_string(PORTNUMBER));

    do
    {
        //set variables
        int rows,cols;
        getmaxyx(stdscr, rows, cols);

        clear();
        clearscreen(rows,cols);

        mvprintw(rows/3-1,cols/2-2,"Login");
        mvprintw(rows/3,cols/2-(login.length()/2),login.c_str());

        //convert length of password to *** string and display it
        mvprintw(rows/2-1,cols/2-3,"Password");
        string starred_password="";
        for(int i=0; i<password.length(); i++)
        {
            starred_password += "*";
        }
        mvprintw(rows/2,cols/2-(starred_password.length()/2),starred_password.c_str());


        //if enter pressed (switched to password move cursor) - not needed when cursor is hidden
//        if(!enter_pressed)
//            move(rows/3,cols/2);
//        else
//            move(rows/2,cols/2);


        input = getch();
        // if enter and login isnt empty switch to password
        if((input == 10) && (login != ""))
        {
            enter_pressed = true;
        }
        //if input is         0..9             OR              A..Z              OR              a..z
        else if(((input >= 48) && (input <= 57) || (input >= 65) && (input <= 90) || (input >= 97) && (input <= 122)) && !enter_pressed)
        {

            if(input != 32)
                login += (char) input;
        }
        //if input is from 32..126 (ASCII table)
        else if(((input >= 32) && (input <= 126)) && enter_pressed)
        {
            password += (char) input;
        }
        //if pressed backspace
        else if(input == 263)
        {
            //login or password?
            if(!enter_pressed)
            {
                //if login length isn't 0
                if(login.length() != 0)
                    login.pop_back();
            }
            else
            {
                //if password length isn't 0
                if(password.length() != 0)
                    password.pop_back();
            }
        }
    }
    while(!(login != "" && password != "" && input == 10));

    //encrypt inserted data
    string encrypted_login = connection_encryptstring(login);
    string encrypted_password = connection_encryptstring(connection_sha256(password));

    //send encrypted login
    send(fd,encrypted_login.c_str(),encrypted_login.length(),0);

    //recv for noerr connection
    char no_error_connection[1];
    recv(fd,no_error_connection,1,0);

    //send encrypted password
    send(fd,encrypted_password.c_str(),encrypted_password.length(),0);

    //recv result of loging
    char login_status[1];
    recv(fd,login_status,1,0);
    //convert this to string

    //if credentials was wrong
    if(login_status[0] == '0')
        return false;
    //if user is already logged
    else if(login_status[0] == '2')
        menu_criticalerror("Error, you are already logged..");
    //if everything goes good
    else if(login_status[0] == '1')
    {
        user_nick = login;
        return true;
    }
    else
    {
        endwin();
        cout << "Critical error when exchanging credentials!\n";
        cout << "Status: " << login_status << endl;
        exit(0);
    }
    return false;
}
