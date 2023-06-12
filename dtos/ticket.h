//
// Created by Working on 6/11/2023.
//

#ifndef BUSSYSTEM_TICKET_H
#define BUSSYSTEM_TICKET_H
#include <string>
#include <ostream>

namespace dto {
    class Ticket {
    public:
        Ticket(int seatNum, const std::string &tripId, const std::string &phoneNumber);

        int getSeatNum() const;

        const std::string &getTripId() const;

        const std::string &getPhoneNumber() const;

        void setSeatNum(int seatNum);

        void setTripId(const std::string &tripId);

        void setPhoneNumber(const std::string &phoneNumber);

    private:
        int seatNum;
        std::string tripId;
        std::string phoneNumber;
    };
}

#endif //BUSSYSTEM_TICKET_H
