#include "phonebook.hpp"

void    phonebook::initialize()
{
    counter = 0;
    index = 0;
}

void phonebook::search_display() {

    size_t user_inp;
    size_t i;

    i = 0;
    if (counter == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    while (i < counter) {
        std::cout << std::right;
        std::cout << (i + 1) << "|";
        contacts[i].display_contact();
        std::cout << std::endl;
        i++;
    }
    while (true) {
        std::cout << "contact index : ";
        std::cin >> user_inp;
        if (std::cin.fail())
        {
            std::cout << "Invalid contat index please fix issue\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break ;
    }
    if (user_inp > counter || user_inp <= 0)
        std::cout << "No contact with this index." << std::endl;
    else
        contacts[user_inp - 1].display_profile();
}

void    phonebook::addcontact()
{
    contacts[index % 8].set_contact();
    if (index == 7)
        index = 0;
    else
        index++;
    if (counter < 8)
        counter++;
}

std::string     get_non_empty(const std::string& prompt)
{
    std::string usr_inp;

    do {
        std::cout << prompt << " : ";
        std::getline(std::cin, usr_inp);
        if (!usr_inp.empty())
            break ;
        else
            std::cout << "Input cannot be empty. Please try again\n";
    } while (usr_inp.empty());
    return (usr_inp);
}

void    contact::set_contact()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer
    firstname = get_non_empty("firstname");
    lastname = get_non_empty("lastname");
    nickname = get_non_empty("nickname");
    do {
        std::cout << "phone number : ";
        std::getline(std::cin, phonenumber);
        if (is_all_numeric(phonenumber))
            break ;
        else
            std::cout << "Please Enter a valid phone number\n";
    } while (true);
    darksecret = get_non_empty("dark secret");
}

bool    is_all_numeric(const std::string& str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}