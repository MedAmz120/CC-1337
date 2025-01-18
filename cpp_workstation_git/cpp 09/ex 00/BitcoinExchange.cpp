#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::~BitcoinExchange () {}

void BitcoinExchange::read_data_csv () {
    std::ifstream   file(data_file.c_str()); // c_str to convert from str to char*
    std::string     line;

    std::getline(file, line); // skip the first line
    while (std::getline(file, line)) {
        std::istringstream splitted_line(line); // split line into columns
        std::string       date_str;
        std::string       price_str;
        double  price;

        std::getline(splitted_line, date_str, ',');
        std::getline(splitted_line, price_str);
        std::istringstream (price_str) >> price; // convert price from str to double

        data[date_str] = price; // store the data into our map
    }
    file.close();
}

bool    BitcoinExchange::check_file(const std::ifstream& file) const {
    if (!file.is_open()) {
        std::cerr << "Could not open input file" << std::endl;
        return false;
    }
    return true;
}

bool    BitcoinExchange::check_line(const std::string& line) const {
    if (line.empty())
            return false;
    if (line.find('|') == std::string::npos) // npos contant indicate not found
    {
        std::cerr << "Error: Bad input => " << line << std::endl;
        return false;
    }
    return true;
}

bool    BitcoinExchange::is_leap_year(int year) const {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool    BitcoinExchange::check_date(const std::string& date) const {
    try {
        if (date.size() != 11)
            throw std::logic_error("bad input => " + date);
        for (int i = 0; i < 10; i++) 
        {
            if (i == 4 || i == 7)  // check if - presence is in the date
            {
                if (date[i] != '-')
                    throw std::logic_error("bad input => " + date);
            }
            else
            {
                if (!std::isdigit(date[i]))
                    throw std::logic_error("bad input => " + date);
            }
        }
        int d, m, y;
        std::istringstream  issyear(date.substr(0, 4)); // from position 0 we take 4 numbers 2022 (0 1 2 3)
        std::istringstream  issmonth(date.substr(5, 2));
        std::istringstream  issday(date.substr(8, 2));

        issyear >> y;
        issmonth >> m; // conversion from str to int
        issday >> d;

        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of day in month jan 31 Feb 28 ...
        if (is_leap_year(y)) // if it s a leap year (sana kabissa) we change Feb from 28 to 29
            days_in_month[2] = 29;
        if (d > days_in_month[m]) // if the number bigger than the number of days in the month
            throw std::logic_error("bad input => " + date);
    }
    catch (std::logic_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool    BitcoinExchange::check_value(const std::string& value_str, double *value) const {
    std::istringstream viss(value_str);

    try {
        if (!(viss >> *value)) // if it s not a number
            throw std::logic_error("Invalid value");
        if (*value < 0) // negative value
            throw std::logic_error("not a positive number.");
        if (*value > 1000)
            throw std::logic_error("too large a number.");
    }
    catch (std::logic_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

double	BitcoinExchange::get_result(std::string date)
{
	//upper_bound: p points to the first element with key >k or c.end(); ordered containers only
	std::map<std::string, double>::const_iterator it = data.upper_bound(date);
	if (it == data.begin()) {
		std::cout << "Error: no available rate for the given date or earlier." << std::endl;
		return -1.0;
	}
	--it;
	return it->second;
}

void    BitcoinExchange::Exchange(const std::string& value_str, double value, const std::string& date) {
    double  btc_value = get_result(date);

    if (btc_value < 0)
        return ;
    btc_value *= value;
    std::cout << date << " => " + value_str <<  " = " << btc_value << std::endl;
}

void BitcoinExchange::read_input_file(const std::string& input_file) {
    
    std::ifstream   file(input_file.c_str());
    if (!check_file(file))
        return ;

    std::string     line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        if (!check_line(line))
            continue ;
        
        std::istringstream  splitted_line(line);
        std::string         date_str;
        std::string         value_str;
        double              value;

        std::getline(splitted_line, date_str, '|');
        std::getline(splitted_line, value_str);
        std::istringstream (value_str) >> value;
    
        if (!check_date(date_str))
            continue ;
        if (!check_value(value_str, &value))
            continue ;
        Exchange(value_str, value, date_str);
    }
    file.close();
}