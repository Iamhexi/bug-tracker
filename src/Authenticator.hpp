#include <iostream>
#include <string_view>
#include <map>

using std::string_view, std::string, std::map;

class Authenticator
{
private:
    map<string, string> credentials;
public:
    Authenticator();
    bool login(string_view username, string_view password);
private:
    string hashPassword(string_view password);
    void loadCredentialsFromDatabase();
};