#include "client.h"


void signal_handler(int signum)
{
    endwin();
    cout << "Received signal " << signum << ". Terminating program.." << endl << endl;
    close(fd);
    endwin();
    exit(0);
}


int main(int argc, char *argv[])
{
    signal(SIGINT,signal_handler);

    args_args(argc,argv);

    textgui();
    close(fd);
    return 0;

}


