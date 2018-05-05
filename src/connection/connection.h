string connection_encryptstring(string msg);
string connection_decryptstring(string msg);
string exec(const char* cmd);

string connection_generateKey();
string connection_encryptKey(string key);
string connection_sha256(string word);

bool connection_connect();


#include "connect.h"
#include "encrypt.h"
#include "generatekey.h"
