#include "ui.hpp"

int main(){
    //console_ui cu = console_ui();
    
    for (int i = 0; i < 10; i++)
        std::cout << generate_id() << "\n";    
    return 0;
}
