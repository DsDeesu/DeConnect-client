bool connection_connect()
{
    struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(SERVERIP);
        server_address.sin_port = htons(PORTNUMBER);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1)
        return false;
    if(connect(fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1)
        return false;

        //sending encrypted key
        aes_key = connection_generateKey();
        string encrypted_aes_key = connection_encryptKey(aes_key);
        send(fd,encrypted_aes_key.c_str(),encrypted_aes_key.length(),0);

    return true;
}
