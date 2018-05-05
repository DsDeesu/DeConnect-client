string connection_generateKey()
{
    return exec("openssl rand 200 | base64 -w 0");
}

string connection_encryptKey(string key)
{
    return exec(("echo "+key+" | openssl rsautl -encrypt -pubin -inkey keys/public.key | base64 -w 0").c_str());
}
