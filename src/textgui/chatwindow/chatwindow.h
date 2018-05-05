struct message_struct
{
    string nick;
    string message;
    string date;
};

vector<message_struct> listOfMessages;


//inputArea
void chatwindow_input_area(WINDOW *window, string text, int rows, int col);
void chatwindow_sendmessage(string msg);

//messageArea
int chatwindow_message_area(WINDOW *window, int rows, int cols, bool show_date);
void chatwindow_get_struct_from_string(string line);

//main
void chatwindow_window();


bool new_message=false;
int main_rows, main_columns;
WINDOW *message_window;
WINDOW *input_window;
int message_rows, message_columns;
int input_rows, input_columns;

int input;
int how_much_scroll_up=0;

string input_text="";
bool show_date = false;



///temporary replace with recv
void get_messages()
{
/// Create list of messages
    //get line's from file
    fstream file;
    file.open("messages.txt");
    string line="";
    listOfMessages.clear();

    while(getline(file,line))
    {
        if(!line.empty())
            chatwindow_get_struct_from_string(line);
    }

    file.close();
}
///



//void chatwindow_showhelp();
#include "window.h"
#include "messageArea.h"
#include "inputArea.h"



