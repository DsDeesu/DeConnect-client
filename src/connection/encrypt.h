#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

string exec(const char* cmd);
string connection_decryptstring(string msg)
{
return exec(("echo "+msg+" | openssl aes-256-cbc -a -A -d -salt -md sha256 -k '"+aes_key+"' | base64 -d | tr -d '\n'").c_str());
}

string connection_encryptstring(string msg)
{
    fstream msg_file;
    msg_file.open(to_string(fd),ios::out);
    msg_file << msg;
    msg_file.close();
    string encrypted_msg_file = exec(("base64 "+to_string(fd)+" | openssl aes-256-cbc -a -A -e -salt -md sha256 -k '"+aes_key+"' | tr -d '\n'").c_str());
    //exit(0);
    remove(to_string(fd).c_str());
    return encrypted_msg_file;
}

string connection_sha256(string word)
{
    return exec(("echo '"+word+"' | sha256sum | tr -d ' -' | tr -d '\n'").c_str());
}

//Created by waqas and edited by Curious on stackoverflow.com
//http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c-using-posix
string exec(const char* cmd)
{
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw runtime_error("popen() failed!");
    while (!feof(pipe.get()))
    {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}
