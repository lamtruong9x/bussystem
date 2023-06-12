#include <iostream>
#include <thread>
#include "vector"
#include "./repo/passenger_repo.h"
#include "./repo/trip_repo.h"

dto::Trip createTripView();
dto::Passenger createPassengerView();

int main() {
    auto repo = repo::repository();
    auto passenger_repo = repo::passenger_repo(repo);
    auto trip_repo = repo::trip_repo(repo);
    auto truong = dto::Passenger("0387855500", "Dam Lam Truong");
    passenger_repo.create(truong);
    auto tr = passenger_repo.getByPhone("0387855500");
    std::cout << tr->getFullName() << std::endl;

    char choose;

    do {
        std::cout << std::endl << "1. Reservations.";
        std::cout << std::endl << "2. Create new trip.";
        std::cout << std::endl << "3. Create new passenger.";
        std::cout << std::endl << "4. Save and exit program.";

        std::cout << std::endl << "You choose: ";
        std::cin >> choose;

        switch(choose) {
            case '1':
                //TODO
                break;

            case '2': {
                auto newTrip = createTripView();
                if (trip_repo.create(newTrip))
                    std::cout << "Trip created.";
                else
                    std::cout << "Trip is already exits.";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }

            case '3': {
                auto newPass = createPassengerView();
                if(passenger_repo.create(newPass))
                    std::cout << "Passenger created.";
                else
                    std::cout << "Passenger is already exits.";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }

            case '4': {
                return 0;
            }
        }
    }while(true);
}

dto::Trip createTripView() {
    int busId;
    std::string dep, des, time, date;

    std::cout << "Bus Id: ";
    std::cin >> busId;
    std::cout << "Depart from: ";
    std::cin >> dep;
    std::cout << "Destine to: ";
    std::cin >> dep;
    std::cout << "Travel date (dd/mm/yy): ";
    std::cin >> date;
    std::cout << "Travel time (hh:mm)";
    std::cin >> time;

    return dto::Trip{busId, dep, des, time, date};
}

dto::Passenger createPassengerView() {
    std::string phoneNumber, fullName, time, date;

    std::cout << "Phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Full name: ";
    std::cin >> fullName;

    return dto::Passenger(phoneNumber, fullName);
}

void reservationsView() {
    do {
        char choose;

        std::cout << std::endl << "1. List Reservations.";
        std::cout << std::endl << "2. Change reservation.";
        std::cout << std::endl << "3. Cancel reservation.";
        std::cout << std::endl << "4. Search reservation by user.";
        std::cout << std::endl << "5. Search reservation by date.";
        std::cout << std::endl << "You choose: ";
        std::cin >> choose;

        switch (choose) {
            case 1:

        }
    } while(true);
}