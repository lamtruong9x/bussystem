
enum class menuChoice
{
    QUIT,
    HELP,
    MAKE,
    MODIFY,
    BLANK,
    CANCEL,
    SEARCHBYNAME,
    SEARCHBYDATE,
    SAVE,
    PRINT,

    UNKNOWN
};

void printMenu();
menuChoice hashTheChoice(std::string choice);

void printMenu() 
{
    std::cout << R"(
**********                                              **********

[Function]:
    [q] or [quit]   Quit the application
    [i] or [make]   Make a reservation
    [m] or [modify] Modify a reservation
    [c] or [cancel] Cancel a reservation
    [s] or [save]   Save data
    [sn] or [searchbyname] Search reservations by name
     [sd] or [searchbydate] Search reservations by date of travel

)";
}

menuChoice hashTheChoice(std::string choice)
{
    if (choice == "q" || choice == "quit")
        return menuChoice::QUIT;
    if (choice == "h" || choice == "help")
        return menuChoice::HELP;
    if (choice == "i" || choice == "make")
        return menuChoice::MAKE;
    if (choice == "m" || choice == "modify")
        return menuChoice::MODIFY;
    if (choice == "c" || choice == "cancel")
        return menuChoice::CANCEL;
    if (choice == "s" || choice == "save")
        return menuChoice::SAVE;
    if (choice == "p" || choice == "print")
        return menuChoice::PRINT;
    if (choice == "b" || choice == "blank")
        return menuChoice::BLANK;
    if (choice == "sn" || choice == "searchbyname")
        return menuChoice::SEARCHBYNAME;
    if (choice == "sd" || choice == "searchbydate")
        return menuChoice::SEARCHBYDATE;

    return menuChoice::UNKNOWN;
}