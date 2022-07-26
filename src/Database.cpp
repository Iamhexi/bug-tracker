#include "Database.hpp"
#include <cstddef>
#include <iostream>
#include <exception>

Database::Database() 
{
    int returnCode = sqlite3_open(databaseSourceFile.data(), &db);
    if (returnCode > 0)
        throw new DatabaseException();
}

Database::~Database()
{
    sqlite3_close(db);
}

void Database::execute(string_view sql) 
{
    // TODO 
    //the sqlite3_prepare/sqlite3_step/sqlite3_finalize API
    // would look like this: https://stackoverflow.com/questions/14437433/proper-use-of-callback-function-of-sqlite3-in-c
}

row Database::getRow(string_view sql) 
{
    return row();
}


