#include <string>
#include <iostream>

#include <Contact.hpp>

void Contact::fill()
{
    std::cout << "First name    : ";
    std::getline(std::cin, firstName);
    std::cout << "Last name     : ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname      : ";
    std::getline(std::cin, nickname);
    std::cout << "Phone number  : ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestSecret);
}

void Contact::print()
{
    std::cout
            << "First name    : " << getFirstName() << "\n"
            << "Last name     : " << getLastName() << "\n"
            << "Nickname      : " << getNickname() << "\n"
            << "Phone number  : " << getPhoneNumber() << "\n"
            << "Darkest secret: " << getDarkestSecret() << std::endl;
}

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickname()
{
    return nickname;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}
