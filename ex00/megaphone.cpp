#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUND AND UNBEARABLE NOISES *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);

        for (size_t i = 0; i < arg.length(); i++)
        {
            std::cout << (char)std::toupper(arg[i]);
        }
    }

    std::cout << std::endl;
}