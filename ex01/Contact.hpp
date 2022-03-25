#pragma once

#include <string>

class Contact
{
public:
    void fill();
    void print();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};