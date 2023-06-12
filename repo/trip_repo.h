//
// Created by Working on 6/11/2023.
//

#ifndef BUSSYSTEM_TRIP_REPO_H
#define BUSSYSTEM_TRIP_REPO_H
#include "repository.h"
namespace repo {
    class trip_repo {
        repository& repo;

    public:
        explicit trip_repo(repository &repo);

        bool create(dto::Trip &trip);
        bool isExist(const std::string id);
        std::vector<dto::Trip>& getTrips();
        dto::Trip * getTripByIndex(const int index);
        dto::Trip * getTripById(const std::string id);
    };
}



#endif //BUSSYSTEM_TRIP_REPO_H
