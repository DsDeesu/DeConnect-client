#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <thread>
#include <vector>
#include <signal.h>
#include <string.h>
#include <sstream>
#include <cstdlib>

#include <sys/socket.h> //socket(), bind() etc
#include <unistd.h> //close()
#include <netinet/in.h> //struct sockaddr_in
#include <arpa/inet.h> //inet_addr()

using namespace std;
