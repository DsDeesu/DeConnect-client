void args_args(int argc, char *argv[])
{
    for(int i=1; i<argc; i++)
    {
        string argument = argv[i];
        if((argument == "-h") || (argument == "--help"))
        {
            args_help();
            exit(0);
        }
        else if((argument == "-p") || (argument == "--port"))
        {
            PORTNUMBER = atoi(argv[i+1]);
            i++;
        }
        else if((argument == "-i") || (argument == "--ip"))
        {
            SERVERIP = argv[i+1];
            i++;
        }
        else if((argument == "-d") || (argument == "--debug"))
        {
            args_debug();
        }
        else
        {
            cout << "Unknown option " << argument << ". Use -h/--help to get more informations." << endl;
            exit(0);
        }
    }
}
