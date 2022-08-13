#pragma once
#include <map>
#include <vector>
#include <string>
#include <string_view>
#include <sqlite3.h>
#include "UserRole.hpp"
#include "UserManager.hpp"
#include "BugManager.hpp"

using usersSummary = std::map<std::string, UserRole>;
using std::string, std::string_view;
using row = std::map<string, string>;
using bugVector = std::vector<Bug>;
using userVector = std::vector<std::shared_ptr<User>>;


class Database 
{
private:
    static constexpr string_view databaseSourceFile {"../db/credentials.db"};
    sqlite3* db;

    static row retrievedRecords;
    static bugVector retrievedBugs;
    static userVector retrievedUsers;
    static UserRole retrievedUserRole;
public: 
    Database();
    ~Database();
    bool execute(string_view sql);
    row getCredentialsMap(string_view sql);
    bugVector getBugVector(string_view sql);
    userVector getUserVector(string_view sql);
    UserRole getUserRole(string_view sql);


private:
    static int getRowsCallback(void* data, int argc, char** argv, char** azColName);
    static int emptyCallback(void* data, int argc, char** argv, char** azColName);
    static int bugCallback(void* data, int argc, char** argv, char** azColName);
    static int userCallback(void* data, int argc, char** argv, char** azColName);
    static int userRoleCallback(void* data, int argc, char** argv, char** azColName);
};

struct DatabaseException : public std::exception {
   const char * what () const throw () {
      return "Could not connect with the database";
   }
};