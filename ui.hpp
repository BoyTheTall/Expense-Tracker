#include "transaction_services.hpp"
#include <iostream>
class console_ui{
    private:
        std::string zhong = "⣿⣿⣿⣿⣿⣿⡿⠛⠋⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⡿⠋⠁⠄⠄⢠⣴⣶⣿⣿⣶⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠿⣿⣿⣿⣿\n"
                            "⣿⣿⡟⠁⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣇⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢹⣿⣿⣿\n"
                            "⣿⣿⣧⠄⠄⠄⠄⢰⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿\n"
                            "⣿⣿⣿⣧⡀⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣷⣆⠄⠄⠄⠄⠄⠄⠄⠄⣰⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⡿⣦⣀⣾⣿⣟⣉⠉⠙⢛⡏⠁⠄⠄⠄⠄⠄⠄⠄⠄⠚⢿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣯⣗⣻⣿⣯⣥⣦⠄⣀⣾⡇⠄⠄⠂⠄⠄⠄⠄⠄⠄⠄⣼⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⠄⠂⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣻⠋⠄⠄⠄⠄⠄⠄⠄⢀⠄⣸⣿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁⡀⠄⠄⠄⠄⠄⠄⢸⣾⣿⣿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣥⣾⣷⠶⠆⠄⠄⠄⢀⠄⠄⠄⠸⣿⣿⣿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣶⣄⡀⠄⠄⠄⠄⠄⢀⠄⠸⣿⣿⣿⣿⣿⣿\n"
                            "⣿⣿⣿⣿⣿⣿⠟⠚⣿⣿⡻⠿⠿⠛⠙⠁⠄⠄⠄⠄⠠⠂⠄⠄⠘⠿⣿⣿⣿⣿\n"
                            "⠿⠛⠉⠁⠁⠄⠄⠄⣻⣿⣿⣧⣠⣀⠄⠄⠄⠄⡀⠂⠄⠄⠄⠄⠄⠄⠈⠉⠿⢿\n"
                            "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⠿⣿⡿⠃⢀⡠⠄⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n";
        Transaction_Services ts;
        const int RETURN_TO_MAIN_MENU = 10;
        const int ADD_TRANSACTION_MENU = 11;
        void clear_scr();

    public:
        console_ui();
        void add_transaction_ui();
        void main_menu();
        void view_transactions();


};
