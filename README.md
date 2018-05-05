# DeConnect-client
Terminal chat for linux systems, encrypted with aes-256-cbc. Powered by ncurses.

## SETUP
  1. cd ~
  1. git clone https://github.com/DsDeesu/DeConnect-client.git
  1. cd DeConnect-client
  1. mkdir bin
  1. g++ main.cpp -lncurses -lpthread -o bin/client
  1. cd bin
  1. mkdir keys
  1. copy [server public key](https://github.com/DsDeesu/DeConnect-server) to directory ~/DeConnect-client/bin/keys/public.key
  1. ~/DeConnect-client/bin/client

## Features
 * Full messages encryption with aes-256-cbc.
 * Aes key is randomly generated every connection.
 * Aes key changing is done using rsa 4096 encryption.
 * Full color support.
    * blue - me
    * green - others
    * red - server
 * The opportunity to change port/ip via cli.

## For more information check [server repository](https://github.com/DsDeesu/DeConnect-server "DeConnect Server")

## Screenshots
![](https://files.empleador.pl/deconnect/date.png)
![](https://files.empleador.pl/deconnect/wodate.png)
