//
// Created by Lam Truong on 6/12/23.
//

#ifndef BUSSYSTEM_TICKET_REPO_H
#define BUSSYSTEM_TICKET_REPO_H
#include "trip_repo.h"
#include "passenger_repo.h"
namespace repo {
    class ticket_repo {
        repo::repository& repo;
        repo::passenger_repo &passengerRepo;
        repo::trip_repo &tripRepo;
    public:
        ticket_repo(repository &repo, passenger_repo &passengerRepo, trip_repo &tripRepo);

        void deleteTicket(const std::string& phoneNumber, const std::string& tripId, const int seatNum);
        bool create(dto::Ticket &ticket);
        void deleteTicketsByReservation(const std::string& phoneNumber, const std::string& tripId);
        bool isExist(const std::string& tripId, int seatNum);
        std::vector<dto::Ticket> getTicketByTripId(const std::string& tripId);
        std::vector<dto::Ticket> getTicketByPassengerAndTripId(const std::string& phoneNumber, const std::string& tripId);
        bool changeTicket(const std::string& phoneNumber, const std::string& tripId, const int oldSeat, const int newSeat);
    };
}

#endif //BUSSYSTEM_TICKET_REPO_H
