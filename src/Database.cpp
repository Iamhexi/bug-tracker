#include "Database.hpp"
#include <unistd.h>
#include <map>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <exception>

row Database::retrievedRecords;
bugVector Database::retrievedBugs;
usersSummary Database::retrievedUsers;
UserRole Database::retrievedUserRole;

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
    return !sqlite3_exec(db, query.c_str(), emptyCallback, (void*)data.c_str(), NULL);
}

usersSummary Database::getUsersSummary(string_view sql)
{
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, query.c_str(), userSummaryCallback, (void*)data.c_str(), NULL);

    return retrievedUsers;
}

row Database::getCredentialsMap(string_view sql) 
{
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, query.c_str(), getRowsCallback, (void*)data.c_str(), NULL);

    return retrievedRecords;
}

bugVector Database::getBugVector(string_view sql)
{
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, query.c_str(), bugCallback, (void*)data.c_str(), NULL);
    return retrievedBugs;
}

UserRole Database::getUserRole(string_view sql)
{
    string query = string(sql);
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, query.c_str(), userRoleCallback, (void*)data.c_str(), NULL);
    return retrievedUserRole;
}

int Database::userRoleCallback(void* data, int argc, char** argv, char** azColName)
{
    string roleNumberAsString = argv[0] == NULL ? "" : argv[0];
    
    if (roleNumberAsString.size() == 0)
        return 1;

    retrievedUserRole = static_cast<UserRole>( std::stoi(roleNumberAsString) );
    return 0;
}

int Database::userSummaryCallback(void* data, int argc, char** argv, char** azColName)
{
    usersSummary summary;
    constexpr unsigned int columnsPerUserInTable = 2;
    for (int i = 0; i < argc; i += columnsPerUserInTable) 
    {
        string username = string(argv[i]);
        UserRole role = static_cast<UserRole>( std::stoi( string(argv[i+1]) ) );

        summary.insert( std::pair<string, UserRole>(username, role) );
    }

    retrievedUsers.insert(summary.begin(), summary.end());
    return 0;
}


int Database::bugCallback(void* data, int argc, char** argv, char** azColName)
{
    bugVector bugs;
    constexpr unsigned int columnsPerUserInTable = 8;
    for (int i = 0; i < argc; i += columnsPerUserInTable) 
    {
        int id = std::stoi( string(argv[i]) );
        string description = string(argv[i+1]);
        
        double reportedAt = std::stod( string(argv[i+2]) );
        double assignedAt = std::stod( string(argv[i+3]) );
        double solvedAt = std::stod( string(argv[i+4]) );

        string reportedBy = string(argv[i+5]);
        string assignedBy = string(argv[i+6]);
        string assignedTo = string(argv[i+7]);
        
        Bug bug(id, description, reportedAt, assignedAt, solvedAt, reportedBy, assignedBy, assignedTo);
        bugs.push_back(bug);
    }
    
    // azColName[i] - a column name
    // argv[i] - a value of the record for this column
    
    retrievedBugs.insert(retrievedBugs.end(), bugs.begin(), bugs.end());
    return 0;
}

int Database::emptyCallback(void* data, int argc, char** argv, char** azColName)
{
    return 0;
}

int Database::getRowsCallback(void* data, int argc, char** argv, char** azColName)
{
    row credentials;
    for (int i = 0; i < argc; i += 2) 
        credentials.insert( std::pair<string, string>(argv[i], argv[i+1] ) );
    
    retrievedRecords.insert(credentials.begin(), credentials.end());
    return 0;
}



