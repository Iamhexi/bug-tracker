#include "Database.hpp"
#include <map>
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
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, query.c_str(), callback, (void*)data.c_str(), NULL);
    // TODO 
    //the sqlite3_prepare/sqlite3_step/sqlite3_finalize API
    // would look like this: https://stackoverflow.com/questions/14437433/proper-use-of-callback-function-of-sqlite3-in-c
}

row Database::getRow(string_view sql) 
{
    return row();
}

int Database::callback(void* data, int argc, char** argv, char** azColName)
{
    std::map<string, string> credentials;
    for (int i = 0; i < argc; i += 2) 
        credentials.insert( std::pair<string, string>(argv[i], argv[i+1]) );

    // azColName[i] - a column name
    // argv[i] - a value of the record for this column

    for (auto& user: credentials)
        std::cout << user.first << ' ' << user.second << std::endl;
  
    return 0;
}


