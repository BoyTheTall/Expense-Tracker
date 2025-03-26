#include "console_ui_elements.hpp"

console_table::console_table( int number_columns, std::vector<std::string> columns, std::string title, std::vector<std::vector<std::string>> table_data){

}
console_table::console_table(std::vector<std::string> columns, std::string title, std::vector<std::vector<std::string>> data){
    this->columns = columns;
    this->title =title;
    this->table_data = data;
    this->number_of_rows = this->table_data.size();
    this->number_of_columns = this->columns.size();
}
std::string console_table::build_table(){
    std::string table_str;
    
    return table_str;
}