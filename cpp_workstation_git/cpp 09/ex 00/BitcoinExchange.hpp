#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>

const std::string data_file = "data.csv";

class BitcoinExchange {
    private:
    std::map<std::string, double> data;

    public:
    BitcoinExchange ();
    BitcoinExchange(const BitcoinExchange& copie);
    BitcoinExchange& operator=(const BitcoinExchange& copie);
    ~BitcoinExchange();

    void    read_data_csv();
    void    read_input_file(const std::string& input_file);
    bool    check_file(const std::ifstream& file) const;
    bool    check_line(const std::string& line) const;
    bool    check_date(const std::string& date) const;
    bool    is_leap_year(int year) const;
    bool    check_value(const std::string& value_str, double *value) const;
    void    Exchange(const std::string& value_str, double value, const std::string& date);
    double  get_result(std::string date);
};

/*    
    void printData() const {
    // Use an iterator to traverse the map
    std::map<std::string, double>::const_iterator it = data.begin();
    while (it != data.end()) {
        // Print the key (date) and value (price)
        std::cout << it->first << " : " << it->second << std::endl;
        ++it; // Move to the next element
        }
    }   
*/

#endif
