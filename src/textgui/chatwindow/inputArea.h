void chatwindow_input_area(WINDOW *window, string text, int rows, int col)
{
    //clear input area
    for(int i=0; i<col; i++)
    {
        mvwprintw(window,rows-3,i," ");
        mvwprintw(window,rows-2,i," ");
        mvwprintw(window,rows-1,i," ");
    }

    //write data to input area
    mvwprintw(window,0,1,text.c_str());
}
void chatwindow_sendmessage(string msg)
{
    //get information about nick(length)
    int nicklen = user_nick.length();
    string nicklenstring="";
    if(nicklen < 10)
        nicklenstring = "0"+to_string(nicklen);
    else
        nicklenstring = to_string(nicklen);

//    int message_len = msg.length();
//    for(int i=0; i<message_len; i++)
//    {
//        if(msg[i] == '\'')
//            msg += '\'';
//    }
//
//    message_len = msg.length();
//    for(int i=0; i<message_len; i++)
//    {
//        if(msg[i] == ';')
//        {
//            msg.insert(i,"\\");
//            message_len++;
//            i++;
//        }
//    }
//    endwin();
//    cout << "Mess: " << msg << endl;
//    getch();
//    exit(0);


    string msg_to_send = nicklenstring + user_nick + msg;
    string encrypted_message = connection_encryptstring(msg_to_send);
    send(fd,encrypted_message.c_str(),encrypted_message.length(),0);
}
