#include <map>
#include <string>
#include <string_view>
#include <sqlite3.h>

using std::string, std::string_view;
using row = std::map<string, string>;

class Database 
{
private:
    string databaseSourceFile = string("credentials.db");
    string table = string("credentials");
    sqlite3* db;
public: 
    Database();
    ~Database();
    void execute(string_view sql);
    row getRow(string_view sql);
};

struct DatabaseException : public std::exception {
   const char * what () const throw () {
      return "Could not connect with the database";
   }
};