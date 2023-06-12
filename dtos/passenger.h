//
// Created by Working on 6/11/2023.
//

#ifndef BUSSYSTEM_PASSENGER_H
#define BUSSYSTEM_PASSENGER_H

#include <string>
#include "date.h"
#include "time.h"

namespace dto {
    class Passenger {
        std::string phoneNumber;
        std::string fullName;
    public:
        Passenger(const std::string &phoneNumber, const std::string &fullName);

        Passenger();

        const std::string &getPhoneNumber() const;

        void setPhoneNumber(const std::string &phoneNumber);

        void setFullName(const std::string &fullName);

        const std::string &getFullName() const;
    };
}

#endif //BUSSYSTEM_PASSENGER_H
