#pragma once
#include <map>
#include <vector>
#include <string>
#include <string_view>
#include <sqlite3.h>
#include "Bug.hpp"

using std::string, std::string_view;
using row = std::map<string, string>;
using bugVector = std::vector<Bug>;

class Database 
{
private:
    string databaseSourceFile = string("../db/credentials.db");
    sqlite3* db;

    static row retrievedRecords;
    static bugVector retrievedBugs;
public: 
    Database();
    ~Database();
    bool execute(string_view sql);
    row getCredentialsMap(string_view sql);
    bugVector getBugVector(string_view sql);

private:
    static int getRowsCallback(void* data, int argc, char** argv, char** azColName);
    static int executeCallback(void* data, int argc, char** argv, char** azColName);
    static int bugCallback(void* data, int argc, char** argv, char** azColName);

};

struct DatabaseException : public std::exception {
   const char * what () const throw () {
      return "Could not connect with the database";
   }
};