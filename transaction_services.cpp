#include "transaction_services.hpp"
#include <iostream>
#include "sqlite3.h"
#include <stdint.h>


//constructor that just connects to the database when the object is created
Transaction_Services::Transaction_Services(){
    connect();
}

//private function for initialising the connection. Although there'll be one constructor I dont want to copy and paste code in case i add another
void Transaction_Services::connect() {

    this->connection_established = sqlite3_open(this->directory, &this->db);
    if (connection_established != SQLITE_OK) {
        std::cerr << "Can't open the database: " << sqlite3_errmsg(db) << "\n";
        this->is_connected = false;
    }
    else {
        std::cout << "Database opened successfully" << "\n";
        this->is_connected = true;
    }

    }

//fetching functions
//this function gets all transactions of the specified type. it will be hidden from view and will be used by public facing functions. I could not really use the other functions with it because well i can't set a default value that makes sense
std::vector<Transaction> Transaction_Services::getTransactionByType(bool transaction_type){
    sqlite3_stmt* stmt;
    std::vector<Transaction> t_list;
    std::string sql = "SELECT * FROM tblTransactions WHERE Transaction_Type = " + std::to_string(transaction_type);
    int exit_code = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, nullptr);
    if(exit_code != SQLITE_OK){
        std::cerr << "Failed to prepare statement " << sqlite3_errmsg(this->db) << "\n";
    }else{
        t_list = this->traverse_result_set(stmt);
    }

    return t_list;
    }

//gets every expense.
std::vector<Transaction> Transaction_Services::getAllExpenses(){
    return this->getTransactionByType(true);
}

//only call this function if the sql statement actually executed
std::vector<Transaction> Transaction_Services::traverse_result_set(sqlite3_stmt* stmt){
    std::vector<Transaction> t_list;
    while(sqlite3_step(stmt) == SQLITE_ROW){
            int64_t t_id = sqlite3_column_int64(stmt, 0);
            double amount = sqlite3_column_double(stmt, 1);
            std::string category = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            bool transaction_type = static_cast<bool>(sqlite3_column_int64(stmt, 3));
            std::string t_date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            Transaction t = Transaction(t_id, t_date, category, amount, transaction_type);
            t_list.push_back(t);
        }
    return t_list;
}

//this can be made used to search for any combinations of the parameters listed. beats having to write the multiple variations. this can only be used for specific date searches or other date search types (mm, yyyy, dd, dd/mm, mm/yyyy but not dd/yyyy)
//the change i made to this function has made the getTransactionsByMonthOrYear obsolete before the gui even came on, won't use it if i only want to use the date
std::vector<Transaction> Transaction_Services::getTransactions(int64_t t_id, std::string date, std::string category, double amount){
    sqlite3_stmt* stmt;
    std::vector<Transaction> t_list;
    bool parameter_added = false;
    std::string sql = "SELECT * FROM tblTransactions";

    if (t_id != 0){
        if (parameter_added == false){
            sql = sql + " WHERE transaction_id = " + std::to_string(t_id);
            parameter_added = true;
            }
            else{
                sql = sql + " AND transaction_id = " + std::to_string(t_id);
            }
    }

    if(date != std::to_string(0)){
        if (parameter_added == false){
            sql = sql + " WHERE date LIKE \"%" + date + "%\"";
            parameter_added = true;
        }
        else{
            sql = sql + " AND date LIKE \"%" + date + "%\"";
        }
    }

    if(category != std::to_string(0)){
        if (parameter_added == false){
            sql = sql + " WHERE category = \"" + category + "\"";
            parameter_added = true;
        }
        else{
            sql = sql + " AND category = \"" + category + "\"";
        }
    }

    if(amount != 0){
        if(parameter_added == false){
            sql = sql + " WHERE amount = " + std::to_string(amount);
            parameter_added = true;
        }
        else{
            sql = sql + " AND amount = " + std::to_string(amount);
        }
    }

    int exit_code = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, nullptr);
    if(exit_code != SQLITE_OK){
        std::cerr << "Failed to prepare statement " << sqlite3_errmsg(this->db) << "\n";
    }else{
        t_list = this->traverse_result_set(stmt);
    }
    sqlite3_finalize(stmt);
    return t_list;
}

//the parameter can be a month or year it will work the same, can be mm/yyyy, mm, yyyy, will be used only if other parameters wont be needed
std::vector<Transaction> Transaction_Services::getTransactionsByMonthOrYear(std::string month_or_year){
    std::string sql = "SELECT * FROM tblTransactions WHERE Date LIKE \"%" + month_or_year + "%\"";
    std::vector<Transaction> t_list;


    sqlite3_stmt* stmt;

    int exit_code = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, nullptr);
    if(exit_code != SQLITE_OK){
        std::cerr << "Failed to prepare statement " << sqlite3_errmsg(this->db) << "\n";
    }else{
        t_list = this->traverse_result_set(stmt);
    }
    sqlite3_finalize(stmt);
    return t_list;
}

//this function is there just for the meme of it, i likely wont really need to get the whole database's worth of transactions
std::vector<Transaction> Transaction_Services::getAllTransactions(){
    return this->getTransactions(this->num_default_value, this->str_default_value, this->str_default_value, this->num_default_value);
}

//update methods
//this function works as far as i know, just call it multiple times if we have to do multiple items
void Transaction_Services::update_transaction(Transaction t){
    std::string sql = "UPDATE tblTransactions SET Amount = " + std::to_string(t.getAmount())
    + ", Category = \"" + t.getCategory() + "\", Transaction_Type = "+ std::to_string(t.getTransactionType()) +
    ", Date = \"" + t.getDate() + "\" WHERE transaction_id = " + t.getTransactionID();
    std::string error_msg = "Failed to update transaction: ";
    std::string success_msg = "Transaction updated successfully";
    this->execute_sql(sql, error_msg, success_msg);
}

void Transaction_Services::delete_transaction(Transaction t){
    std::string sql = "DELETE FROM tblTransactions WHERE transaction_id = " + t.getTransactionID();
    std::string error_msg = "Failed to remove transaction: ";
    std::string succes_msg = "Transaction removed successfully";
    this->execute_sql(sql, error_msg, succes_msg);
}
//insertion methods
void Transaction_Services::add_transaction(Transaction t){
    std::string sql = "INSERT INTO tblTransactions (transaction_id, Amount, Category, Transaction_Type, Date) VALUES (" + t.getTransactionID() +  ", " + std::to_string(t.getAmount()) +
                ", \"" + t.getCategory() + "\", " + std::to_string(t.getTransactionType()) + ", \"" + t.getDate() + "\")";
    std::string error_msg = "Failed to add transaction into database: ";
    std::string success_msg = "Transaction added successfully";
    this->execute_sql(sql, error_msg, success_msg);
}

//utility functions

//this function is only used where the is no return variable that will be needed
void Transaction_Services::execute_sql(std::string sql, std::string error_msg, std::string success_msg){
    sqlite3_stmt* stmt;
    int exit_code = sqlite3_exec(this->db, sql.c_str(), 0, &stmt, nullptr);

    if(exit_code != SQLITE_OK){
        std::cerr << error_msg << sqlite3_errmsg(this->db) << "\n";
    }
    else{
        std::cout << success_msg << "\n";
    }
    sqlite3_finalize(stmt);
}
//deconstructor
Transaction_Services::~Transaction_Services(){

    if(this->is_connected == true)
        sqlite3_close(this->db);
}

std::string generate_id(){
    srand(time(0));
    int id = rand() + time(0);
    std::string transaction_id = std::to_string(id);
    return transaction_id;
}
