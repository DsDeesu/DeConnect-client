#include "include.h"

///debug
int PORTNUMBER = 12121;
char* SERVERIP = "127.0.0.1";


string user_nick="";
string client_title="DeConnect";
int fd=0;

string aes_key="";

#include "src/connection/connection.h"
#include "src/textgui/textgui.h"
#include "src/arguments/arguments.h"
