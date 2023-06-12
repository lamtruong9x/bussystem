//
// Created by Working on 6/11/2023.
//

#include "trip_repo.h"

bool repo::trip_repo::isExist(std::string id) {
    for (auto &trip:repo.trips) {
        if (id == trip.getId()) {
            return true;
        }
    }
    return false;
}

bool repo::trip_repo::create(dto::Trip &trip) {
    if (isExist(trip.getId())) {
        return false;
    }
    repo.trips.push_back(trip);
    return true;
}

std::vector<dto::Trip> &repo::trip_repo::getTrips() {
        return repo.trips;
}

dto::Trip * repo::trip_repo::getTripByIndex(const int index) {
    if (index >= repo.trips.size() || index < 0) {
        return nullptr;
    }
    return &repo.trips[index];
}

dto::Trip *repo::trip_repo::getTripById(const std::string id) {
    for (auto &trip:repo.trips) {
        if (id == trip.getId()) {
            return &trip;
        }
    }
    return nullptr;
}
