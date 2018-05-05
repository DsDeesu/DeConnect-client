void args_debug()
{

    if(connection_connect())
    {
        cout << "Key: " << aes_key << endl;
        string login, password;
        cout << "Login: ";
        cin >> login;
        password = getpass("Password: ");

        login = connection_encryptstring(login);
        password = connection_encryptstring(connection_sha256(password));
        printf("Enc Login: A|%s|A\nEnc Pass: A|%s|A\n",login.c_str(),password.c_str());

        cout << "Sending login\n";
        send(fd,login.c_str(),login.length(),0);

        cout << "Receiving +\n";
        char c[1];
        read(fd,c,1);

        cout << "Sending Pass\n";
        send(fd,password.c_str(),password.length(),0);

        read(fd,c,1);
        cout << c << endl;

        char buffer[2048];
        bzero(buffer,2048);
        read(fd,buffer,2048);
        cout << "Received: " << buffer << endl;
        cout << "Serv Mess: " << connection_decryptstring(buffer) << endl;
        cout << "Mess to send: ";
        string msg_to_send;//getline(cin,msg_to_send);
        cin >> msg_to_send;

        chatwindow_sendmessage(msg_to_send);

        bzero(buffer,2048);
        read(fd,buffer,2048);

        cout << "\n\nReceived encrypted: " << buffer << endl;
        cout << "Received decrypted: " << connection_decryptstring(buffer) << endl;


        chatwindow_get_struct_from_string(connection_decryptstring(buffer));

        for(int i=0; i<listOfMessages.size(); i++)
        {
            cout << "Mess nr: " << i << endl;
            cout << listOfMessages[i].date << endl;
            cout << listOfMessages[i].nick << endl;
            cout << listOfMessages[i].message << endl << endl;
        }
    }
    else
    {
        cout << "Error when connecting.." << endl;
    }
    close(fd);
    exit(0);
}
