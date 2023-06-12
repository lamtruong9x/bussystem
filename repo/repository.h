//
// Created by Working on 6/11/2023.
//

#ifndef BUSSYSTEM_REPOSITORY_H
#define BUSSYSTEM_REPOSITORY_H
#include "vector"
#include "../dtos/passenger.h"
#include "../dtos/trip.h"
#include "../dtos/ticket.h"
#include <iostream>
#include <fstream>

namespace repo {
    static const char* TRIP_FILENAME = "trips.txt";
    static const char* TICKET_FILENAME = "tickets.txt";
    static const char* PASSENGER_FILENAME = "passengers.txt";
    class repository {
    public:
        repository();

        virtual ~repository();

        std::vector<dto::Passenger> passengers;
        std::vector<dto::Trip> trips;
        std::vector<dto::Ticket> tickets;
    };


    // Function to save trips vector data into a text file
    void saveTripsToFile(std::vector<dto::Trip>& trips, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (auto& trip : trips) {
                file << trip.getBus().getId() << '\n';
                file << trip.getId() << '\n';
                file << trip.getDeparture() << '\n';
                file << trip.getDestination() << '\n';
                file << trip.getTravelDate() << '\n';
                file << trip.getTravelTime() << '\n';
            }
            file.close();
            std::cout << "Data saved to " << filename << " successfully." << std::endl;
        } else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }
    }

    std::vector<dto::Trip> loadTripsFromFile(const std::string& filename) {
        std::vector<dto::Trip> trips;
        std::ifstream file(filename);
        if (file.is_open()) {
            dto::Trip trip;
            std::string line;
            std::string id, des, dep;
            while (getline(file, line)) {
                trip.getBus().setId(std::stoi(line));

                getline(file, id);
                trip.setId(id);
                getline(file, dep);
                trip.setDeparture(dep);
                getline(file, des);
                trip.setDestination(des);
                // Assuming the date and time data are stored in a format that can be easily parsed
                getline(file, line); // Read the date as a string
                trip.setTravelDate(dt::Date(line));
                getline(file, line); // Read the time as a string
                trip.setTravelTime(dt::Time(line));
                trips.push_back(trip);
            }
            file.close();
            std::cout << "Data loaded from " << filename << " successfully." << std::endl;
        } else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }
        return trips;
    }

    void savePassengersToFile(std::vector<dto::Passenger>& trips, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (auto& passenger : trips) {
                file << passenger.getPhoneNumber() << '\n';
                file << passenger.getFullName() << '\n';
            }
            file.close();
            std::cout << "Data saved to " << filename << " successfully." << std::endl;
        } else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }
    }

    std::vector<dto::Passenger> loadPassengerFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<dto::Passenger> passengers;
        if (file.is_open()) {
            dto::Passenger p;
            std::string line;
            while (getline(file, line)) {
                p.setPhoneNumber(line);
                getline(file, line);
                p.setFullName(line);
            }
            file.close();
            std::cout << "Data loaded from " << filename << " successfully." << std::endl;
        } else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }
        return passengers;
    }

    void saveTicketsToFile(const std::vector<dto::Ticket>& tickets, const std::string &filename) {
        std::ofstream file(filename);

        if (file.is_open()) {
            for (const dto::Ticket &ticket : tickets) {
                file << ticket.getSeatNum() << "," << ticket.getTripId() << "," << ticket.getPhoneNumber() << "\n";// Uses overloaded operator<< to write Ticket objects to the file
            }
            file.close();
            std::cout << "Tickets saved successfully.\n";
        } else {
            std::cerr << "Failed to open the file.\n";
        }
    }

    std::vector<dto::Ticket> loadTickets(const std::string &filename) {
        std::vector<dto::Ticket> loadedTickets;
        std::ifstream file(filename);

        if (file.is_open()) {
            int seatNum;
            std::string tripId, phoneNumber;

            while (file >> seatNum >> std::ws && std::getline(file, tripId, ',') && std::getline(file, phoneNumber)) {
                loadedTickets.emplace_back(seatNum, tripId, phoneNumber);
            }
            file.close();
            std::cout << "Tickets loaded successfully.\n";
        } else {
            std::cerr << "Failed to open the file.\n";
        }

        return loadedTickets;
    }
}


#endif //BUSSYSTEM_REPOSITORY_H
