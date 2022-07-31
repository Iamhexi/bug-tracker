#include <map>
#include <string>
#include <string_view>
#include <sqlite3.h>

using std::string, std::string_view;
using row = std::map<string, string>;

class Database 
{
private:
    string databaseSourceFile = string("../db/credentials.db");
    sqlite3* db;

    static row retrievedRecords;
public: 
    Database();
    ~Database();
    bool execute(string_view sql);
    row getRows(string_view sql);
private:
    static int getRowsCallback(void* data, int argc, char** argv, char** azColName);
    static int executeCallback(void* data, int argc, char** argv, char** azColName);
};

struct DatabaseException : public std::exception {
   const char * what () const throw () {
      return "Could not connect with the database";
   }
};