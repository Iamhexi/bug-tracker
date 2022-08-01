#include "Database.hpp"
#include <unistd.h>
#include <map>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <exception>

row Database::retrievedRecords;

Database::Database() 
{
    retrievedRecords = row();
    int returnCode = sqlite3_open(databaseSourceFile.data(), &db);
    if (returnCode > 0)
        throw new DatabaseException();
}

Database::~Database()
{
    sqlite3_close(db);
}

bool Database::execute(string_view sql) 
{
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    return !sqlite3_exec(db, query.c_str(), executeCallback, (void*)data.c_str(), NULL);
}

row Database::getRows(string_view sql) 
{
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, query.c_str(), getRowsCallback, (void*)data.c_str(), NULL);
    return retrievedRecords;
}

int Database::executeCallback(void* data, int argc, char** argv, char** azColName)
{
    return 0;
}

int Database::getRowsCallback(void* data, int argc, char** argv, char** azColName)
{
    row credentials;
    for (int i = 0; i < argc; i += 2) 
        credentials.insert( std::pair<string, string>(argv[i], string(argv[i+1]) ) );
    
    //for(auto& pair: credentials)
        //std::cout << pair.first << " " << pair.second << "\n";

    // azColName[i] - a column name
    // argv[i] - a value of the record for this column
    
    retrievedRecords = credentials;
  
    return 0;
}


