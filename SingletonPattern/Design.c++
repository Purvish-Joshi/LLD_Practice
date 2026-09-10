#include <iostream>
#include <string>
using namespace std;

class DatabaseConnectionManager
{
private:
    DatabaseConnectionManager() {};
    bool isConnected = false;

public:
    static DatabaseConnectionManager &getInstance()
    {
        static DatabaseConnectionManager instance;
        return instance;
    }

    void connect()
    {
        cout << "the Database is connected" << endl;
        isConnected = true;
    }

    void disconnect()
    {
        cout << "the Database has been disconnected" << endl;
        isConnected = false;
    }

    void executeQuery(const string &query)
    {
        if (!isConnected)
        {
            cout << "the database is not connected" << endl;
        }
        else
        {
            cout << " the following Query has been executed:" << query << endl;
        }
    }
};

int main()
{

    auto &db1 = DatabaseConnectionManager::getInstance();
    auto &db2 = DatabaseConnectionManager::getInstance();

    db1.connect();
    db2.executeQuery("SELECT * FROM users");
    db2.disconnect();

    return 0;
}