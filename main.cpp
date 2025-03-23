#include "ui.hpp"

int main(){
    Transaction_Services ts = Transaction_Services();
    vector<Transaction> transactions = ts.getAllTransactions();
    for(int i =0; i < transactions.size(); i++){
        std::cout << transactions[i].toString() << '\n' << '\n';
    }
    ts.add_transaction(transactions[0]);
}
