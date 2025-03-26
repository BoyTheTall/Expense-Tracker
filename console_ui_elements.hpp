#include <string>
#include <vector>
#include <string>
class console_table{
    private:
        int number_of_rows;
        int number_of_columns;
        std::string title;
        std::vector<std::string> columns;
        std::vector<std::vector<std::string>> table_data;
        std::string build_table();
    public:
        console_table(int number_columns, std::vector<std::string> columns, std::string title, std::vector<std::vector<std::string>> table_data);
        console_table(std::vector<std::string> columns, std::string title, std::vector<std::vector<std::string>> data);
        std::string getTable();
    
};