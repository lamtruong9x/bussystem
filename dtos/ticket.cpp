//
// Created by Working on 6/11/2023.
//

#include "ticket.h"

dto::Ticket::Ticket(int seatNum, const std::string &tripId, const std::string &phoneNumber) : seatNum(seatNum),
                                                                                              tripId(tripId),
                                                                                              phoneNumber(
                                                                                                      phoneNumber) {}

int dto::Ticket::getSeatNum() const {
    return seatNum;
}

const std::string &dto::Ticket::getTripId() const {
    return tripId;
}

const std::string &dto::Ticket::getPhoneNumber() const {
    return phoneNumber;
}

void dto::Ticket::setSeatNum(int seatNum) {
    Ticket::seatNum = seatNum;
}

void dto::Ticket::setTripId(const std::string &tripId) {
    Ticket::tripId = tripId;
}

void dto::Ticket::setPhoneNumber(const std::string &phoneNumber) {
    Ticket::phoneNumber = phoneNumber;
}