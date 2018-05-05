int chatwindow_message_area(WINDOW *window, int rows, int cols, bool show_date)
{
    //clean message area with spaces
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            mvwprintw(window,i,j," ");
        }
    }

    //start displaying messages
    int messages_count = listOfMessages.size() - 1; // cuz we will be start counting from 0

    //every message need 3 lines, 6 lines is for input area + upper line
    //we need check if already all messages arent on screen
    //if so we can zero needed scroll up count
    //and should be +1 for decremntating messages_count
    if(messages_count * 3 + 6 <= rows)
        how_much_scroll_up=0;

    //if last message will be displayed (check loop for more details)
    //this bool is setting to true
    static bool last_message_displayed=false;

    //max scroll when last message is showed
    static int max_scroll=0;
    if(last_message_displayed)
    {
        if(how_much_scroll_up>max_scroll)
        {
            how_much_scroll_up = max_scroll;
        }
        else
        {
            last_message_displayed=false;
        }

    }

    //for every message in messages list
    for(int i=messages_count-how_much_scroll_up; i>=0; i--)
    {

        int PAIR_TO_DISPLAY;

        if(listOfMessages[i].nick == user_nick)
            PAIR_TO_DISPLAY = textgui_PAIR_SELF;

        else if(listOfMessages[i].nick == "SERVER")
            PAIR_TO_DISPLAY = textgui_PAIR_SERVER;

        else
            PAIR_TO_DISPLAY = textgui_PAIR_OTHERS;


        wattron(window,COLOR_PAIR(PAIR_TO_DISPLAY));

        if(listOfMessages[i].nick != user_nick)
            mvwprintw(window,rows-2,1,listOfMessages[i].nick.c_str());
        else
            mvwprintw(window,rows-2,1,"me");



        if(show_date)
        {
            string year = listOfMessages[i].date.substr(0,4).c_str();
            string month = listOfMessages[i].date.substr(4,2).c_str();
            string day = listOfMessages[i].date.substr(6,2).c_str();
            string hour = listOfMessages[i].date.substr(8,2).c_str();
            string minute = listOfMessages[i].date.substr(10,2).c_str();
            string date_string = hour+":"+minute+" "+day+"/"+month+"/"+year+" ";

            mvwprintw(window,rows-2,cols-date_string.length()-2,date_string.c_str());
        }

        wattroff(window,COLOR_PAIR(PAIR_TO_DISPLAY));

        //display message
        mvwprintw(window,rows-1,2,listOfMessages[i].message.c_str());

        //if last message (i) when scrolling (j>0) (cuz j=0 mean window is good size to show last message)
        //then change bool to true, and lock scrolling at this level
        if((rows>=0) && (i<=0))
        {
            last_message_displayed=true;
            max_scroll = how_much_scroll_up;
        }

        rows--;// Because every message
        rows--;// need three lines
        rows--;// to be displayed
    }

    if(last_message_displayed)
        return max_scroll;
    else
        return -1;
}


void chatwindow_get_struct_from_string(string line)
{
    ///string format YYYYMMDDHHmmNLnickmessage

    string date = line.substr(0,12).c_str();
    int nick_len = atoi(line.substr(12,2).c_str());
    string nick = line.substr(14,nick_len);
    if(nick != user_nick)
        new_message = true;
    string message = line.substr(nick_len+14,line.length());
    message_struct messagestruct;
    messagestruct.date = date;
    messagestruct.nick = nick;
    messagestruct.message =  message;
    listOfMessages.push_back(messagestruct);
}
