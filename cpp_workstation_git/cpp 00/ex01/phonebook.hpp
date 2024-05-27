# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class phonebook {
    private:
    contact contacts[8];
    size_t index;
    size_t counter;

    public:
    void    initialize();
    void    addcontact();
    void    search_display();
};

bool            is_all_numeric(const std::string& str);
std::string     get_non_empty(const std::string& prompt);

#endif