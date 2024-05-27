# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip>

class contact {
    private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darksecret;
 
    public:
    void    display_contact();
    void    display_profile();
    void    set_contact();
};

#endif