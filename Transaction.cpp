#include "Transaction.hpp"
#include <iostream>
#include <string>
using namespace std;

//this is the preferred constructor because well I am lazy and qt5 uses strings for the ui element data iirc
Transaction::Transaction(string t_id, std::string n_date, std::string n_category, double n_amount, bool n_is_expense)
{
    this ->transaction_id = t_id;
    this ->date = n_date;
    this ->category = n_category;
    this ->amount = n_amount;
    this ->is_expense = n_is_expense;

}

Transaction::Transaction(){
    this ->transaction_id = 122;
    this ->date = "22/04/0325";
    this ->category = "bank";
    this ->amount = 420.66;
    this ->is_expense = true;
}

double Transaction::getAmount(){
    return this -> amount;
}

std::string Transaction::getCategory()
{
    return this ->category;
}
std::string Transaction::getDate(){
    return this ->date;
}

std::string Transaction::getTransactionID(){
    return this->transaction_id;
}
bool Transaction::getTransactionType(){
    return this -> is_expense;
}
string Transaction::toString(){
    string str_rep("Transaction ID: ");
    str_rep.append(this->transaction_id + "\n");

    str_rep.append("Category: " + this->category +"\n");
    str_rep.append("Date: " + this->date + "\n");
    str_rep.append("Amount: " + to_string(this->amount) + "\n");
    if (this->is_expense == true){
        str_rep.append("Type of transaction: Expense");
    }
    else{
        str_rep.append("Type of transaction: Income");
    }
    return str_rep;
}
 void Transaction::setAmount(double n_amount){
    this -> amount = n_amount;
 }

 void Transaction::setCategory(std::string n_category){
    this -> category = n_category;
 }

 void Transaction::setDate(std::string n_date){
    this -> date = n_date;
 }

 void Transaction::setTransactionType(bool n_is_expense){
    this -> is_expense = n_is_expense;
 }

 Transaction::~Transaction(){

 }
