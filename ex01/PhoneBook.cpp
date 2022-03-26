#include <iostream>
#include <iomanip>
#include <sstream>

#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
    : contactCount(0),
      lastContact(0)
{
}

void PhoneBook::fillNextContact()
{
    contacts[lastContact].fill();
    lastContact = (lastContact + 1) % 8;
    if (contactCount < MAX_CONTACT_COUNT)
        contactCount++;
}

Contact PhoneBook::getContact(size_t i)
{
    return contacts[i % MAX_CONTACT_COUNT];
}

static std::string _shorten(std::string string)
{
	if (string.size() > 10)
	{
		string.resize(10);
		string[9] = '.';
	}
	return (string);
}

void PhoneBook::displayContacts()
{
    std::cout << std::string(36, '-') << std::endl;

    std::cout << "|"
        << std::setw(1) << std::right << "#" << "|"
        << std::setw(10) << std::right << "First name" << "|"
        << std::setw(10) << std::right << "Last name" << "|"
        << std::setw(10) << std::right << "Nickname" << "|"
        << std::endl;
        
    std::cout << std::string(36, '-') << std::endl;
    
    for (size_t i = 0; i < contactCount; i++)
    {
        Contact contact = getContact(i);

        std::cout << "|"
            << std::setw(1) << std::right << i + 1 << "|"
            << std::setw(10) << std::right << _shorten(contact.getFirstName()) << "|"
            << std::setw(10) << std::right << _shorten(contact.getLastName()) << "|"
            << std::setw(10) << std::right << _shorten(contact.getNickname()) << "|"
            << std::endl;
    }

    std::cout << std::string(36, '-') << std::endl;
}

void PhoneBook::queryContact()
{
    std::cout << ">> #: ";

    std::string input;
    std::getline(std::cin, input);

    std::stringstream inputStream(input);

    size_t contactIndex;

    if (!(inputStream >> contactIndex))
    {
        std::cout << "error: invalid contact index" << std::endl;
        
        return;
    }

    if (contactIndex <= 0 || contactIndex > lastContact)
    {
        std::cout << "error: contact index out of range" << std::endl;

        return;
    }

    getContact(contactIndex - 1).print();
}
