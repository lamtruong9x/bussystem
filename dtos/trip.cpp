//
// Created by Working on 6/11/2023.
//

#include "trip.h"

dto::Trip::Trip(const int busId, const std::string &departure, const std::string &destination,
                const dt::Date &travelDate, const dt::Time &travelTime) : bus(Bus(busId)), destination(destination),
                                                                          departure(departure), travelDate(travelDate),
                                                                          travelTime(travelTime){
    id = std::to_string(busId) + std::string(departure+destination+travelDate.to_string()+travelTime.to_string());
}

const std::string &dto::Trip::getId() const {
    return id;
}

const std::string &dto::Trip::getDestination() const {
    return destination;
}

const std::string &dto::Trip::getDeparture() const {
    return departure;
}

const dt::Date &dto::Trip::getTravelDate() const {
    return travelDate;
}

const dt::Time &dto::Trip::getTravelTime() const {
    return travelTime;
}

std::ostream &dto::operator<<(std::ostream &os, const dto::Trip &trip) {
    os << "bus: " << trip.bus << " destination: " << trip.destination << " departure: " << trip.departure
       << " travelDate: " << trip.travelDate << " travelTime: " << trip.travelTime;
    return os;
}


dto::Trip::Trip() {}

void dto::Trip::setId(const std::string &id) {
    Trip::id = id;
}

void dto::Trip::setDestination(const std::string &destination) {
    Trip::destination = destination;
}

void dto::Trip::setDeparture(const std::string &departure) {
    Trip::departure = departure;
}

void dto::Trip::setTravelDate(const dt::Date &travelDate) {
    Trip::travelDate = travelDate;
}

void dto::Trip::setTravelTime(const dt::Time &travelTime) {
    Trip::travelTime = travelTime;
}

dto::Bus &dto::Trip::getBus() {
    return Trip::bus;
}
