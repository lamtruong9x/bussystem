//
// Created by Working on 6/11/2023.
//


#include "repository.h"
namespace repo {
    repo::repository::repository() {
        this->trips = repo::loadTripsFromFile(TRIP_FILENAME);
        this->tickets = repo::loadTickets(TICKET_FILENAME);
        this->passengers = repo::loadPassengerFromFile(PASSENGER_FILENAME);
    }

    repo::repository::~repository() {
        repo::savePassengersToFile(passengers, PASSENGER_FILENAME);
        repo::saveTicketsToFile(tickets, TICKET_FILENAME);
        repo::saveTripsToFile(trips, TRIP_FILENAME);
    }
}//namespace repo

