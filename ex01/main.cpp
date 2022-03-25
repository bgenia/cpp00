#include <string>
#include <iostream>

#include <PhoneBook.hpp>

int main()
{
    PhoneBook phoneBook;
    std::string line;

    do
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "ADD")
        {
            phoneBook.fillNextContact();
        }

        if (line == "SEARCH")
        {
            phoneBook.displayContacts();
            phoneBook.queryContact();
        }
    }
    while (!std::cin.eof() && line != "EXIT");

    std::cout << std::endl;
}
