#pragma once

#include <Contact.hpp>

class PhoneBook
{
public:
    static const size_t MAX_CONTACT_COUNT = 8;

    PhoneBook();

    void fillNextContact();
    
    Contact getContact(size_t i);

    void displayContacts();

    void queryContact();

private:
    Contact contacts[MAX_CONTACT_COUNT];
    size_t contactCount;
    size_t lastContact;
};