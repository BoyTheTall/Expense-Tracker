#include "Transaction.hpp"
#include "sqlite3.h"
#include <vector>
#include <stdint.h>
#include <string>

class Transaction_Services{
private:
    const char* directory = "C:\\Users\\Doctor\\Documents\\C C++ projects\\expenses tracker\\transactions.db";
    sqlite3* db;
    int connection_established;//this is for checking if the connection was established
    void connect();
    std::vector<Transaction> traverse_result_set(sqlite3_stmt* stmt);
    std::vector<Transaction> getTransactionByType(bool transaction_type);
    void execute_sql(std::string sql, std::string error_msg, std::string success_msg);
    std::vector<Transaction> execute_fetch_sql(std::string sql);

public:
    std::string str_default_value = std::to_string(0);
    int num_default_value = 0;
    bool is_connected;
    Transaction_Services();
    void add_transaction(Transaction t);
    std::vector<Transaction> getAllTransactions();
    std::vector<Transaction> getAllExpenses();
    std::vector<Transaction> getTransactionsByMonthOrYear(std::string month_or_year);
    std::vector<Transaction> getTransactions(int64_t t_id = 0, std::string date = std::to_string(0), std::string category = std::to_string(0), double amount = 0);
    std::vector<Transaction> getExpenses();
    void update_transaction(Transaction t);
    void delete_transaction(Transaction t);
    ~Transaction_Services();

};
std::string generate_id();