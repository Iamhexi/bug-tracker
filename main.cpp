#include "src/Authenticator.hpp"
#include <iostream>

void print_map(const std::map<std::string, std::string>& m)
{
    for (const auto& [key, value] : m) {
        std::cout << '[' << key << "] = " << value << "; ";
    }
}

int main()
{
    Database db;
    row records = db.getRows("SELECT * FROM credentials;");
    //print_map(records);


    return 0;
}