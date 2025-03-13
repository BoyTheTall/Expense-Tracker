#include "Transaction.hpp"
#include "sqlite3.h"
#include <vector>
#include <stdint.h>
using namespace std;

class Transaction_Services{
private:
    const char* directory = "C:\\Users\\Doctor\\Documents\\C C++ projects\\expenses tracker\\transactions.db";
    sqlite3* db;
    int connection_established;//this is for checking if the connection was established
    void connect();
    vector<Transaction> traverse_result_set(sqlite3_stmt* stmt);
    vector<Transaction> getTransactionByType(bool transaction_type);

public:
    string str_default_value = to_string(0);
    int num_default_value = 0;
    bool is_connected;
    Transaction_Services();
    void add_transaction(Transaction t);
    vector<Transaction> getAllTransactions();
    vector<Transaction> getAllExpenses();
    vector<Transaction> getTransactionsByMonthOrYear(string month_or_year);
    vector<Transaction> getTransactions(int64_t t_id = 0, string date = to_string(0), string category = to_string(0), double amount = 0);
    vector<Transaction> getExpenses();
    void update_transaction(Transaction t);
    void delete_transaction(Transaction t);
    ~Transaction_Services();
};
std::string generate_id();