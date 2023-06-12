//
// Created by Lam Truong on 6/12/23.
//

#include "ticket_repo.h"
#include <algorithm>

repo::ticket_repo::ticket_repo(repo::repository &repo, repo::passenger_repo &passengerRepo, repo::trip_repo &tripRepo)
        : repo(repo), passengerRepo(passengerRepo), tripRepo(tripRepo) {}

bool repo::ticket_repo::create(dto::Ticket &ticket) {
    if (isExist(ticket.getTripId(), ticket.getSeatNum())) {
        return false;
    }
    repo.tickets.push_back(ticket);
    return true;
}

bool repo::ticket_repo::isExist(const std::string &tripId, int seatNum) {
    for(const auto &ticket : repo.tickets) {
        if (ticket.getSeatNum() == seatNum && ticket.getTripId() == tripId) {
            return true;
        }
    }
    return false;
}

void repo::ticket_repo::deleteTicketsByReservation(const std::string &phoneNumber, const std::string &tripId) {
    repo.tickets.erase(
            std::remove_if(repo.tickets.begin(), repo.tickets.end(), [&](const dto::Ticket& ticket) {
                return (ticket.getPhoneNumber() == phoneNumber) && (ticket.getTripId() == tripId);
            }),
            repo.tickets.end()
    );
}

std::vector<dto::Ticket> repo::ticket_repo::getTicketByTripId(const std::string &tripId) {
    std::vector<dto::Ticket> tickets;
    for(auto &ticket : repo.tickets) {
        if (ticket.getTripId() == tripId) {
            tickets.push_back(ticket);
        }
    }
    return tickets;
}

std::vector<dto::Ticket> repo::ticket_repo::getTicketByPassengerAndTripId(const std::string &phoneNumber, const std::string &tripId) {
    std::vector<dto::Ticket> tickets;
    for(auto &ticket : repo.tickets) {
        if (ticket.getTripId() == tripId && ticket.getPhoneNumber() == phoneNumber) {
            tickets.push_back(ticket);
        }
    }
    return tickets;
}

bool repo::ticket_repo::changeTicket(const std::string &phoneNumber, const std::string &tripId, const int oldSeat,
                                     const int newSeat) {
    if(!isExist(tripId, newSeat) && isExist(tripId, oldSeat)) {
        deleteTicket(phoneNumber, tripId, oldSeat);
        auto newTicket = dto::Ticket(newSeat, tripId, phoneNumber);
        create(newTicket);
        return true;
    }
    return false;
}

void repo::ticket_repo::deleteTicket(const std::string &phoneNumber, const std::string &tripId, const int seatNum) {
    for (auto it = repo.tickets.begin(); it != repo.tickets.end(); ++it) {
        if ((*it).getPhoneNumber() == phoneNumber && (*it).getTripId() == tripId && seatNum == (*it).getSeatNum()) {
            repo.tickets.erase(it);
            break;  // Exit the loop after erasing the element
        }
    }
}
