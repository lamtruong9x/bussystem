
enum class menuChoice_modify
{
    QUIT,
    HELP,
    BACK,
    MODIFY_PASS,
    MODIFY_TICK,


    UNKNOWN
};

void printMenu_modify();
menuChoice_modify hashTheChoice_modify(std::string choice);



void printMenu_modify() 
{
    std::cout << R"(
**********               Modification Menu               **********
syntax: -[Function]

[Function]:
    [t] or [ticket] to modify ticket (seat number)
    [q] or [quit] to quit the application
    [b] or [back] to go back the previous menu
    
)";
}

menuChoice_modify hashTheChoice_modify(std::string choice)
{
    if (choice == "-q" || choice == "-quit")
        return menuChoice_modify::QUIT;
    if (choice == "-h" || choice == "-help")
        return menuChoice_modify::HELP;
    if (choice == "-b" || choice == "-back" || choice == "-make")
        return menuChoice_modify::BACK;
    if (choice == "-p" || choice == "-passenger")
        return menuChoice_modify::MODIFY_PASS;
    if (choice == "-t" || choice == "-ticket")
        return menuChoice_modify::MODIFY_TICK;

    return menuChoice_modify::UNKNOWN;
}