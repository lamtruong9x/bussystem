#include <iostream>
#include <string>
#include <regex>

#include "time.h"

namespace dt {
    Time::Time()
            : hour(0), minute(0)
    {
    }
    // hour, minute
    Time::Time(int hour, int minute)
            : hour(hour), minute(minute)
    {
    }

    Time::Time(const std::string& dateString) {
        // Assuming the date string is always in the format "dd/mm/yyyy"
        size_t pos1 = dateString.find('h');

        hour = std::stoi(dateString.substr(0, pos1));
        minute = std::stoi(dateString.substr(pos1 + 1));
    }

    bool Time::isHour(int hour)
    {
        if (hour < 0 || hour > 23) return false;
        return true;
    }

    bool Time::isMinute(int minute)
    {
        if (minute >= 0 && minute <= 59) return true;
        return false;
    }

    std::istream& operator>>(std::istream& is, Time& entry)
    {
        is >> entry.hour;
        is >> entry.minute;

        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Time& entry)
    {
        os << entry.hour;
        os << "h";
        os << entry.minute;

        return os;
    }
}

