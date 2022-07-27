#include "src/Database.hpp"

int main()
{
    Database db;
    db.execute("SELECT * FROM credentials;");


    return 0;
}