#include "ui.hpp"

console_ui::console_ui(){
    this->ts = Transaction_Services();
    this->main_menu();
    
}

//private function that will clear the console. due to different platforoms it will have code to cler consoles of windomws, linux or mac. for now itll be windows only
void console_ui::clear_scr(){
    system("cls");

}
void console_ui::add_transaction_ui(){
    int exit = 0;

    while(exit == 0){
        this->clear_scr();   
        std::cout << "Add Transaction Menu:\n";
        std::cout << "Note: transaction id will be automatically added and shown at the end\n";
        std::cout << "1.Add single Transaction.\n";
        std::cout << "2.Add multiple Transactions\n";
        std::cout << this->RETURN_TO_MAIN_MENU <<".Return to Main Menu\n";
        std::cout << "Enter the desired menu option: ";
        int option;
        int cont_main_menu = this->RETURN_TO_MAIN_MENU;
        std::cin >> option;
        if(option == 1){
            this->clear_scr();
            //Variables
            std::string date;
            std::string category;
            double amount;
            bool isExpense;

            //getting inputs
            std::cout<<"Enter the transaction date(dd/mm/yyyy): ";
            std::cin >> date;
            std::cout << "Enter the category of the transaction(for example groceries): ";
            std::cin >> category;
            std::cout << "Enter the transaction type(E/e for an expense and I/i for an income transaction/money coming in): ";
            char t_type;
            std::cin >> t_type;
            if ('e' == t_type || 'E' == t_type){
                isExpense = true;
            }
            else {
                if('i' == t_type || 'I' == t_type){
                    isExpense = false;
                }
                else{
                    bool valid_option_entered = false;
                    while (valid_option_entered == false){
                    std::cout <<"Error invalid transaction type entered\n";
                    std::cout << "Enter the transaction type(E/e for an expense and I/i for an income transaction/money coming in): ";
                    if('i' == t_type || 'I' == t_type){
                       isExpense = false;
                       valid_option_entered = true;
                    }
                    if ('e' == t_type || 'E' == t_type){
                       isExpense = true;
                       valid_option_entered = true;
                    }
                }
                    
            }
        }
        std::cout <<"Enter the amount: ";
        std::cin >> amount;
        Transaction t(generate_id(), date, category, amount, isExpense);
        ts.add_transaction(t);

        }
        if(option == 2){
            this->clear_scr();
            std::cout << "How many transactions do you wish to add: ";
            int number_of_transactions;
            std::cin >> number_of_transactions;
            for(int i = 1; i >= number_of_transactions; i++){
                this->clear_scr();
                std::cout << "Transaction number: " << i << '\n';
                //Variables
                std::string date;
                std::string category;
                double amount;
                bool isExpense;

                //getting inputs
                std::cout<<"Enter the transaction date(dd/mm/yyyy): ";
                std::cin >> date;
                std::cout << "Enter the category of the transaction(for example groceries): ";
                std::cin >> category;
                std::cout << "Enter the transaction type(E/e for an expense and I/i for an income transaction/money coming in): ";
                char t_type;
                std::cin >> t_type;
                if ('e' == t_type || 'E' == t_type){
                    isExpense = true;
                }
                else {
                    if('i' == t_type || 'I' == t_type){
                        isExpense = false;
                    }
                    else{
                        bool valid_option_entered = false;
                        while (valid_option_entered == false){
                        std::cout <<"Error invalid transaction type entered\n";
                        std::cout << "Enter the transaction type(E/e for an expense and I/i for an income transaction/money coming in): ";
                        if('i' == t_type || 'I' == t_type){
                            isExpense = false;
                            valid_option_entered = true;
                        }
                        if ('e' == t_type || 'E' == t_type){
                            isExpense = true;
                            valid_option_entered = true;
                        }
                    }
                    
                }
            }
            std::cout <<"Enter the amount: ";
            std::cin >> amount;
            Transaction t(generate_id(), date, category, amount, isExpense);
            ts.add_transaction(t);
            }

        }
        if(option == this->RETURN_TO_MAIN_MENU){
            exit = 1;
        }
        

    }
    //breaking the loop returns to the main menu
    this->clear_scr();
}
void console_ui::view_transactions(){}

void console_ui::main_menu(){
    int exit = 0;
    while(exit==0){

        std::cout << "Main Menu:\n";
        std::cout <<"1.Add Transaction\n";
        std::cout << "3. Show all transactions";
        std::cout <<"99.exit application\n";
        std::cout << "100. Zhong Xina\n";
        std::cout << "Enter the desired option: ";

        int option;
        std::cin >> option;
        switch(option){
            case 1:
                add_transaction_ui();
                break;
            
            case 99:
                exit = 1;
                break;
            case 100:
                std::cout << this->zhong;
                break;
            case 3:
                vector<Transaction> transactions = this->ts.getAllExpenses();
                for(int i = 0; i < transactions.size(); i++)
                    std::cout << transactions[i].toString();
               
            }
    }
}