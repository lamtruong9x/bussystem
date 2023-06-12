//
// Created by Working on 6/11/2023.
//

#include "passenger.h"

dto::Passenger::Passenger(const std::string &phoneNumber, const std::string &fullName) : phoneNumber(phoneNumber),
                                                                                         fullName(fullName) {}

dto::Passenger::Passenger() {}

const std::string &dto::Passenger::getPhoneNumber() const {
    return phoneNumber;
}

const std::string &dto::Passenger::getFullName() const {
    return fullName;
}

void dto::Passenger::setPhoneNumber(const std::string &phoneNumber) {
    Passenger::phoneNumber = phoneNumber;
}

void dto::Passenger::setFullName(const std::string &fullName) {
    Passenger::fullName = fullName;
}
