//
// Created by Lam Truong on 6/12/23.
//

#include "passenger_repo.h"

repo::passenger_repo::passenger_repo(repo::repository &repo) : repo(repo) {}

bool repo::passenger_repo::create(dto::Passenger &p) {
    if (isExist(p.getPhoneNumber())) {
        return false;
    }
    repo.passengers.push_back(p);
    return true;
}

bool repo::passenger_repo::isExist(std::string phoneNumber) {
    for (auto &passenger : repo.passengers) {
        if (passenger.getPhoneNumber() == phoneNumber) {
            return true;
        }
    }
    return false;
}

dto::Passenger *repo::passenger_repo::getByPhone(std::string phoneNumber) {
    auto it = std::find_if(repo.passengers.begin(), repo.passengers.end(), [&](const dto::Passenger& passenger) {
        return passenger.getPhoneNumber() == phoneNumber;
    });

    if (it != repo.passengers.end()) {
        return &(*it);
    }

    return nullptr;
}

dto::Passenger *repo::passenger_repo::getByName(std::string name) {
    auto it = std::find_if(repo.passengers.begin(), repo.passengers.end(), [&](const dto::Passenger& passenger) {
        return passenger.getFullName() == name;
    });

    if (it != repo.passengers.end()) {
        return &(*it);
    }

    return nullptr;
}

