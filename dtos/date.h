#ifndef DATE_HPP
#define DATE_HPP
namespace dt {
    struct Date {
        Date();

        Date(int, int, int);

        Date(const std::string &dateString);

        bool operator==(Date &A) const;

        bool isDay(int);

        bool isMonth(int);

        bool isYear(int);

        int day;
        int month;
        int year;
        const std::string to_string() const {
            return std::to_string(day) + std::to_string(month) + std::to_string(year);
        }

        void print();
    };

    std::istream &operator>>(std::istream &is, Date &entry);

    std::ostream &operator<<(std::ostream &os, const Date &entry);
}
#endif