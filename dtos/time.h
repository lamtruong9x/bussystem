#ifndef TIME_HPP
#define TIME_HPP


namespace dt {

    struct Time {
        Time();

        Time(int, int);

        Time(const std::string &dateString);

        bool isHour(int);

        bool isMinute(int);

        void print();

        int hour;
        int minute;
        const std::string to_string() const {
            return std::to_string(hour) + std::to_string(minute);
        }
    };

    std::istream &operator>>(std::istream &is, Time &entry);

    std::ostream &operator<<(std::ostream &os, const Time &entry);
}
#endif