#include <iostream>
#include <string_view>

using std::string_view;

class Authenticator
{
public:
    void login();
private:
    bool usernameExists(string_view username, string_view password);
    string_view hashPassword(string_view password);
    bool passwordMatchesUsername();
}