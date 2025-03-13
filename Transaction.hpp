#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP
#include <stdint.h>
#include <iostream>
#include <string>
/// @brief
class Transaction{
    private:
        std::string transaction_id;
        std::string date;
        std::string category;
        double amount;
        bool is_expense;

    public:
        explicit Transaction(std::string t_id, std::string n_date, std::string n_category, double n_amount, bool n_is_expense);
        Transaction(int64_t t_id, std::string n_date, std::string n_category, double n_amount, bool n_is_expense);
        Transaction();
        std::string getDate();
        std::string getCategory();
        double getAmount();
        bool getTransactionType();
        std::string toString();
        std::string getTransactionID();

        void setDate(std::string n_date);
        void setCategory(std::string n_category);
        void setAmount(double n_amount);
        void setTransactionType(bool n_is_expense);
        ~Transaction();

};
#endif
