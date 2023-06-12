#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include "date.h"
//datetime
namespace dt {
    Date::Date()
            : day(1), month(1), year(2022) {
    }
    // day, month, year
    Date::Date(int day, int month, int year)
            : day(day), month(month), year(year) {
    }

    Date::Date(const std::string& dateString) {
        // Assuming the date string is always in the format "dd/mm/yyyy"
        size_t pos1 = dateString.find('/');
        size_t pos2 = dateString.find('/', pos1 + 1);

        day = std::stoi(dateString.substr(0, pos1));
        month = std::stoi(dateString.substr(pos1 + 1, pos2 - pos1 - 1));
        year = std::stoi(dateString.substr(pos2 + 1));
    }

    bool Date::operator==(Date &A) const {
        return (day == A.day) && (month == A.month) && (year == A.year);
    }

    bool Date::isDay(int day) {
        if (day < 1) return false;

        int month_have_31_days[] = {1, 3, 5, 7, 8, 10, 12};

        if (month == 2 && day > 29) {
            return false;
        }
        if (std::count(std::begin(month_have_31_days), std::end(month_have_31_days), month) > 0) {
            if (day > 31) return false;
        } else {
            if (day > 30) return false;
        }
        return true;
    }

    bool Date::isMonth(int month) {
        if (month < 1) return false;
        if (month > 12) return false;
        return true;
    }

    bool Date::isYear(int year) {
        if (year < 0) return false;
        return true;
    }

    void Date::print() {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }

    std::istream &operator>>(std::istream &is, Date &entry) {
        is >> entry.day;
        is >> entry.month;
        is >> entry.year;

        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Date &entry) {
        os << entry.day;
        os << "/";
        os << entry.month;
        os << "/";
        os << entry.year;


        return os;
    }

}