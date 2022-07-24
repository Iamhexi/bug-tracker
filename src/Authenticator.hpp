#include <iostream>
#include <string_view>

using std::string_view, std::string;

class Authenticator
{
private:
    string correctHash;
public:
    Authenticator();
    void login();
private:
    bool usernameExists(string_view username, string_view password);
    string hashPassword(string_view password);
    bool passwordMatchesUsername();
    bool loadCorrectHash();
};