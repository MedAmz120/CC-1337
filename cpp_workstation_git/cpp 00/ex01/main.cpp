#include "phonebook.hpp"

void    contact::display_profile()
{
    std::cout << firstname << std::endl;
    std::cout << lastname << std::endl;
    std::cout << nickname << std::endl;
    std::cout << phonenumber << std::endl;
    std::cout << darksecret << std::endl;
}

void    contact::display_contact()
{
    std::cout << std::setw(10);
    std::cout << ((firstname.length() > 10) ? firstname.substr(0, 9) + "." : firstname); 
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << ((lastname.length() > 10) ? lastname.substr(0, 9) + "." : lastname); 
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << ((nickname.length() > 10) ? nickname.substr(0, 9) + "." :nickname); 
}

int main()
{
    contact     data;
    phonebook   profile;
    std::string command;

    profile.initialize();
    do {
        std::cin >> command;
        if (command.compare("ADD") == 0)
            profile.addcontact();
        if (command.compare("SEARCH") == 0)
            profile.search_display();
    } while (command.compare("EXIT") != 0);
    return 0;
}
